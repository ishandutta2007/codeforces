#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long Int;
//
int n,k;
int arr[200111];

map<Int,Int> mymap;
map<Int,Int>::iterator myit;

Int ctr1[200111];
Int ctr2[200111];

int main()
{
    int i;
    Int z;
    Int ans=0;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (i=1;i<=n;i++)
    {
        z=arr[i];

        if (z%k!=0)
        ctr1[i]=0LL;
        else
        {
            z/=k;

            myit=mymap.find(z);

            if (myit==mymap.end())
            ctr1[i]=0LL;
            else
            ctr1[i]=(*myit).second;
        }

        myit=mymap.find((Int)arr[i]);

        if (myit==mymap.end())
        {
            mymap.insert(make_pair((Int)arr[i],1LL));
        }
        else
        {
            (*myit).second=(*myit).second+1LL;
        }
    }

    ///

    mymap.clear();

    for (i=n;i>=1;i--)
    {
        z=(Int)arr[i]*(Int)k;

        myit=mymap.find(z);

        if (myit==mymap.end())
        ctr2[i]=0;
        else
        ctr2[i]=(*myit).second;

        myit=mymap.find((Int)arr[i]);

        if (myit==mymap.end())
        mymap.insert(make_pair((Int)arr[i],1LL));
        else
        (*myit).second=(*myit).second+1;
    }

    for (i=1;i<=n;i++)
    {
        ans+=ctr1[i]*ctr2[i];
    }

    printf("%lld\n",ans);

    return 0;
}