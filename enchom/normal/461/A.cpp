#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int n;
int nums[300001];
Int sum=0;

int main()
{
    int i;
    Int ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
        sum+=(Int)nums[i];
    }

    sort(nums+1,nums+1+n);

    ans=sum;

    for (i=1;i<=n;i++)
    {
        ans+=sum;

        sum-=(Int)nums[i];
    }

    ans-=nums[n];

    printf("%I64d\n",ans);

    return 0;
}