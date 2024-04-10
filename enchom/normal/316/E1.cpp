#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

const Int MOD=1000000000;
Int nums[100001];
Int n,m;
Int fib[100001];

int main()
{
    Int i,j;
    Int tp;
    Int x,v;
    Int L,R,d;
    Int ans,cur;

    fib[0]=1;
    fib[1]=1;
    for (i=2;i<=100000;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];

        if (fib[i]>=MOD)
        {
            fib[i]-=MOD;
        }
    }

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&tp);

        if (tp==1)
        {
            scanf("%I64d %I64d",&x,&v);
            nums[x]=v;
        }
        else if (tp==2)
        {
            scanf("%I64d %I64d",&L,&R);

            ans=0;
            for (j=L;j<=R;j++)
            {
                cur=(fib[j-L]*nums[j])%MOD;
                ans=ans+cur;

                if (ans>=MOD)
                {
                    ans-=MOD;
                }
            }

            printf("%I64d\n",ans);
        }
    }

    return 0;
}