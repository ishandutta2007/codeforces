#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
typedef long long Int;
typedef unsigned long long UInt;

UInt B1=127;
Int B2=197;
Int MOD=1000000009LL;

int n,m;
char inp[1011];
int L;

set< pair<UInt,Int> > PB;

int PoB=0,Both=0,EB=0;

int main()
{
    int i,j;
    pair<UInt,Int> H;
    int mv=0;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",inp+1);
        L=strlen(inp+1);

        H=make_pair(0,0);

        for (j=1;j<=L;j++)
        {
            H.first*=B1;
            H.first+=(UInt)inp[j];

            H.second*=B2;
            H.second+=(Int)inp[j];
            H.second%=MOD;
        }

        PB.insert(H);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%s",inp+1);
        L=strlen(inp+1);

        H=make_pair(0,0);

        for (j=1;j<=L;j++)
        {
            H.first*=B1;
            H.first+=(UInt)inp[j];

            H.second*=B2;
            H.second+=(Int)inp[j];
            H.second%=MOD;
        }

        if (PB.find(H)!=PB.end())
        {
            Both++;
            PB.erase(H);
        }
        else
        {
            EB++;
        }
    }

    PoB=PB.size();

    while(1)
    {
        if (Both>0)
        {
            Both--;
            mv^=1;
        }
        else
        {
            if (mv==0)
            {
                if (PoB>0)
                PoB--;
                else
                break;
            }
            else
            {
                if (EB>0)
                EB--;
                else
                break;
            }

            mv^=1;
        }
    }

    if (mv==0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }

    return 0;
}