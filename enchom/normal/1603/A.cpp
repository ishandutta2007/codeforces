#include <iostream>
#include <stdio.h>
using namespace std;

int t, n;
int a[300111];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
        }

        bool progress = true;
        while(n > 0 && progress)
        {
            progress = false;
            for (i=n;i>=1;i--)
            {
                if (a[i] % (i + 1) != 0)
                {
                    for (j=i;j<n;j++)
                    {
                        a[j] = a[j + 1];
                    }

                    n--;
                    progress = true;

                    break;
                }
            }
        }

        if (n == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}