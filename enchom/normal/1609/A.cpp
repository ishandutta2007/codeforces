#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n;
llong a[101];

int main()
{
    int i, j;
    int test, t;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        llong sum = 0;
        llong largest = 0;
        llong multiplier = 1;
        for (i=1;i<=n;i++)
        {
            scanf("%lld", &a[i]);

            while(a[i] % 2 == 0)
            {
                a[i] /= 2LL;
                multiplier *= 2LL;
            }

            sum += a[i];
            largest = max(largest, a[i]);
        }

        sum = sum - largest + largest * multiplier;

        printf("%lld\n", sum);
    }

    return 0;
}