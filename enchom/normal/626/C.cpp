#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;

int main()
{
    int l,r,mid,best;
    int Only3,Only2,Both;
    int need;

    scanf("%d %d",&n,&m);

    l=1;
    r=10000000;

    while(l<=r)
    {
        mid=(l+r)/2;

        Only3=mid/3-mid/6;
        Only2=mid/2-mid/6;
        Both=mid/6;

        need=0;
        if (Only3<m)
        need+=m-Only3;
        if (Only2<n)
        need+=n-Only2;

        if (need<=Both)
        {
            best=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    printf("%d\n",best);

    return 0;
}