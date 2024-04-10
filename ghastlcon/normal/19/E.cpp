#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#define N 10020
#define M 15
using namespace std;

int u[N], v[N];
map<pair<int, int>, int> r;
vector<int> e[2][N];
int d[N], f[N], p[M][N];
bool k[N];
vector<int> o;

void InitLCA(int x)
{
    int i, v;

    k[x] = true;
    for(i = 1; i < M; i ++)
        p[i][x] = p[i - 1][p[i - 1][x]];

    for(i = 0; i < (signed)e[0][x].size(); i ++)
        if(!k[v = e[0][x][i]])
        {
            e[1][x].push_back(v);
            r[make_pair(min(x, v), max(x, v))] = -r[make_pair(min(x, v), max(x, v))];
            d[v] = d[x] + 1;
            p[0][v] = x;
            InitLCA(v);
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

int DistanceLCA(int u, int v)
{
    return d[u] + d[v] - d[GetLCA(u, v)] * 2;
}

void DFS(int x, int w)
{
    static int v;
    int i, t;

    t = v;
    for(i = 0; i < (signed)e[1][x].size(); i ++)
        DFS(e[1][x][i], w);
    v += f[x];

    if(v - t == w && p[0][x] != x)
        o.push_back(r[make_pair(min(x, p[0][x]), max(x, p[0][x]))]);

    return;
}

int main(void)
{
    int n, m;
    int i;
    vector<int> x, y;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d", &u[i], &v[i]);
        r[make_pair(min(u[i], v[i]), max(u[i], v[i]))] = -i;
        e[0][u[i]].push_back(v[i]);
        e[0][v[i]].push_back(u[i]);
    }

    for(i = 1; i <= n; i ++)
        if(!k[i])
        {
            p[0][i] = i;
            InitLCA(i);
        }
    for(i = 1; i <= m; i ++)
        if(r[make_pair(min(u[i], v[i]), max(u[i], v[i]))] < 0)
            (DistanceLCA(u[i], v[i]) & 1 ? y : x).push_back(i);

    // if(n == 10000)
    //     printf("flag size %d\n", (int)x.size());

    if(x.empty())
    {
        printf("%d\n", m);
        for(i = 1; i <= m; i ++)
            printf("%d%c", i, " \n"[i == m]);
    }
    else
    {
        for(i = 0; i < (signed)x.size(); i ++)
        {
            f[u[x[i]]] ++;
            f[v[x[i]]] ++;
            f[GetLCA(u[x[i]], v[x[i]])] -= 2;
        }
        for(i = 0; i < (signed)y.size(); i ++)
        {
            f[u[y[i]]] --;
            f[v[y[i]]] --;
            f[GetLCA(u[y[i]], v[y[i]])] += 2;
        }
        for(i = 1; i <= n; i ++)
            if(p[0][i] == i)
                DFS(i, (int)x.size());

        if(x.size() == 1)
            o.push_back(x[0]);
        sort(o.begin(), o.end());

        printf("%d\n", (int)o.size());
        for(i = 0; i < (signed)o.size(); i ++)
            printf("%d%c", o[i], " \n"[i == (signed)o.size() - 1]);
    }

    return 0;
}