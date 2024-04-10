#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int components[1001];
Int cL=0;
bool TFO[1001];
Int thenext[1001],behind[1001];
bool sawx;
Int n,x;
bool sums[1001];

Int Search(Int ver)
{
    if (ver==0)
    {
        return 0;
    }
    if (ver==x)
    {
        sawx=true;
    }

    TFO[ver]=true;

    return Search(thenext[ver])+1;
}

int main()
{
    Int i,j;
    Int placeforx;

    for (i=0;i<=1000;i++)
    {
        behind[i]=0;
        TFO[i]=false;
        sums[i]=false;
    }

    scanf("%I64d %I64d",&n,&x);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&thenext[i]);
        behind[ thenext[i] ]=i;
    }

    for (i=1;i<=n;i++)
    {
        if (behind[i]==0 && !TFO[i])
        {
            cL++;
            components[cL]=Search(i);

            if (sawx)
            {
                cL--;
                sawx=false;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        TFO[i]=false;
    }

    placeforx=Search(x);

    sums[0]=true;

    for (i=1;i<=cL;i++)
    {
        for (j=n;j>=0;j--)
        {
            if (sums[j])
            {
                sums[j+components[i]]=true;
            }
        }
    }

    for (i=0;i<=n;i++)
    {
        if (sums[i])
        {
            printf("%I64d\n",i+placeforx);
        }
    }

    return 0;
}