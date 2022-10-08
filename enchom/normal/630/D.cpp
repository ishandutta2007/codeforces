#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

void EnchomSolve()
{
    Int n;
    Int ans;

    scanf("%lld",&n);

    ans=3LL*n*(n+1LL)+1LL;

    printf("%lld\n",ans);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}