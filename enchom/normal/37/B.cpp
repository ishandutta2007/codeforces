#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;

struct scroll
{
    Int pow;
    Int dmg;
    Int orgind;
};

struct castedspell
{
    Int second,id;
};

Int BossHP;
Int maxhp;
Int reg;
Int n;
bool TFO[1002];
Int possiblestart=1;
scroll scrolls[1001];
vector<castedspell> spells;

bool Possible(Int p)
{
    Int a,b;

    a=p*maxhp;
    b=100*BossHP;

    return a>=b;
}

bool SortScrolls(scroll a,scroll b)
{
    return a.pow>b.pow;
}

int main()
{
    Int i;
    Int maxdmg;
    Int maxid;
    Int cursec=0;
    castedspell helper;

    memset(TFO,false,sizeof(TFO));

    scanf("%I64d %I64d %I64d",&n,&maxhp,&reg);
    BossHP=maxhp;

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&scrolls[i].pow,&scrolls[i].dmg);

        scrolls[i].orgind=i;
    }

    sort(scrolls+1,scrolls+1+n,SortScrolls);

    while(BossHP>0)
    {
        BossHP=BossHP+reg;

        if (BossHP>maxhp)
        BossHP=maxhp;

        if (BossHP<=0)
        break;

        while(TFO[possiblestart] && possiblestart<=n)
        {
            possiblestart++;
        }

        maxdmg=0;
        maxid=-1;
        for (i=possiblestart;i<=n;i++)
        {
            if (TFO[i])
            continue;

            if (Possible(scrolls[i].pow))
            {
                if (scrolls[i].dmg>maxdmg)
                {
                    maxdmg=scrolls[i].dmg;
                    maxid=i;
                }
            }
            else
            {
                break;
            }
        }

        if (maxid!=-1)
        {
            TFO[maxid]=true;
            reg-=maxdmg;

            helper.second=cursec;
            helper.id=scrolls[maxid].orgind;

            spells.push_back(helper);
        }
        else
        {
            if (reg>=0)
            {
                printf("NO\n");
                return 0;
            }
        }

        cursec++;
    }

    printf("YES\n");
    printf("%I64d %I64d\n",cursec,(Int)spells.size());

    for (i=0;i<spells.size();i++)
    {
        printf("%I64d %I64d\n",spells[i].second,spells[i].id);
    }

    return 0;
}