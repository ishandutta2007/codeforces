#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n;
int nums[100111];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        int sum = 0;
        for (i=1;i<=n;i++)
        {
            scanf("%d", &nums[i]);
            sum += nums[i];
        }

        if (sum < n)
        {
            printf("1\n");
        }
        else if (sum == n)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", sum - n);
        }
    }

    return 0;
}