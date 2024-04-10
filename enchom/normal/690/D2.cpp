#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n,c;
Int fact[1000111];
const Int MOD=1000003LL;

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1LL;

    Int POW=FastPow(k,p/2);
    POW=(POW*POW)%MOD;

    if (p%2==1)
    POW=(POW*k)%MOD;

    return POW;
}

Int C(Int n,Int k)
{
    Int tp=fact[n];
    Int bt=(fact[k]*fact[n-k])%MOD;

    return (tp*FastPow(bt,MOD-2))%MOD;
}

int main()
{
    int i;
    Int ans=0;

    fact[0]=1LL;
    for (i=1;i<=1000000;i++)
    {
        fact[i]=fact[i-1]*(Int)i;
        fact[i]%=MOD;
    }

    scanf("%lld %lld",&n,&c);

    for (i=1;i<=n;i++)
    {
        ans+=C(i+c-1,i);
        ans%=MOD;
    }

    printf("%lld\n",ans);

    return 0;
}