InsideOfTruck_MapScripts:: @ 823BEDA
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad: @ 823BEE5
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, 0
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, 0
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, 0
	end

InsideOfTruck_OnResume: @ 823BF01
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags:: @ 823BF04
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsMale
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale:: @ 823BF20
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale:: @ 823BF46
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	end

InsideOfTruck_EventScript_Debug::
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	giveitem ITEM_HM01, 1
	giveitem ITEM_HM02, 1
	giveitem ITEM_HM03, 1
	giveitem ITEM_HM04, 1
	giveitem ITEM_HM05, 1
	giveitem ITEM_HM06, 1
	giveitem ITEM_HM07, 1
	givemon SPECIES_MEW, 100
return

InsideOfTruck_EventScript_AskNuzlocke::
	goto_if_set FLAG_NUZLOCKE_MODE, InsideOfTruck_EventScript_NuzlockeEnabled
	msgbox InsideOfTruck_Text_WantToEnableNuzlockeMode, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_ExplainNuzlocke
	releaseall
	end

InsideOfTruck_EventScript_ExplainNuzlocke::
	msgbox InsideOfTruck_Text_ExplainNuzlocke, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq InsideOfTruck_EventScript_AbortNuzlocke
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	msgbox InsideOfTruck_Text_EnableAdditionalClauses, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq InsideOfTruck_EventScript_EnableAdditionalClauses
	special EnableNuzlockeMode
	playse SE_SAVE
	goto InsideOfTruck_EventScript_NuzlockeEnabled
	end

InsideOfTruck_EventScript_EnableAdditionalClauses::
	msgbox InsideOfTruck_Text_EnableSpeciesClause, MSGBOX_YESNO
	copyvar VAR_0x8004, VAR_RESULT
	msgbox InsideOfTruck_Text_EnableShinyClause, MSGBOX_YESNO
	copyvar VAR_0x8005, VAR_RESULT
	msgbox InsideOfTruck_Text_ConfigurationComplete
	return

InsideOfTruck_EventScript_NuzlockeEnabled::
	msgbox InsideOfTruck_Text_NuzlockeEnabled
	releaseall
	end

InsideOfTruck_EventScript_AbortNuzlocke::
	releaseall
	end

InsideOfTruck_EventScript_MovingBox:: @ 823BF6C
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_WantToEnableNuzlockeMode:
	.string "Do you want to enable NUZLOCKE mode?$"

InsideOfTruck_Text_ExplainNuzlocke:
	.string "You won't be able to change your\n"
	.string "current difficulty setting once\l"
	.string "NUZLOCKE mode has been enabled.\p"
	.string "Are you okay with that?$"

InsideOfTruck_Text_EnableAdditionalClauses:
	.string "Do you want to adjust the\n"
	.string "NUZLOCKE rules?$"

InsideOfTruck_Text_EnableSpeciesClause:
	.string "Enable the SPECIES CLAUSE?$"

InsideOfTruck_Text_EnableShinyClause:
	.string "Enable the SHINY CLAUSE?$"

InsideOfTruck_Text_ConfigurationComplete:
	.string "Configuration complete!$"

InsideOfTruck_Text_NuzlockeEnabled:
	.string "NUZLOCKE mode has been enabled!\p"
	.string "Good luck on your journey!$"
