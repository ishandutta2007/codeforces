#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n;
int nums[200111];

int ABS(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    int i,j;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        for (i=1;i<=n;i++)
        {
            scanf("%d",&nums[i]);
        }

        bool yes = false;
        for (i=1;i<n;i++)
        {
            if (ABS(nums[i] - nums[i+1]) > 1)
            {
                printf("YES\n%d %d\n",i,i+1);
                yes = true;
                break;
            }
        }

        if (!yes)
            printf("NO\n");
    }

    return 0;
}