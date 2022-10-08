#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int nums[101];
int n,k;

int main()
{
    int i;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    sort(nums+1,nums+1+n);
    reverse(nums+1,nums+1+n);

    printf("%d\n",nums[k]);

    return 0;
}