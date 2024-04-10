#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int req[26];
char inp[1001];
Int L;

int main()
{
    Int i,j;
    Int n;
    Int l,r,mid,best=-1;
    Int sum;
    Int len;

    memset(req,0,sizeof(req));

    scanf("%s",inp);
    L=strlen(inp);

    for (i=0;i<L;i++)
    {
        req[ inp[i]-'a' ]++;
    }

    scanf("%I64d",&n);

    l=1;
    r=10000;
    while(l<=r)
    {
        mid=(l+r)/2;

        sum=0;

        for (i=0;i<=25;i++)
        {
            sum=sum+req[i]/mid;

            if (req[i]%mid!=0)
            {
                sum++;
            }
        }

        if (sum>n)
        {
            l=mid+1;
        }
        else
        {
            best=mid;
            r=mid-1;
        }
    }

    printf("%I64d\n",best);
    if (best!=-1)
    {
        sum=0;
        for (i=0;i<=25;i++)
        {
            len=req[i]/best;

            if (req[i]%best!=0)
            len++;

            sum+=len;

            for (j=1;j<=len;j++)
            {
                printf("%c",(char)(i+'a'));
            }
        }

        for (i=1;i<=n-sum;i++)
        {
            printf("a");
        }

        printf("\n");
    }

    return 0;
}