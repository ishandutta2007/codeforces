#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <tr1/tuple>
#define N 120
#define M 100020
#define Q 131071
using namespace std;

int a[N][N], b[N];
vector<tr1::tuple<int, int, int> > d;
vector<int> e[M];
int v[M], p[M];

bool AdvanceKarp(int s, int t)
{
    static int q[Q + 2];
    static bool u[M];
    int i, k, l, r;

    for(i = 0; i <= t; i ++)
        v[i] = INT_MAX >> 2;
    l = r = 0;
    v[s] = 0;

    for(q[r ++] = s; l < r; l ++)
    {
        s = q[l & Q];
        for(i = 0; i < (signed)e[s].size(); i ++)
        {
            k = e[s][i];
            if(tr1::get<1>(d[k]) && v[tr1::get<0>(d[k])] > v[s] + tr1::get<2>(d[k]))
            {
                v[tr1::get<0>(d[k])] = v[s] + tr1::get<2>(d[k]);
                p[tr1::get<0>(d[k])] = k;
                if(!u[tr1::get<0>(d[k])])
                {
                    u[tr1::get<0>(d[k])] = true;
                    q[(r ++) & Q] = tr1::get<0>(d[k]);
                }
            }
        }
        u[s] = false;
    }

    return v[t] != INT_MAX >> 2;
}

int AugmentKarp(int s, int t)
{
    int i, o;

    for(i = t, o = INT_MAX; i != s; i = tr1::get<0>(d[p[i] ^ 1]))
        o = min(o, tr1::get<1>(d[p[i]]));
    for(i = t; i != s; i = tr1::get<0>(d[p[i] ^ 1]))
    {
        tr1::get<1>(d[p[i]    ]) -= o;
        tr1::get<1>(d[p[i] ^ 1]) += o;
    }

    return o;
}

int Karp(int s, int t)
{
    int o;

    for(o = 0; AdvanceKarp(s, t); )
        o += v[t] * AugmentKarp(s, t);

    return o;
}

void AddEdge(int u, int v, int w, int c)
{
    e[u].push_back(d.size());
    d.push_back(tr1::make_tuple(v, w, c));
    e[v].push_back(d.size());
    d.push_back(tr1::make_tuple(u, 0, -c));

    return;
}

int main(void)
{
    int n, m, u, v;
    int i, j, k, t, c;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            if(i != j)
                a[i][j] = 2;
    while(m --)
    {
        scanf("%d %d", &u, &v);
        if((-- u) > (-- v))
            a[v][u] = 0;
        else
            a[u][v] = 1;
    }
    for(i = c = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
        {
            if(i < j)
            {
                if(!a[i][j])
                    b[i] ++;
                else if(a[i][j] == 1)
                    b[j] ++;
                else
                    AddEdge(0, ++ c, 1, 0);
            }
        }

    for(i = k = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            if(i < j && a[i][j] == 2)
            {
                AddEdge(++ k, i + c + 1, 1, 0);
                AddEdge(   k, j + c + 1, 1, 0);
            }
    // for(i=0;i<n;i++)cout<<b[i]<<' ';cout<<endl;
    for(i = 0; i < n; i ++)
        for(j = 0; j < N; j ++)
            AddEdge(i + c + 1, n + c + 1, 1, j + b[i]);
    Karp(0, n + c + 1);

    for(i = k = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            if(i < j && a[i][j] == 2)
            {
                k ++;
                for(t = 0; t < (signed)e[k].size(); t ++)
                    if(tr1::get<0>(d[e[k][t]]) && !tr1::get<1>(d[e[k][t]]))
                    {
                        a[i][j] = tr1::get<0>(d[e[k][t]]) == j + c + 1;
                        break;
                    }
            }
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            printf("%d%s", i <= j ? a[i][j] : a[j][i] ^ 1, j == n - 1 ? "\n" : "");

    return 0;
}