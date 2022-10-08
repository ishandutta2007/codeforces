#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long llong;

int n,k;
vector<int> Graph[200111];
int father[200111];
int sz[200111];
int depth[200111];

vector< pair<int,int> > all;

void DFS(int ver, int dad)
{
    int i;

    father[ver] = dad;
    depth[ver] = depth[dad] + 1;
    sz[ver] = 1;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        DFS(Graph[ver][i], ver);
        sz[ver] += sz[ Graph[ver][i] ];
    }

    return;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&k);

    for (i=1;i<n;i++)
    {
        int a,b;

        scanf("%d %d", &a, &b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    depth[0] = -1;
    DFS(1, 0);

    for (i=1;i<=n;i++)
    {
        all.push_back(make_pair(depth[i] - sz[i] + 1, i));
    }

    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());

    llong ans = 0;
    for (i=0;i<k;i++)
    {
        ans += all[i].first;
    }

    printf("%lld\n",ans);

    return 0;
}