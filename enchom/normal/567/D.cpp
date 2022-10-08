#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,k,a;
int m;
int x[200111];
bool broken[200111];

bool Cheating(int q)
{
    int i,j;
    int ctr=0;
    int placed=0;

    memset(broken,false,sizeof(broken));

    for (i=1;i<=q;i++)
    {
        broken[ x[i] ]=true;
    }

    for (i=1;i<=n;i++)
    {
        if (broken[i])
        placed=0;
        else
        placed++;

        if (placed==a)
        {
            ctr++;
            placed=0;
            i++;
        }
    }

    return ctr<k;
}

int main()
{
    int i;
    int l,r,mid,best=-1;

    scanf("%d %d %d",&n,&k,&a);

    scanf("%d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d",&x[i]);
    }

    l=1;
    r=m;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Cheating(mid))
        {
            r=mid-1;
            best=mid;
        }
        else
        l=mid+1;
    }

    printf("%d\n",best);

    return 0;
}