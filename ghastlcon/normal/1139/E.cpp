#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <utility>
#define N 20020
#define M 5020
using namespace std;

int a[N], b[N], v[N];
bool u[N];
vector<pair<int, int> > d;
vector<int> e[N], t[N];
int l[N], r[N], o[N];

bool LevelDinic(int s, int t)
{
    static int q[N];
    int i, k, l, r;

    memset(::l, 0, sizeof(::l));
    ::l[s] = 1;
    l = r = 0;
    for(q[r ++] = s; l < r; l ++)
    {
        s = q[l];
        for(i = 0; i < (signed)e[s].size(); i ++)
        {
            k = e[s][i];
            if(d[k].second && !::l[d[k].first])
            {
                ::l[d[k].first] = ::l[s] + 1;
                q[r ++] = d[k].first;
            }
        }
    }

    return ::l[t];
}

int BlockDinic(int x, int t, int v)
{
    int f, k;

    if(x == t || !v)
        return v;

    for(f = 0; r[x] < (signed)e[x].size(); r[x] ++)
    {
        k = e[x][r[x]];
        if(d[k].second && l[d[k].first] == l[x] + 1 && (f = BlockDinic(d[k].first, t, min(v, d[k].second))))
        {
            d[k    ].second -= f;
            d[k ^ 1].second += f;
            break;
        }
    }

    return f;
}

int Dinic(int s, int t)
{
    int o, k;

    for(o = 0; LevelDinic(s, t); )
    {
        memset(r, 0, sizeof(r));
        while((k = BlockDinic(s, t, INT_MAX)))
            o += k;
    }

    return o;
}

void AddEdge(int u, int v, int w)
{
    // printf("%d->%d : %d\n",u,v,w);
    e[u].push_back(d.size());
    d.push_back(make_pair(v, w));
    e[v].push_back(d.size());
    d.push_back(make_pair(u, 0));

    return;
}

int main(void)
{
    int n, m, k;
    int i, j, c, s;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i ++)
        scanf("%d", &b[i]);
    scanf("%d", &k);
    for(i = 0; i < k; i ++)
    {
        scanf("%d", &v[i]);
        u[-- v[i]] = true;
    }

    for(i = 1; i <= m; i ++)
        AddEdge(0, i, 1);
    for(i = 0; i < M; i ++)
        AddEdge(i + m + 1, N - 1, 1);
    for(i = 0; i < n; i ++)
        if(!u[i])
            t[a[i]].push_back(i);

    for(i = k - 1, c = s = 0; i > -1; i --)
    {
        do
        {
            c ++;
            for(j = 0; j < (signed)t[c - 1].size(); j ++)
                AddEdge(b[t[c - 1][j]], c - 1 + m + 1, 1);
            s += Dinic(0, N - 1);
        }while(s == c);
        o[i] = -- c;

        if(a[v[i]] > c)
            t[a[v[i]]].push_back(v[i]);
        else
            AddEdge(b[v[i]], a[v[i]] + m + 1, 1);
    }

    for(i = 0; i < k; i ++)
        printf("%d\n", o[i]);

    return 0;
}