#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long llong;

llong ans = 0;
int n,q;
int a[500111];
int freedom[500111];

map< pair<int,int>, int> mymap;
map< pair<int,int>, int>::iterator myit;

void removeMilestone(int s, int t, int u)
{
    if (freedom[u] <= a[u])
        ans++;

    freedom[u]--;
    mymap.erase(make_pair(s,t));
}

void addMilestone(int s, int t, int u)
{
    if (freedom[u] < a[u])
        ans--;

    freedom[u]++;
    mymap.insert(make_pair(make_pair(s,t),u));
}

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        ans += (llong)a[i];
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        int s,t,u;

        scanf("%d %d %d",&s,&t,&u);

        myit = mymap.find(make_pair(s,t));

        if (myit != mymap.end())
        {
            removeMilestone(s, t, (*myit).second);
        }

        if (u != 0)
            addMilestone(s, t, u);

        printf("%lld\n",ans);
    }

    return 0;
}