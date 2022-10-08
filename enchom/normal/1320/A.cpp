#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long llong;

map<int, llong> mymap;
map<int, llong>::iterator myit;
int n;

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        int b;

        scanf("%d",&b);

        int v = i - b;

        myit = mymap.find(v);

        if (myit == mymap.end())
        {
            mymap.insert(make_pair(v, b));
        }
        else
        {
            (*myit).second += (llong)b;
        }
    }

    llong ans = 0;
    for (myit = mymap.begin(); myit != mymap.end(); myit++)
    {
        ans = max(ans, (*myit).second);
    }

    printf("%lld\n",ans);

    return 0;
}