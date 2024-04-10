#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int F[9000001];
Int nums[3001];
Int n;
Int inv=0;

int main()
{
    Int i,j;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (nums[i]>nums[j])
            {
                inv++;
            }
        }
    }

    F[0]=0;
    F[1]=1;

    for (i=2;i<=inv;i++)
    {
        F[i]=F[i-2]+4;
    }

    printf("%I64d.000000\n",F[inv]);

    return 0;
}