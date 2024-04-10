#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

const Int MOD=1000000009;
Int n,m,k;

Int FastPow(Int k)
{
    if (k==0)
    return 1;

    Int POWER=FastPow(k/2);

    if (k%2==1)
    {
        return (POWER*POWER*2)%MOD;
    }
    else
    {
        return (POWER*POWER)%MOD;
    }
}

int main()
{
    Int wrongs;
    Int groups;
    Int bonuspts=0;
    Int pts;
    Int x;

    scanf("%I64d %I64d %I64d",&n,&m,&k);

    wrongs=n-m;
    groups=n/k;

    if (wrongs>=groups)
    {
        printf("%I64d\n",m);
        return 0;
    }

    bonuspts=(k-1)*wrongs;
    n=n-k*wrongs;

    x=n/k;

    pts=FastPow(x+1)-2;
    if (pts<0)
    {
        pts+=MOD;
    }

    pts=pts*k;
    pts%=MOD;

    pts=pts+(n-x*k)+bonuspts;

    printf("%I64d\n",pts%MOD);

    return 0;
}