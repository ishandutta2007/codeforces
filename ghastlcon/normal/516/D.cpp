#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <ext/pb_ds/priority_queue.hpp>
#define N 100020
#define M 17
using namespace std;

vector<pair<int, int> > e[N];
int p[M][N], d[N];
long long z[N], l[N];
__gnu_pbds::priority_queue<long long> q[N];

void DFS(int x, int p)
{
    int i;

    for(i = 1, ::p[0][x] = p; i < M; i ++)
        ::p[i][x] = ::p[i - 1][::p[i - 1][x]];

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i].first != p)
        {
            d[e[x][i].first] = d[x] + 1;
            z[e[x][i].first] = z[x] + e[x][i].second;
            DFS(e[x][i].first, x);
        }

    return;
}

int GetLCA(int u, int v)
{
    int i, t;

    if(d[u] < d[v])
        swap(u, v);
    t = d[u] - d[v];
    for(i = 0; i < M; i ++)
        if(t & (1 << i))
            u = p[i][u];
    if(u == v)
        return u;

    for(i = M - 1; i > -1; i --)
        if(p[i][u] != p[i][v])
        {
            u = p[i][u];
            v = p[i][v];
        }

    return p[0][u];
}

long long DistanceLCA(int u, int v)
{
    return z[u] + z[v] - z[GetLCA(u, v)] * 2;
}

int Solve(int x, int p, long long s)
{
    int i, o;

    q[x].clear();
    for(i = o = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i].first != p)
        {
            o = max(o, Solve(e[x][i].first, x, s));
            q[x].join(q[e[x][i].first]);
        }

    for(; !q[x].empty() && q[x].top() - l[x] > s; q[x].pop())
        ;
    q[x].push(l[x]);

    return max(o, (int)q[x].size());
}

int main(void)
{
    int n, m, u, v, w;
    long long s;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    DFS(1, 1);

    for(i = u = 1; i <= n; i ++)
        if(DistanceLCA(1, i) > DistanceLCA(1, u))
            u = i;
    for(i = v = 1; i <= n; i ++)
        if(DistanceLCA(u, i) > DistanceLCA(u, v))
            v = i;
    // printf("diameter %d-%d\n", u, v);

    for(i = 1; i <= n; i ++)
        l[i] = max(DistanceLCA(u, i), DistanceLCA(v, i));
    w = (int)(min_element(l + 1, l + n + 1) - l);

    scanf("%d", &m);
    while(m --)
    {
        scanf("%I64d", &s);
        printf("%d\n", Solve(w, w, s));
    }

    return 0;
}
//