#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t;
int n, c;

int hasNum[1000111];
int preSum[1000111];

bool exists(int L, int R)
{
    if (R > c)
        return preSum[c] - preSum[L - 1] > 0;

    return preSum[R] - preSum[L - 1] > 0;
}

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        bool isIntegral = true;

        scanf("%d %d", &n, &c);

        for (i=1;i<=c;i++)
        {
            hasNum[i] = 0;
        }

        for (i=1;i<=n;i++)
        {
            int a;
            scanf("%d", &a);
            hasNum[a]++;
        }

        for (i=1;i<=c;i++)
        {
            preSum[i] = preSum[i-1] + hasNum[i];
        }

        for (i=1;i<=c;i++)
        {
            if (hasNum[i] > 0)
            {
                int L = i;
                int R = 2 * i - 1;
                int res = 1;

                while(L <= c)
                {
                    if (exists(L, R))
                    {
                        if (hasNum[res] == 0)
                        {
                            isIntegral = false;
                            break;
                        }
                    }

                    L += i;
                    R += i;
                    res++;
                }

                if (!isIntegral)
                    break;
            }
        }

        if (isIntegral)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}