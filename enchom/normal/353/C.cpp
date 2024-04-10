#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char inp[100001];
Int nums[100001];
Int L;
Int prefixsums[100001];

int main()
{
    Int n;
    Int i;
    Int maxsum=0,cursum;
    Int sumsofar=0;

    scanf("%I64d",&n);

    prefixsums[0]=0;

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);

        prefixsums[i]=prefixsums[i-1]+nums[i];
    }

    scanf("%s",inp+1);

    L=strlen(inp+1);

    for (i=L;i>=1;i--)
    {
        if (inp[i]=='1')
        {
            cursum=prefixsums[i-1]+sumsofar;

            sumsofar+=nums[i];

            if (cursum>maxsum)
            maxsum=cursum;
        }
    }

    if (sumsofar>maxsum)
    maxsum=sumsofar;

    printf("%I64d\n",maxsum);

    return 0;
}