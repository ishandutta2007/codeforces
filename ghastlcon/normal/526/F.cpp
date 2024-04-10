#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 300020
using namespace std;

class Node
{
public:
    int v;
    int c;
    int a;

    Node(void)
    {
        return;
    }
};

int a[N];
Node f[N << 2];

void InitSegment(int x, int l, int r)
{
    int m;

    f[x].v = l;
    f[x].c = 1;
    if(l == r)
        return;

    m = (l + r) >> 1;
    InitSegment(x << 1    , l    , m);
    InitSegment(x << 1 | 1, m + 1, r);

    return;
}

void PushdownSegment(int x)
{
    f[x << 1].v += f[x].a;
    f[x << 1].a += f[x].a;
    f[x << 1 | 1].v += f[x].a;
    f[x << 1 | 1].a += f[x].a;
    f[x].a = 0;

    return;
}

void PushupSegment(int x)
{
    f[x].v = min(f[x << 1].v, f[x << 1 | 1].v);
    f[x].c = (f[x].v == f[x << 1].v ? f[x << 1].c : 0) + (f[x].v == f[x << 1 | 1].v ? f[x << 1 | 1].c : 0);

    return;
}

void AddSegment(int x, int l, int r, int s, int t, int v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        f[x].v += v;
        f[x].a += v;

        return;
    }
    if(f[x].a)
        PushdownSegment(x);

    m = (l + r) >> 1;
    AddSegment(x << 1    , l    , m, s, t, v);
    AddSegment(x << 1 | 1, m + 1, r, s, t, v);
    PushupSegment(x);

    return;
}

int main(void)
{
    int n, u, v;
    int i;
    long long o;
    vector<int> f, g;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %d", &u, &v);
        a[u] = v;
    }

    f.push_back(0);
    g.push_back(0);
    InitSegment(1, 1, n);
    for(i = 1, o = 0; i <= n; i ++)
    {
        AddSegment(1, 1, n, 1, n, -1);
        for(; f.size() > 1 && a[f.back()] > a[i]; f.pop_back())
            AddSegment(1, 1, n, f[f.size() - 2] + 1, f.back(),  a[f.back()]);
        for(; g.size() > 1 && a[g.back()] < a[i]; g.pop_back())
            AddSegment(1, 1, n, g[g.size() - 2] + 1, g.back(), -a[g.back()]);
        // printf("add %d-%d : %d\n", f.back() + 1, i, -a[i]);
        // printf("add %d-%d : %d\n", g.back() + 1, i,  a[i]);
        AddSegment(1, 1, n, f.back() + 1, i, -a[i]);
        AddSegment(1, 1, n, g.back() + 1, i,  a[i]);
        f.push_back(i);
        g.push_back(i);
        o += ::f[1].c;
        // printf("%d : %d,%d\n", i, ::f[1].v, ::f[1].c);
    }
    printf("%I64d\n", o);

    return 0;
}