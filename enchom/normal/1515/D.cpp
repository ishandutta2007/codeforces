#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n, l, r;
int lefts[500111];
int rights[500111];
int socks[500111];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        int ans = 0;

        scanf("%d %d %d", &n, &l, &r);

        int disbalance = l - r;

        for (i=1;i<=n;i++)
        {
            lefts[i] = 0;
            rights[i] = 0;
        }

        for (i=1;i<=n;i++)
        {
            scanf("%d", &socks[i]);

            if (i <= l)
                lefts[ socks[i] ]++;
            else
                rights[ socks[i] ]++;
        }

        for (i=1;i<=n;i++)
        {
            int mv = min(lefts[i], rights[i]);

            lefts[i] -= mv;
            rights[i] -= mv;
        }

        for (i=1;i<=n;i++)
        {
            while(disbalance > 0 && lefts[i] >= 2)
            {
                disbalance -= 2;
                lefts[i] -= 2;
                ans++;
            }

            while(disbalance < 0 && rights[i] >= 2)
            {
                disbalance += 2;
                rights[i] -= 2;
                ans++;
            }
        }

        for (i=1;i<=n;i++)
        {
            if (disbalance > 0 && lefts[i] > 0)
            {
                lefts[i]--;
                rights[i]++;
                disbalance -= 2;
                ans++;
            }

            if (disbalance < 0 && rights[i] > 0)
            {
                rights[i]--;
                lefts[i]++;
                disbalance += 2;
                ans++;
            }
        }

        int remaining = 0;
        for (i=1;i<=n;i++)
        {
            remaining += lefts[i];
        }

        ans += remaining;

        printf("%d\n", ans);
    }

    return 0;
}