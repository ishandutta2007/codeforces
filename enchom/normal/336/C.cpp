#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int Bits[100001][33];
Int n;
bool broken[33];
Int nums[100001];

void CutToBits(Int k,Int p)
{
    Int i;

    for (i=0;i<=32;i++)
    {
        Bits[p][i]=k%2;
        k/=2;
    }

    return;
}

int main()
{
    Int n;
    Int i,j,in;
    Int ctr,maxctr=0;
    Int bestchoice=-1;
    bool bad;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);

        CutToBits(nums[i],i);
    }

    for (i=0;i<=32;i++)
    {
        ctr=0;
        memset(broken,false,sizeof(broken));
        for (j=1;j<=n;j++)
        {
            if (Bits[j][i]!=1)
            {
                continue;
            }

            ctr++;
            for (in=i-1;in>=0;in--)
            {
                if (Bits[j][in]==0)
                {
                    broken[in]=true;
                }
            }
        }

        bad=false;

        for (j=0;j<=i-1;j++)
        {
            if (!broken[j])
            {
                bad=true;
                break;
            }
        }

        if (!bad)
        {
            maxctr=ctr;
            bestchoice=i;
        }
    }

    printf("%I64d\n",maxctr);

    if (bestchoice!=-1)
    {
        for (i=1;i<=n;i++)
        {
            if (Bits[i][bestchoice]==1)
            {
                printf("%I64d",nums[i]);
                maxctr--;
                if (maxctr!=0)
                {
                    printf(" ");
                }
            }
        }
    }
    printf("\n");

    return 0;
}