#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long llong;

int t;
int n, k;
llong nums[300111];


int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &k);

        for (i=1;i<=k;i++)
        {
            scanf("%lld", &nums[i]);
        }

        if (k == 1)
        {
            printf("Yes\n");
            continue;
        }

        bool bad = false;
        llong lastNum = nums[2] - nums[1];
        for (i=3;i<=k;i++)
        {
            llong curNum = nums[i] - nums[i - 1];

            if (curNum < lastNum)
            {
                bad = true;
                break;
            }

            lastNum = curNum;
        }

        if (bad)
        {
            printf("No\n");
            continue;
        }

        llong firstNum = nums[2] - nums[1];
        llong maxSum = (llong)(n - k + 1) * firstNum;

        if (maxSum < nums[1])
        {
            printf("No\n");
            continue;
        }

        printf("Yes\n");
    }

    return 0;
}