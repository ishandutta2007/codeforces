#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char inp[100001];
Int nums[100001];
Int prefixsums[100001];

int main()
{
    Int L;
    Int m;
    Int i;
    Int lefty,righty;
    Int ans;

    scanf("%s",inp);

    L=strlen(inp);

    for (i=0;i<L-1;i++)
    {
        if (inp[i]==inp[i+1])
        {
            nums[i]=1;
        }
        else
        {
            nums[i]=0;
        }

        if (i>0)
        {
            prefixsums[i]=prefixsums[i-1]+nums[i];
        }
        else
        {
            prefixsums[i]=nums[i];
        }
    }

    scanf("%I64d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&lefty,&righty);
        lefty--;
        righty--;

        if (lefty!=0)
        ans=prefixsums[righty-1]-prefixsums[lefty-1];
        else
        ans=prefixsums[righty-1];

        printf("%I64d\n",ans);
    }

    return 0;
}