#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct formation
{
    Int likable,difference;
};

formation teamformations[1000001];
Int tfL=0;
bool Likes[8][8];
Int inteam[8];
Int Mephisto,Diablo,Baal;

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

Int MAX(Int a,Int b)
{
    if (a<b)
    return b;
    else
    return a;
}

void Generator(Int pos)
{
    Int i,j;
    Int ctr[4]={0,0,0,0};
    Int xp1,xp2,xp3;
    Int dif,like=0;
    if (pos==8)
    {
        for (i=1;i<=7;i++)
        {
            ctr[ inteam[i] ]++;
        }
        if (ctr[1]==0 || ctr[2]==0 || ctr[3]==0)
        return;
        
        xp1=Mephisto/ctr[1];
        xp2=Diablo/ctr[2];
        xp3=Baal/ctr[3];
        
        dif=MAX( ABS(xp1-xp2) , MAX( ABS(xp2-xp3) , ABS(xp3-xp1) ) );
        for (i=1;i<=7;i++)
        {
            for (j=1;j<=7;j++)
            {
                if (inteam[i]==inteam[j])
                {
                    if (Likes[i][j])
                    {
                        like++;
                    }
                }
            }
        }
        
        tfL++;
        teamformations[tfL].likable=like;
        teamformations[tfL].difference=dif;
        
        return;
    }
    inteam[pos]=1;
    Generator(pos+1);
    inteam[pos]=2;
    Generator(pos+1);
    inteam[pos]=3;
    Generator(pos+1);
}

Int GetNum(string s)
{
    switch (s[0])
    {
        case 'A':
        return 1;
        break;
        
        case 'C':
        if (s[1]=='h')
        return 2;
        else
        return 3;
        break;
        
        case 'T':
        return 4;
        break;
        
        case 'D':
        return 5;
        break;
        
        case 'S':
        return 6;
        break;
        
        case 'H':
        return 7;
    }
}

int main()
{
    Int n;
    Int a,b;
    string str;
    Int i,j;
    Int minndif=999999999999;
    Int maxlike=0;
    
    scanf("%I64d",&n);
    
    for (i=0;i<=7;i++)
    {
        for (j=0;j<=7;j++)
        {
            Likes[i][j]=false;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        cin>>str;
        a=GetNum(str);
        cin>>str;
        cin>>str;
        b=GetNum(str);
        
        Likes[a][b]=true;
    }
    
    scanf("%I64d %I64d %I64d",&Mephisto,&Diablo,&Baal);
    
    Generator(1);
    
    for (i=1;i<=tfL;i++)
    {
        if (teamformations[i].difference<minndif)
        minndif=teamformations[i].difference;
    }
    
    for (i=1;i<=tfL;i++)
    {
        if (teamformations[i].difference==minndif)
        {
            if (teamformations[i].likable>maxlike)
            maxlike=teamformations[i].likable;
;        }
    }
    printf("%I64d %I64d\n",minndif,maxlike);
    return 0;
}