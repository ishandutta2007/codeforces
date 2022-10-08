#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int nums[100001];

int main()
{
    Int n,k;
    Int i;
    Int uk,thenums=0,example,current=0;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    sort(nums+1,nums+1+n);
    
    uk=1;
    while(1)
    {
        thenums=0;
        example=nums[uk];
        while (nums[uk]==example && uk<=n)
        {
            uk++;
            thenums++;
        }
        if (current+thenums*n<k)
        {
            current=current+thenums*n;
        }
        else
        {
            for (i=1;i<=n;i++)
            {
                current=current+thenums;
                if (current>=k)
                {
                    printf("%I64d %I64d\n",example,nums[i]);
                    return 0;
                }
            }
        }
    }
    return 0;
}