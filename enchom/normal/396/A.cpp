#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;
#define MOD 1000000007

Int n;
Int divlist[100001];
Int L=0;
Int Fact[100001];

///stars = N+K and thus forming N+K-1 holes, therefore C(N+K-1,N-1)

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1;

    Int POW=FastPow(k,p/2);

    if (p%2==0)
    return (POW*POW)%MOD;
    else
    return (( (POW*POW)%MOD )*k)%MOD;
}

Int C(Int n,Int k)
{
    Int top,bottom;
    Int div;

    top=Fact[n];

    bottom=Fact[n-k]*Fact[k];
    bottom%=MOD;

    div=FastPow(bottom,MOD-2);

    return (top*div)%MOD;
}

Int Solve(Int k)
{
    return C(n+k-1,n-1);
}

int main()
{
    Int i,j;
    Int a;
    Int b;
    Int ctr=0;
    Int Ans=1;
    Int mult;

    Fact[0]=1;
    for (i=1;i<=100000;i++)
    {
        Fact[i]=Fact[i-1]*i;
        Fact[i]%=MOD;
    }

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);

        b=a;

        for (j=2;j*j<=a;j++)
        {
            while (b%j==0)
            {
                L++;
                divlist[L]=j;
                b/=j;
            }
        }

        if (b>1)
        {
            L++;
            divlist[L]=b;
        }
    }

    sort(divlist+1,divlist+1+L);

    ctr=1;
    for (i=2;i<=L;i++)
    {
        if (divlist[i]==divlist[i-1])
        {
            ctr++;
        }
        else
        {
            mult=Solve(ctr);
            Ans*=mult;
            Ans%=MOD;

            ctr=1;
        }
    }

    if (L>0)
    {
        mult=Solve(ctr);
        Ans*=mult;
        Ans%=MOD;
    }

    printf("%I64d\n",Ans);

    return 0;
}