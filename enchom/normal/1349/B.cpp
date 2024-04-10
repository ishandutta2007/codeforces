#include <iostream>
#include <stdio.h>
using namespace std;

int t, test;
int n, k;
int nums[200111];

int main()
{
    int i,j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &k);

        bool hasBlack = false;
        for (i=1;i<=n;i++)
        {
            scanf("%d", &nums[i]);

            if (nums[i] == k)
                hasBlack = true;
        }

        if (!hasBlack)
        {
            printf("no\n");
            continue;
        }

        if (n == 1)
        {
            printf("yes\n");
            continue;
        }

        ///Twosome
        bool WIN = false;
        for (i=1;i<n;i++)
        {
            int a = nums[i], b = nums[i+1];
            int med = min(a, b);

            if (med >= k)
                WIN = true;
        }

        if (WIN)
        {
            printf("yes\n");
            continue;
        }

        ///Threesome
        for (i=1;i<n-1;i++)
        {
            int a = nums[i], b = nums[i+1], c = nums[i+2];

            if (a > b)
                swap(a, b);
            if (b > c)
                swap(b, c);
            if (a > b)
                swap(a, b);

            int med = b;

            if (med >= k)
                WIN = true;
        }

        if (WIN)
        {
            printf("yes\n");
            continue;
        }

        printf("no\n");
    }

    return 0;
}