// GamblingSystem.h: interface for the CGamblingItemBag class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMBLINGSYSTEM_H__2874FC7A_D2C6_4A3B_B4F0_3D15EC489DDC__INCLUDED_)
#define AFX_GAMBLINGSYSTEM_H__2874FC7A_D2C6_4A3B_B4F0_3D15EC489DDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ItemBagEx.h"

struct _GAMBLING_RATE
{
	int iSkillRate;
	int iLuckRate;
	int iAddOptionRate;
	int iExcellentRate;
	int iSelectedRate;
	
	_GAMBLING_RATE()
	{
		iSkillRate = 0;
		iLuckRate = 0;
		iAddOptionRate = 0;
		iExcellentRate = 0;
		iSelectedRate = 0;
	}
};

class CGamblingItemBag  
{
	BOOL m_bLoad;

	_GAMBLING_RATE m_stGamblingRate[25];
	
	int m_iAddOption[4];
	int m_iGamblingItemGetRate[5];
	int m_iGamblingOptionCountRate[4];
	int m_iGamblingExOptionRate[6];
	int m_iNormalExOptionRate[6];
	int m_iBagObjectCount;
	int m_iDropRatePerItemCount[25];
	int m_iRateKindCount;
	CItemBagAttrEx BagObject[MAX_ITEMBAG];

public:
	CGamblingItemBag();
	virtual ~CGamblingItemBag();

private:
	int GetBagCount(){		return m_iBagObjectCount;	}
	BYTE GetLevel(int n);
	
	BYTE IsSkill(int n);
	BYTE IsLuck(int n);
	BYTE IsOption(int n);

public:
	void GamblingItemBagInit(char* name);
	void LoadItem(char* script_file);
	BYTE GetGamblingSystemItem(int aIndex, BYTE btMapNumber, BYTE cX, BYTE cY, BYTE btItemType);
	BYTE GamblingOptionRand(int iOptionCount);
	BYTE ExcellentOptionRand();
};

#endif // !defined(AFX_GAMBLINGSYSTEM_H__2874FC7A_D2C6_4A3B_B4F0_3D15EC489DDC__INCLUDED_)
