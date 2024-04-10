#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct beacon
{
    int a,b;
};

beacon beacons[100111];
int n;

int F[100111];

bool BS(beacon a,beacon b)
{
    return a.a<b.a;
}

int main()
{
    int i;
    int reach;
    int ans,curans;
    int l,r,mid,best;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&beacons[i].a,&beacons[i].b);
    }

    sort(beacons+1,beacons+1+n,BS);

    F[0]=0;

    reach=1;
    for (i=1;i<=n;i++)
    {
        l=1;
        r=i;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (beacons[mid].a>=beacons[i].a-beacons[i].b)
            {
                best=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        reach=best;

        F[i]=F[reach-1]+(i-reach);
    }

    ans=n;
    for (i=n;i>=1;i--)
    {
        curans=F[i]+(n-i);

        if (curans<ans)
        ans=curans;
    }

    printf("%d\n",ans);

    return 0;
}