#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n;
llong c[2011];

int main()
{
    int i, j;

    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld", &c[i]);
    }

    llong ans = 0;

    for (i=1;i<=n;i+=2)
    {
        llong midSum = 0;
        llong lowestMid = 0;
        llong leftAv = c[i];

        for (j=i+1;j<=n;j+=2)
        {
            if (lowestMid + leftAv < 0)
                break;

            llong minLeftMid = (-lowestMid) + midSum;
            llong needRight = max(0LL, minLeftMid);

            if (c[j] >= needRight)
            {
                ans += min(leftAv + lowestMid, c[j] - needRight) + 1;

                if (lowestMid == 0 && needRight == 0)
                    ans--;
            }

            midSum -= c[j];
            lowestMid = min(lowestMid, midSum);

            midSum += c[j+1];
        }
    }

    printf("%lld\n", ans);

    return 0;
}