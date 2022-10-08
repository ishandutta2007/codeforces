#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n,l,r,Ql,Qr;
Int w[100001];
Int prefixsums[100001];
Int suffixsums[100002];

int main()
{
    Int i;
    Int L,R;
    Int addon;
    Int mincost=-1,curcost;
    Int reps;

    scanf("%I64d %I64d %I64d %I64d %I64d",&n,&l,&r,&Ql,&Qr);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&w[i]);
    }

    prefixsums[0]=0;
    for (i=1;i<=n;i++)
    {
        prefixsums[i]=prefixsums[i-1]+w[i]*l;
    }

    suffixsums[n+1]=0;
    for (i=n;i>=1;i--)
    {
        suffixsums[i]=suffixsums[i+1]+w[i]*r;
    }

    for (i=0;i<=n;i++)
    {
        L=i;
        R=n-i;

        curcost=prefixsums[i]+suffixsums[i+1];

        if (L!=R)
        {
            if (L<R)
            {
                reps=R-L-1;

                curcost=curcost+Qr*reps;
            }
            else
            {
                reps=L-R-1;

                curcost=curcost+Ql*reps;
            }
        }

        if (mincost==-1 || curcost<mincost)
        {
            mincost=curcost;
        }
    }

    printf("%I64d\n",mincost);

    return 0;
}