#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

llong t, x, y;

int main()
{
    int test;
    int i, j;

    scanf("%lld", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%lld %lld", &x, &y);

        if (x > y)
        {
            printf("%lld\n", 1000000001LL * x + y);
        }
        else if (x == y)
        {
            printf("%lld\n", x);
        }
        else
        {
            llong clst = y / x;
            llong closest = clst * x;

            llong xv = 0;
            llong yv = y % closest;

            printf("%lld\n", closest + (yv - xv) / 2LL);
        }
    }

    return 0;
}