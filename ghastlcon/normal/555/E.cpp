#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 200020
#define M 18
using namespace std;

namespace Tarjan
{
    vector<pair<int, int> > e[N];
    bool u[N];
    int v[N];

    void Tarjan(int x, int p)
    {
        static int d[N], l[N];
        static int k;
        int i;

        if(d[x])
            return;

        d[x] = l[x] = ++ k;
        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i].second != p)
            {
                if(!d[e[x][i].first])
                {
                    Tarjan(e[x][i].first, e[x][i].second);
                    l[x] = min(l[x], l[e[x][i].first]);
                    if(l[e[x][i].first] > d[x])
                        u[e[x][i].second] = true;
                }
                else
                    l[x] = min(l[x], d[e[x][i].first]);
            }

        return;
    }

    void Block(int x, int k)
    {
        int i;

        if(v[x])
            return;
        v[x] = k;

        for(i = 0; i < (signed)e[x].size(); i ++)
            if(!u[e[x][i].second])
                Block(e[x][i].first, k);

        return;
    }
}

namespace Tree
{
    vector<int> e[N], r;
    int u[N], d[N], p[M][N];
    long long f[N];
    vector<pair<int, int> > g;

    void InitLCA(int x, int p)
    {
        int i;

        for(i = 1, Tree::p[0][x] = p; i < M; i ++)
            Tree::p[i][x] = Tree::p[i - 1][Tree::p[i - 1][x]];
        u[x] = (int)r.size();

        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i] != p)
            {
                d[e[x][i]] = d[x] + 1;
                InitLCA(e[x][i], x);
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

    void InsertPath(int u, int v)
    {
        int w;

        w = GetLCA(u, v);
        f[u] ++;
        f[w] --;
        g.push_back(make_pair(v, w));

        return;
    }

    void DFSA(int x, int p)
    {
        static int s;
        int i, t;

        t = s;
        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i] != p)
                DFSA(e[x][i], x);
        s += f[x];
        f[x] = s - t;

        return;
    }

    void DFSB(int x, int p)
    {
        int i;

        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i] != p)
            {
                f[e[x][i]] += f[x];
                DFSB(e[x][i], x);
            }

        return;
    }

    bool Solve(void)
    {
        int i;

        for(i = 0; i < (signed)r.size(); i ++)
        {
            DFSA(r[i], r[i]);
            DFSB(r[i], r[i]);
        }
        for(i = 0; i < (signed)g.size(); i ++)
            if(f[g[i].first] != f[g[i].second])
                return false;

        return true;
    }
}

int main(void)
{
    int n, m, q, u, v;
    int i, j, c;

    scanf("%d %d %d", &n, &m, &q);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d", &u, &v);
        Tarjan::e[u].push_back(make_pair(v, i));
        Tarjan::e[v].push_back(make_pair(u, i));
    }

    for(i = 1; i <= n; i ++)
        Tarjan::Tarjan(i, 0);
    for(i = 1, c = 0; i <= n; i ++)
        if(!Tarjan::v[i])
            Tarjan::Block(i, ++ c);
    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)Tarjan::e[i].size(); j ++)
            if(Tarjan::v[i] != Tarjan::v[Tarjan::e[i][j].first])
            {
                // printf("%d -- %d\n", Tarjan::v[i], Tarjan::v[Tarjan::e[i][j].first]);
                Tree::e[Tarjan::v[i]].push_back(Tarjan::v[Tarjan::e[i][j].first]);
            }
    for(i = 1; i <= c; i ++)
        if(!Tree::u[i])
        {
            Tree::r.push_back(i);
            Tree::InitLCA(i, i);
        }
    // for(i=1;i<=m;i++)cout<<::u[i]<<' ';cout<<endl;

    for(i = 1; i <= q; i ++)
    {
        scanf("%d %d", &u, &v);
        u = Tarjan::v[u];
        v = Tarjan::v[v];
        if(u == v)
            continue;
        if(Tree::u[u] != Tree::u[v])
        {
            printf("No\n");
            break;
        }
        Tree::InsertPath(u, v);
    }
    if(i > q)
        printf("%s\n", Tree::Solve() ? "Yes" : "No");

    return 0;
}