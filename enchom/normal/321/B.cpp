#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct card
{
    bool atk;
    Int strength;
};

card cards[101];
Int attackers[101];
Int n,m;
char inp[10];
bool TFO[101];

bool SortC(card a,card b)
{
    return a.strength<b.strength;
}

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    Int i;
    Int uk1,uk2;
    Int dmg1=0,dmg2=0;

    memset(TFO,false,sizeof(TFO));

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",inp);

        if (inp[0]=='A')
        {
            cards[i].atk=true;
        }
        else
        {
            cards[i].atk=false;
        }

        scanf("%I64d",&cards[i].strength);

        if (!cards[i].atk)
        cards[i].strength++;
    }

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&attackers[i]);
    }

    sort(attackers+1,attackers+1+m);
    sort(cards+1,cards+1+n,SortC);

    uk1=1;
    uk2=1;

    while(uk1<=n && uk2<=m)
    {
        if (cards[uk1].atk)
        {
            uk1++;
            continue;
        }

        if (attackers[uk2]>=cards[uk1].strength)
        {
            TFO[uk2]=true;
            uk1++;
            uk2++;
        }
        else
        {
            uk2++;
        }
    }

    while(cards[uk1].atk)
    {
        uk1++;
    }

    if (uk1>n)
    {
        uk1=1;
        uk2=1;

        while(uk1<=n && uk2<=m)
        {
            if (TFO[uk2])
            {
                uk2++;
                continue;
            }
            if (!cards[uk1].atk)
            {
                uk1++;
                continue;
            }

            if (attackers[uk2]>=cards[uk1].strength)
            {
                dmg1=dmg1+(attackers[uk2]-cards[uk1].strength);
                TFO[uk2]=true;
                uk1++;
                uk2++;
            }
            else
            {
                uk2++;
            }
        }

        if (uk1>n)
        {
            for (i=1;i<=m;i++)
            {
                if (!TFO[i])
                {
                    dmg1+=attackers[i];
                }
            }
        }
    }

    uk1=1;
    uk2=m;

    while(uk1<=n && uk2>=1)
    {
        if (!cards[uk1].atk)
        {
            uk1++;
            continue;
        }

        if (attackers[uk2]>=cards[uk1].strength)
        {
            dmg2=dmg2+(attackers[uk2]-cards[uk1].strength);
            uk1++;
            uk2--;
        }
        else
        {
            break;
        }
    }

    printf("%I64d\n",MAX(dmg1,dmg2));

    return 0;
}