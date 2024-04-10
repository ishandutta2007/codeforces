#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define int long long
#define N 200020
#define M 800020
#define INFINITE 1000000000000000000LL
#pragma GCC optimize("O3")
using namespace std;

int n, k, s;
int h[N], x[M], v[M], w[M], c;
pair<int, int> f[N * 4];
int o[N];
bool u[N];

void BuildWinner(int n)
{
    int i;

    k = pow(2, ceil(log(n) / log(2)));
    for(i = 0;i < k;i ++)
    {
        f[i + k].first = INFINITE;
        f[i + k].second = i;
    }
    for(i = k - 1;i > 0;i --)
    {
        f[i].first = min(f[i << 1].first, f[i << 1 | 1].first);
        f[i].second = f[i << 1].first < f[i << 1 | 1].first ? f[i << 1].second : f[i << 1 | 1].second;
    }

    return;
}

void SetWinner(int p, int v)
{
    for(f[p += k].first = v;p >>= 1;)
    {
        f[p].first = min(f[p << 1].first, f[p << 1 | 1].first);
        f[p].second = f[p << 1].first < f[p << 1 | 1].first ? f[p << 1].second : f[p << 1 | 1].second;
    }

    return;
}

void Dijkstra(void)
{
    int i, j;
    pair<int, int> t, p;

    BuildWinner(n);
    SetWinner(s, 0);
    u[s] = true;

    for(i = 0;i < n;i ++)
        o[i] = INFINITE;

    for(i = 1;i < n;i ++)
    {
        //cout<<i<<endl;
        t = f[1];
        o[t.second] = t.first;
        SetWinner(t.second, INFINITE);
        u[t.second] = true;

        for(j = h[t.second];j != -1;j = x[j])
            if(!u[v[j]] && f[v[j] + k].first > t.first + w[j])
                SetWinner(v[j], t.first + w[j]);
    }
    o[f[1].second] = f[1].first;

    return;
}

void AddEdge(int u, int v, int w)
{
    x[c] = h[u];
    h[u] = c;
    ::v[c] = v;
    ::w[c] = w;
    c ++;

    return;
}


signed main()
{
    int m;
    int u, v, w;
    int i;

    memset(h, -1, sizeof(h));
    scanf("%I64d %I64d", &n, &m);
    while(m --)
    {
        scanf("%I64d %I64d %I64d", &u, &v, &w);
        AddEdge(-- u, -- v, w * 2);
        AddEdge(   v,    u, w * 2);
    }
    for(i = 0;i < n;i ++)
    {
        scanf("%I64d", &w);
        AddEdge(n, i, w);
    }

    s = n ++;
    Dijkstra();
    for(i = 0;i < n - 1;i ++)
        printf("%I64d ", o[i]);

    return 0;
}