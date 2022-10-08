#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int ans[200001];
Int aL=0;
Int nums[200001];
Int n;

int main()
{
    Int i;
    Int sum=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
        sum=sum+nums[i];
    }
    for (i=1;i<=n;i++)
    {
        if ( (sum-nums[i])/(n-1)==nums[i] && (sum-nums[i])%(n-1)==0 )
        {
            aL++;
            ans[aL]=i;
        }
    }
    printf("%I64d\n",aL);
    for (i=1;i<=aL;i++)
    {
        printf("%I64d",ans[i]);
        if (i==aL)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}