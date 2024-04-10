#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int a,b;

Int Solve(Int k)
{
    if (k==0)
    return 0;

    Int bs=0;
    int i;
    Int ans=0;
    Int num=0;

    while( (1LL<<bs)<=k )
    {
        bs++;
    }

    bs--;

    for (i=1;i<=bs;i++)
    {
        ans+=(i-1);
    }

    for (i=0;i<bs;i++)
    {
        num=(1LL<<(bs+1))-1;
        num-=(1LL<<i);

        if (num<=k)
        ans++;
    }

    return ans;
}

int main()
{
    scanf("%lld %lld",&a,&b);

    printf("%lld\n",Solve(b)-Solve(a-1));

    return 0;
}