#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int t, n;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        llong sum = 0;
        llong a;
        llong maxv = -1000000001;

        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%lld", &a);

            maxv = max(maxv, a);
            sum += a;
        }

        long double p1 = maxv;
        long double p2 = (long double)(sum - maxv) / (long double)(n - 1);

        printf("%.6f\n", (double)(p1 + p2));
    }

    return 0;
}