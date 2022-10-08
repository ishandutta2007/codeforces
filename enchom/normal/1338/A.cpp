#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int t, test;
int n;
llong nums[100111];
int k;

bool good()
{
    int i;
    llong limit = 0;

    for (i=0;i<k;i++)
    {
        limit += (1LL << (llong)i);
    }

    llong nextNum = nums[n] + limit;
    for (i=n-1;i>=1;i--)
    {
        if (nums[i] > nextNum)
            return false;

        nextNum = min(nums[i] + limit, nextNum);
    }

    return true;
}

int main()
{
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        for (i=1;i<=n;i++)
        {
            scanf("%lld",&nums[i]);
        }

        k = 0;
        while(!good())
        {
            k++;
        }

        printf("%d\n",k);
    }

    return 0;
}