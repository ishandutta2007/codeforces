#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

llong n;

int main()
{
    int ans = 0;
    llong maxnum = 1;
    llong sum = 0;

    scanf("%lld",&n);

    while(sum < n)
    {
        sum += maxnum;
        maxnum *= 2;
        ans++;
    }

    printf("%d\n",ans);

    return 0;
}