#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int nums[300001];

Int ABS(Int a)
{
    if (a<0)
    return a*(-1);
    else
    return a;
}

int main()
{
    Int n;
    Int i;
    Int sum=0;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    sort(nums+1,nums+1+n);

    for (i=n;i>=1;i--)
    {
        sum=sum+ABS(nums[i]-i);
    }

    printf("%I64d\n",sum);

    return 0;
}