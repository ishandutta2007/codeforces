#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

int n,m;
llong net[300111];

vector<int> rich;
vector<int> poor;

vector< pair< pair<int,int>, llong > > ans;

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)
    {
        llong a,b,c;

        scanf("%lld %lld %lld",&a,&b,&c);

        net[a] -= c;
        net[b] += c;
    }

    for (i=1;i<=n;i++)
    {
        if (net[i] > 0)
            rich.push_back(i);
        if (net[i] < 0)
            poor.push_back(i);
    }

    while(!rich.empty() && !poor.empty())
    {
        llong resolve = min(net[rich.back()], -net[poor.back()]);

        ans.push_back(make_pair(make_pair(poor.back(), rich.back()), resolve));

        net[ rich.back() ] -= resolve;
        net[ poor.back() ] += resolve;

        while(!rich.empty() && net[ rich.back() ] == 0)
            rich.pop_back();

        while(!poor.empty() && net[ poor.back() ] == 0)
            poor.pop_back();
    }

    printf("%d\n",(int)ans.size());

    for (i=0;i<ans.size();i++)
    {
        printf("%d %d %lld\n",ans[i].first.first,ans[i].first.second,ans[i].second);
    }

    return 0;
}