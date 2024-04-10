#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long llong;

struct pos
{
    int r, c;
};

const llong INF = 1000000000000000000LL;

int t;
int n, m;
vector< pair<int, pair<int, int> > > edges;
vector<int> Graph[511];

int hopDist[511][511];

int q[2111];
int qL;
int uk;

void BFS(int ver)
{
    int i, j;

    for (i=1;i<=n;i++)
    {
        hopDist[ver][i] = -1;
    }
    hopDist[ver][ver] = 0;

    qL = 1;
    q[qL] = ver;
    uk = 1;

    while(uk <= qL)
    {
        int cver = q[uk];

        for (int i = 0; i < Graph[cver].size(); i++)
        {
            int nver = Graph[cver][i];

            if (hopDist[ver][nver] == -1)
            {
                hopDist[ver][nver] = hopDist[ver][cver] + 1;
                qL++;
                q[qL] = nver;
            }
        }

        uk++;
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &m);

        for (i=0;i<=n+1;i++)
        {
            Graph[i].clear();
        }
        edges.clear();

        for (i=1;i<=m;i++)
        {
            int a, b, c;

            scanf("%d %d %d", &a, &b, &c);

            edges.push_back(make_pair(c, make_pair(a, b)));
            edges.push_back(make_pair(c, make_pair(b, a)));

            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }

        for (i=1;i<=n;i++)
        {
            BFS(i);
        }

        sort(edges.begin(), edges.end());

        llong ans = INF;
        for (i=0;i<edges.size();i++)
        {
            llong cost = edges[i].first;
            int v1 = edges[i].second.first;
            int v2 = edges[i].second.second;

            ans = min(ans, cost * (hopDist[1][v1] + hopDist[v2][n] + 1));

            for (j=1;j<=n;j++)
            {
                ans = min(ans, cost * (hopDist[1][j] + hopDist[j][v1] + hopDist[j][n] + 2));
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}