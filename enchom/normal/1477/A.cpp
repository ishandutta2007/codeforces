#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long llong;

llong a[200111];

llong gcd(llong a, llong b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    llong r;

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int t, test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        int n;
        llong k;

        scanf("%d %lld", &n, &k);

        for (int i=1;i<=n;i++)
        {
            scanf("%lld", &a[i]);
        }

        sort(a+1,a+1+n);

        llong nod = a[2] - a[1];
        for (int i=1;i<n;i++)
        {
            nod = gcd(nod, a[i+1] - a[i]);
        }

        if (nod == 0)
        {
            if (a[1] == k)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }

            continue;
        }

        bool good = false;
        for (int i=1;i<=n;i++)
        {
            llong diff = abs(k - a[i]);

            if (diff % nod == 0)
            {
                good = true;
                break;
            }
        }

        if (good)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}