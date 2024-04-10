#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int total;
Int lights[1001];
Int gaps[1001];
Int gL=0;
Int ways=0;
Int delitels[1001];
const Int MOD=1000000007;

bool SortBack(Int a,Int b)
{
    return (a>b);
}

Int FastPow(Int k,Int p)
{
    Int POWER;

    if (p<1)
    return 1;

    if (p%2==0)
    {
        POWER=FastPow(k,p/2);
        return (POWER*POWER)%MOD;
    }
    else
    {
        POWER=FastPow(k,(p-1)/2);
        return (POWER*POWER*k)%MOD;
    }
}

void CutInDelitels(Int k)
{
    Int i;

    for (i=2;i*i<=k;i++)
    {
        while(k%i==0)
        {
            delitels[i]++;
            k=k/i;
        }
    }
    if (k>1)
    {
        delitels[k]++;
    }

    return;
}

void RemoveFromTotal(Int k)
{
    Int i;

    for (i=2;i*i<=k;i++)
    {
        while(k%i==0)
        {
            delitels[i]--;
            k=k/i;
        }
    }
    if (k>1)
    {
        delitels[k]--;
    }

    return;
}

int main()
{
    Int n,m;
    Int i,j;
    Int current;
    Int nod;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&lights[i]);
    }

    sort(lights+1,lights+1+m);

    total=lights[1]-1;
    total=total + (n-lights[m]);
    gL++;
    gaps[gL]=lights[1]-1;
    gL++;
    gaps[gL]=n-lights[m];

    for (i=1;i<m;i++)
    {
        total=total+(lights[i+1]-lights[i]-1);

        gL++;
        gaps[gL]=lights[i+1]-lights[i]-1;
    }

    sort(gaps+1,gaps+1+gL,SortBack);

    while(gL>0 && gaps[gL]<1)
    {
        gL--;
    }

    for (i=0;i<=1000;i++)
    {
        delitels[i]=0;
    }


    ways=1;
    for (i=2;i<=total;i++)
    {
        CutInDelitels(i);
    }

    for (i=1;i<=gL;i++)
    {
        for (j=2;j<=gaps[i];j++)
        {
            RemoveFromTotal(j);
        }
    }



    for (i=2;i<=1000;i++)
    {
        for (j=1;j<=delitels[i];j++)
        {
            ways=(ways*i)%MOD;
        }
    }

    for (i=1;i<m;i++)
    {
        ways=( ways*FastPow(2, lights[i+1]-lights[i]-2 ) )%MOD;
    }

    printf("%I64d\n",ways);

    return 0;
}