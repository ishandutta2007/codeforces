#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

const Int MOD=1000000007;

Int FastPower(Int k,Int p)
{
    if (p==0)
    return 1;

    Int POWER=FastPower(k,p/2);

    if (p%2==0)
    return (POWER*POWER)%MOD;
    else
    return (((POWER*POWER)%MOD)*k)%MOD;
}

Int ModDIV(Int num,Int d)
{
    Int mult=FastPower(d,MOD-2);

    return (num*mult)%MOD;
}

Int facts[2000001] ; /// facts == factoriels, not facts :D
Int F[1011];
Int S=0;
Int a[1011];

Int C(Int n,Int k)
{
    Int div=(facts[k]*facts[n-k])%MOD;
    Int res=ModDIV(facts[n],div);

    return res;
}

int main()
{
    Int i;
    Int n;

    facts[0]=1;
    for (i=1;i<=2000000;i++)
    {
        facts[i]=(facts[i-1]*i)%MOD;
    }

    scanf("%lld",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]--;
    }

    S=a[1]+1;
    F[1]=1;

    for (i=2;i<=n;i++)
    {
        F[i]=(C(a[i]+S,a[i])*F[i-1])%MOD;
        S=S+a[i]+1;
    }

    printf("%lld\n",F[n]);

    return 0;
}