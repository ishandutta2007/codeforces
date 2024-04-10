#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int nums[101];

bool SortEm(Int a,Int b)
{
    return (a>b);
}

int main()
{
    Int n;
    Int totalsum=0,currsum=0;
    Int coins=0;
    Int i;
    
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
        totalsum=totalsum+nums[i];
    }
    
    sort(nums+1,nums+1+n,SortEm);
    
    for (i=1;i<=n;i++)
    {
        currsum=currsum+nums[i];
        coins++;
        if (currsum>totalsum-currsum)
        {
            break;
        }
    }
    printf("%I64d\n",coins);
    return 0;
}