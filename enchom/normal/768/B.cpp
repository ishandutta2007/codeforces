#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int n,l,r;
int bits[111];
int L=0;
int ans=0;

void Solve(Int L,Int R,int b)
{
    if (L>r || R<l)
    return;
    if (b==0 || L>R)
    return;

    Int mid=(L+R)/2LL;

    if (mid>=l && mid<=r && bits[b]==1)
    {
        ans++;
    }

    Solve(L,mid-1,b-1);
    Solve(mid+1,R,b-1);

    return;
}

int main()
{
    scanf("%lld %lld %lld",&n,&l,&r);

    if (n==0)
    {
        printf("0\n");
        return 0;
    }
    else if (n==1)
    {
        printf("1\n");
        return 0;
    }

    while(n>0)
    {
        L++;
        bits[L]=n%2LL;
        n/=2LL;
    }

    reverse(bits+1,bits+1+L);

    Solve(1LL,(1LL<<L)-1LL,L);

    printf("%d\n",ans);

    return 0;
}