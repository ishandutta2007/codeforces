#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;

    Edge(void)
    {
        return;
    }

    bool operator<(const Edge &that) const
    {
        return this -> w > that.w;
    }
};

Edge a[N];
int f[N];
bool g[N];

int GetUFS(int x)
{
    int i, t;

    for(i = x; f[i] > -1; i = f[i])
        ;
    while(x != i)
    {
        t = f[x];
        f[x] = i;
        x = t;
    }

    return i;
}

void MergeUFS(int u, int v)
{
    u = GetUFS(u);
    v = GetUFS(v);
    if(u != v)
    {
        if(f[u] > f[v])
            swap(u, v);
        f[u] += f[v];
        f[v] = u;
        g[u] |= g[v];
    }

    return;
}

int main(void)
{
    int n, m;
    int i, o;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        f[i] = -1;
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
        a[i].u --;
        a[i].v --;
    }
    sort(a, a + m);

    for(i = o = 0; i < m; i ++)
        if(GetUFS(a[i].u) != GetUFS(a[i].v))
        {
            if(g[GetUFS(a[i].u)] && g[GetUFS(a[i].v)])
                continue;
            o += a[i].w;
            MergeUFS(a[i].u, a[i].v);
        }
        else if(!g[GetUFS(a[i].u)])
        {
            o += a[i].w;
            g[GetUFS(a[i].u)] = true;
        }
    printf("%d\n", o);

    return 0;
}