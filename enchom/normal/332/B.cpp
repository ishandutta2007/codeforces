#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int nums[200001];
Int NKSum[200001];
Int F[200001];
Int WhatA[200001];

int main()
{
    Int n,k;
    Int i;
    Int themax=-1,cur;
    Int themaxb,themaxa;

    scanf("%I64d %I64d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }


    NKSum[1]=0;
    for (i=1;i<=k;i++)
    {
        NKSum[1]+=nums[i];
    }

    for (i=k+1;i<=n;i++)
    {
        NKSum[i-k+1]=NKSum[i-k]-nums[i-k]+nums[i];
    }

    F[k]=NKSum[1];
    WhatA[k]=1;

    for (i=k+1;i<=n;i++)
    {
        if (F[i-1]>=NKSum[i-k+1])
        {
            F[i]=F[i-1];
            WhatA[i]=WhatA[i-1];
        }
        else
        {
            F[i]=NKSum[i-k+1];
            WhatA[i]=i-k+1;
        }
    }

    for (i=k+1;i<=n-k+1;i++)
    {
        cur=NKSum[i]+F[i-1];

        if (cur>themax || themax==-1)
        {
            themaxb=i;
            themaxa=WhatA[i-1];
            themax=cur;
        }
        else if (cur==themax)
        {
            if (WhatA[i-1]<themaxa)
            {
                themaxa=WhatA[i-1];
                themaxb=i;
            }
            else if (WhatA[i-1]==themaxa)
            {
                if (i<themaxb)
                {
                    themaxb=i;
                }
            }
        }
    }

    printf("%I64d %I64d\n",themaxa,themaxb);

    return 0;
}