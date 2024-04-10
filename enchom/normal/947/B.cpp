#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n;
llong V[100111];
llong T[100111];
llong tSum[100111];

int meltDay[100111];
llong lastDayMelt[100111];

llong getSum(int L,int R)
{
    if (L>R)
        return 0;
    else
        return tSum[R]-tSum[L-1];
}

vector<int> melted[100111];

int main()
{
    int i,j;
    int l,r,mid,best;
    int frozenCtr=0;
    llong meltToday=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&V[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&T[i]);
        tSum[i]=tSum[i-1]+T[i];
    }

    for (i=1;i<=n;i++)
    {
        best=n+1;

        l=i;
        r=n;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (getSum(i,mid)>=V[i])
            {
                best=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        meltDay[i]=best;
        lastDayMelt[i]=V[i]-getSum(i,best-1);

        melted[best].push_back(lastDayMelt[i]);
    }

    for (i=1;i<=n;i++)
    {
        meltToday=0;

        frozenCtr++;

        for (j=0;j<melted[i].size();j++)
        {
            frozenCtr--;

            meltToday+=melted[i][j];
        }

        meltToday+=(llong)frozenCtr*T[i];

        printf("%lld",meltToday);
        if (i!=n)
            printf(" ");
    }
}