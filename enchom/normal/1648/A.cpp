#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
typedef long long llong;

map< int, vector< pair<int, int> > > groups;
int n, m;

vector<int> coords;

llong solveCoords(vector<int> &c)
{
    int i;
    llong ans = 0;
    llong sumSoFar = 0;

    sort(c.begin(), c.end());

    for (i=0;i<c.size();i++)
    {
        ans += (llong)i * (llong)c[i] - sumSoFar;

        sumSoFar += c[i];
    }

    return ans;
}

llong solveGroup(vector< pair<int, int> > &g)
{
    int i;
    llong ans = 0;

    coords.clear();
    for (i=0;i<g.size();i++)
    {
        coords.push_back(g[i].first);
    }
    ans += solveCoords(coords);

    coords.clear();
    for (i=0;i<g.size();i++)
    {
        coords.push_back(g[i].second);
    }
    ans += solveCoords(coords);

    return ans;
}

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            int a;

            scanf("%d", &a);

            auto it = groups.find(a);

            if (it == groups.end())
                groups.insert(make_pair(a, vector< pair<int,int> >()));

            it = groups.find(a);

            (*it).second.push_back(make_pair(i, j));
        }
    }

    llong ans = 0;
    for (auto it = groups.begin(); it != groups.end(); it++)
    {
        ans += solveGroup((*it).second);
    }

    printf("%lld\n", ans);
}