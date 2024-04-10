#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef int Int;

bool TFO[1000001];
Int grid[1001][1001];
bool mgrid[1001][1001];
Int nums[1001];
Int L;
Int n,m;

bool Good(Int k)
{
    memset(TFO,false,sizeof(TFO));
    memset(mgrid,false,sizeof(mgrid[0][0])*1001*1001);

    Int i,j,in;
    Int merged;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]>=k)
            {
                mgrid[i][j]=true;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        L=0;
        for (j=1;j<=m;j++)
        {
            if (mgrid[i][j])
            {
                L++;
                nums[L]=j;
            }
        }

        for (j=1;j<=L;j++)
        {
            for (in=j+1;in<=L;in++)
            {
                merged=(nums[j]-1)*1000+(nums[in]-1);
                if (TFO[merged])
                {
                    return true;
                }

                TFO[merged]=true;
            }
        }
    }

    return false;
}

int main()
{
    Int i,j;
    Int l,r,mid;
    Int best;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    l=0;
    r=1000000000;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Good(mid))
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    printf("%d\n",best);

    return 0;
}