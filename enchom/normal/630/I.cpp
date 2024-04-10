#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int P(Int k,int p)
{
    int i;
    Int ans=1;

    for (i=1;i<=p;i++)
    {
        ans*=k;
    }

    return ans;
}

void EnchomSolve()
{
    Int n,total;
    Int ans;

    scanf("%lld",&n);
    total=2*n-2;

    ans=2LL*4LL*3LL*P(4,(total-n-1));
    ans+=(n-3LL)*4LL*9LL*P(4,(total-n-2));

    printf("%lld\n",ans);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}