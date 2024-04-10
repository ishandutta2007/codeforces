#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

bool SortEm(Int a,Int b)
{
    return (a>b);
}

int main()
{
    Int n,k;
    Int nums[51];
    Int i,j;
    Int end;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    sort(nums+1,nums+1+n,SortEm);
    
    if (nums[k]>0)
    {
        end=k;
        for (i=k+1;i<=n;i++)
        {
            if (nums[i]!=nums[k])
            break;
            else
            end++;
        }
    }
    else
    {
        end=0;
        for (i=k-1;i>=1;i--)
        {
            if (nums[i]>0)
            {
                end=i;
                break;
            }
        }
    }
    
    printf("%I64d\n",end);
    return 0;
}