#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

const Int MOD=1000000007;

Int facts[200001];

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1;

    Int POWER=FastPow(k,p/2);

    if (p%2==0)
    return (POWER*POWER)%MOD;
    else
    return (((POWER*POWER)%MOD)*k)%MOD;
}

Int MultiplicativeInverse(Int top,Int bot)
{
    Int res=( top*FastPow(bot,MOD-2) )%MOD;

    return res;
}

Int Comb(Int zero,Int one)
{
    Int bottom=(facts[zero]*facts[one])%MOD;
    Int ans=MultiplicativeInverse(facts[zero+one],bottom);

    return ans;
}

int main()
{
    Int n,m,g;
    Int L;
    Int i;
    Int totalways=0;

    facts[0]=1;

    for (i=1;i<=200000;i++)
    {
        facts[i]=(facts[i-1]*i)%MOD;
    }

    scanf("%I64d %I64d %I64d",&m,&n,&g);

    if (n==0)
    {
        if (m%2==0)
        {
            if (g==1)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            if (g==1)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }

        return 0;
    }

    L=n+m;

    for (i=g+1;i<L;i+=2)
    {
        if (i-1>m) ///Don't have enough zeroes
        break;

        if (L-i+1<n) ///Have too much ones
        break;

        totalways+=Comb(m-(i-1),n-1);

        if (totalways>=MOD)
        totalways-=MOD;
    }

    if (n==1)
    {
        if (m%2==0 && g==1)
        {
            totalways++;
        }
        if (m%2==1 && g==0)
        {
            totalways++;
        }
    }

    printf("%I64d\n",totalways%MOD);

    return 0;
}