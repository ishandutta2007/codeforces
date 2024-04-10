#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

void EnchomSolve()
{
    Int n;

    scanf("%lld",&n);

    printf("%lld\n",((n%2LL)^1LL)+1);
    return;
}

int main()
{
    EnchomSolve();
    return 0;
}