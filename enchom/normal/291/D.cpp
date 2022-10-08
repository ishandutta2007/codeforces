#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int nums[10001];
Int req[10001];
Int whereis[10001];

int main()
{
    Int n,k;
    Int i,j;
    Int need;

    scanf("%I64d %I64d",&n,&k);

    for (i=1;i<=n;i++)
    {
        nums[i]=1;
        req[i]=n-i;
        whereis[n-i]=i;
    }
    nums[n]=0;

    for (i=1;i<=k;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (nums[j]*2<req[j])
            {
                nums[j]=nums[j]*2;
                printf("%I64d",j);
            }
            else
            {
                need=req[j]-nums[j];
                nums[j]=req[j];
                printf("%I64d",whereis[need]);
            }

            if (j!=n)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}