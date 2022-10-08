#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;

Int D(Int k)
{
    return n/k;
}

void EnchomSolve()
{
    Int ans;

    scanf("%lld",&n);

    ans=n;
    ans-=D(2)+D(3)+D(5)+D(7);
    ans+=D(2*3)+D(2*5)+D(2*7)+D(3*5)+D(3*7)+D(5*7);
    ans-=D(2*3*5)+D(2*3*7)+D(3*5*7)+D(2*5*7);
    ans+=D(2*3*5*7);

    printf("%lld\n",ans);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}