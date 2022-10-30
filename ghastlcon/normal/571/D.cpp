#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#define N 1000020
using namespace std;

tuple<char, int, int> a[N];
vector<int> e[2][N], v[N];
int p[2][N], l[2][N], r[2][N], z[N];
pair<int, int> f[N << 2];
long long o[N], g[N];

void SetSegment(int x, int l, int r, int s, int t, int v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        f[x] = make_pair(v, v);

        return;
    }
    if(f[x].second)
    {
        f[x << 1] = f[x << 1 | 1] = make_pair(f[x].second, f[x].second);
        f[x].second = 0;
    }

    m = (l + r) >> 1;
    SetSegment(x << 1    , l    , m, s, t, v);
    SetSegment(x << 1 | 1, m + 1, r, s, t, v);

    return;
}

int GetSegment(int x, int l, int r, int p)
{
    int m;

    if(l == r)
        return f[x].first;
    if(f[x].second)
    {
        f[x << 1] = f[x << 1 | 1] = make_pair(f[x].second, f[x].second);
        f[x].second = 0;
    }

    m = (l + r) >> 1;
    if(p <= m)
        return GetSegment(x << 1, l, m, p);

    return GetSegment(x << 1 | 1, m + 1, r, p);
}

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int n, int v)
{
    for(; p <= n; p += Lowbit(p))
        g[p] += v;

    return;
}

long long SumFenwick(int p)
{
    long long o;

    for(o = 0; p; p -= Lowbit(p))
        o += g[p];

    return o;
}

void DFS(int x, vector<int> e[N], int *l, int *r, int *z, int &k)
{
    int i;

    if(z)
        z[x] = e[x].empty();
    l[x] = ++ k;
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        DFS(e[x][i], e, l, r, z, k);
        if(z)
            z[x] += z[e[x][i]];
    }
    r[x] = k;

    return;
}

int main(void)
{
    int n, m;
    int i, k, c[2];

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        p[0][i] = p[1][i] = i;
    for(i = 1, c[0] = c[1] = n; i <= m; i ++)
    {
        scanf("%*[^UMAZQ]%c %d", &get<0>(a[i]), &get<1>(a[i]));
        switch(get<0>(a[i]))
        {
        case 'U':
            scanf("%d", &get<2>(a[i]));
            e[0][++ c[0]].push_back(p[0][get<1>(a[i])]);
            e[0][c[0]].push_back(p[0][get<2>(a[i])]);
            p[0][get<1>(a[i])] = c[0];
            p[0][get<2>(a[i])] = -1;
            break;

        case 'M':
            scanf("%d", &get<2>(a[i]));
            e[1][++ c[1]].push_back(p[1][get<1>(a[i])]);
            e[1][c[1]].push_back(p[1][get<2>(a[i])]);
            p[1][get<1>(a[i])] = c[1];
            p[1][get<2>(a[i])] = -1;
            break;

        case 'A':
            get<1>(a[i]) = p[0][get<1>(a[i])];
            break;

        case 'Z':
            get<1>(a[i]) = p[1][get<1>(a[i])];
            break;

        default:
            break;
        }
    }

    c[0] ++;
    c[1] ++;
    for(i = 1; i <= n; i ++)
    {
        if(p[0][i] != -1)
            e[0][c[0]].push_back(p[0][i]);
        if(p[1][i] != -1)
            e[1][c[1]].push_back(p[1][i]);
    }
    k = 0;
    DFS(c[0], e[0], l[0], r[0], z   , k);
    k = 0;
    DFS(c[1], e[1], l[1], r[1], NULL, k);

    for(i = 1; i <= m; i ++)
        if(get<0>(a[i]) == 'Z')
            SetSegment(1, 1, c[1], l[1][get<1>(a[i])], r[1][get<1>(a[i])], i);
        else if(get<0>(a[i]) == 'Q')
        {
            // printf("fetch %d\n", GetSegment(1, 1, c[1], l[1][get<1>(a[i])]));
            v[GetSegment(1, 1, c[1], l[1][get<1>(a[i])])].push_back(i);
        }

    for(i = 1; i <= m; i ++)
    {
        if(get<0>(a[i]) == 'A')
        {
            AddFenwick(l[0][get<1>(a[i])]    , c[0],  z[get<1>(a[i])]);
            AddFenwick(r[0][get<1>(a[i])] + 1, c[0], -z[get<1>(a[i])]);
        }
        else if(get<0>(a[i]) == 'Q')
            printf("%lld\n", o[i] + SumFenwick(l[0][get<1>(a[i])]));
        for(k = 0; k < (signed)v[i].size(); k ++)
            o[v[i][k]] -= SumFenwick(l[0][get<1>(a[v[i][k]])]);
    }

    return 0;
}