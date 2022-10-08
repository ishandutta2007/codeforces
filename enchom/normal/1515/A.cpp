#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n, x;
int w[1011];
bool taken[1011];
int ans[1011];

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        int sum = 0;

        scanf("%d %d", &n, &x);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &w[i]);
            taken[i] = false;
            sum += w[i];
        }

        if (sum == x)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        int cursum = 0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (taken[j])
                    continue;

                if (cursum + w[j] != x)
                {
                    ans[i] = w[j];
                    taken[j] = true;
                    cursum += w[j];

                    break;
                }
            }
        }

        for (i=1;i<=n;i++)
        {
            printf("%d", ans[i]);

            if (i != n)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}