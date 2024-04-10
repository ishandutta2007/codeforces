#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int nums[100111];

int main()
{
    int i;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);

        while(nums[i]%2==0)
        nums[i]/=2;

        while(nums[i]%3==0)
        nums[i]/=3;
    }

    for (i=1;i<n;i++)
    {
        if (nums[i]!=nums[i+1])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}