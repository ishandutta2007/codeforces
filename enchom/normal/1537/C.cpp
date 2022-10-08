#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int h[200111];
int t;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &h[i]);
        }

        sort(h+1, h+1+n);

        int mindif = h[2] - h[1];
        int minind = 1;

        for (i=2;i<n;i++)
        {
            if (h[i+1] - h[i] < mindif)
            {
                mindif = h[i+1] - h[i];
                minind = i;
            }
        }

        if (h[n] - h[1] != mindif)
        {
            printf("%d", h[minind+1]);
            for (i=minind+2;i<=n;i++)
            {
                printf(" %d", h[i]);
            }
            for (i=1;i<=minind;i++)
            {
                printf(" %d", h[i]);
            }
            printf("\n");
        }
        else
        {
            printf("%d", h[1]);
            for (i=2;i<=n;i++)
            {
                printf(" %d", h[i]);
            }
            printf("\n");
        }
    }

    return 0;
}