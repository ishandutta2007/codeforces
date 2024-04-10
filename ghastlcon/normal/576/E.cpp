#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <tuple>
#define N 500020
#define K 51
using namespace std;

class UFS
{
private:
    int f[N + N];
    vector<tuple<int, int, int> > g;

public:
    UFS(void)
    {
        memset(f, -1, sizeof(f));

        return;
    }

    int GetUFS(int x)
    {
        for(; f[x] > -1; x = f[x])
            ;

        return x;
    }

    void MergeUFS(int u, int v, int k)
    {
        u = GetUFS(u);
        v = GetUFS(v);
        if(u != v)
        {
            g.push_back(make_tuple(k, u, f[u]));
            g.push_back(make_tuple(k, v, f[v]));
            if(f[u] > f[v])
                swap(u, v);
            f[u] += f[v];
            f[v] = u;
        }

        return;
    }

    void UndoUFS(int k)
    {
        for(; !g.empty() && get<0>(g.back()) == k; g.pop_back())
            f[get<1>(g.back())] = get<2>(g.back());

        return;
    }
};

int n, k, q;
int u[N], v[N], p[N], w[N];
UFS f[K];
vector<int> g[N << 2], h[N];
int r[N];

void InsertSegment(int x, int l, int r, int s, int t, int v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        g[x].push_back(v);

        return;
    }

    m = (l + r) >> 1;
    InsertSegment(x << 1    , l    , m, s, t, v);
    InsertSegment(x << 1 | 1, m + 1, r, s, t, v);

    return;
}

void DFSSegment(int x, int l, int r)
{
    int m;
    int i;

    for(i = 0; i < (signed)g[x].size(); i ++)
    {
        f[w[g[x][i]]].MergeUFS(u[p[g[x][i]]], v[p[g[x][i]]] + n, x);
        f[w[g[x][i]]].MergeUFS(u[p[g[x][i]]] + n, v[p[g[x][i]]], x);
    }
    if(l == r)
    {
        if(f[w[l]].GetUFS(u[p[l]]) == f[w[l]].GetUFS(v[p[l]]))
        {
            printf("NO\n");
            if(::r[p[l]])
                InsertSegment(1, 1, q, l + 1, *upper_bound(h[p[l]].begin(), h[p[l]].end(), l) - 1, ::r[p[l]]);
        }
        else
        {
            printf("YES\n");
            InsertSegment(1, 1, q, l + 1, *upper_bound(h[p[l]].begin(), h[p[l]].end(), l) - 1, l);
            ::r[p[l]] = l;
        }
        for(i = 1; i <= k; i ++)
            f[i].UndoUFS(x);

        return;
    }

    m = (l + r) >> 1;
    DFSSegment(x << 1    , l    , m);
    DFSSegment(x << 1 | 1, m + 1, r);
    for(i = 1; i <= k; i ++)
        f[i].UndoUFS(x);

    return;
}

int main(void)
{
    int m;
    int i;

    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(i = 1; i <= m; i ++)
        scanf("%d %d", &u[i], &v[i]);

    for(i = 1; i <= q; i ++)
    {
        scanf("%d %d", &p[i], &w[i]);
        h[p[i]].push_back(i);
        // if(!r[p[i]])
        // {
        //     InsertSegment(1, 1, q, i, i, i);
        //     r[p[i]] = i;
        // }
    }
    for(i = 1; i <= m; i ++)
        h[i].push_back(q + 1);
    DFSSegment(1, 1, q);

    return 0;
}