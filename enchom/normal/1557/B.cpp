#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t, n, k;
pair<int, int> a[100111];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &k);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }

        sort(a + 1, a + 1 + n);

        int chunks = 1;

        for (i=2;i<=n;i++)
        {
            if (a[i].second != a[i-1].second + 1)
                chunks++;
        }

        if (k >= chunks)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}