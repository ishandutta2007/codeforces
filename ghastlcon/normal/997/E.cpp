#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 120020
using namespace std;

class Node
{
public:
    int v;
    int c;
    int a;
    int s;
    long long o;

    Node(void)
    {
        return;
    }
};

int a[N];
Node f[N << 2];
vector<pair<int, int> > q[N];
long long o[N];

void PushdownSegment(int x)
{
    f[x << 1].v += f[x].a;
    f[x << 1].a += f[x].a;
    if(f[x << 1].v == f[x].v)
    {
        f[x << 1].s += f[x].s;
        f[x << 1].o += (long long)f[x].s * f[x << 1].c;
    }
    f[x << 1 | 1].v += f[x].a;
    f[x << 1 | 1].a += f[x].a;
    if(f[x << 1 | 1].v == f[x].v)
    {
        f[x << 1 | 1].s += f[x].s;
        f[x << 1 | 1].o += (long long)f[x].s * f[x << 1 | 1].c;
    }
    f[x].a = f[x].s = 0;

    return;
}

void PushupSegment(int x)
{
    f[x].v = min(f[x << 1].v, f[x << 1 | 1].v);
    f[x].c = (f[x].v == f[x << 1].v ? f[x << 1].c : 0) + (f[x].v == f[x << 1 | 1].v ? f[x << 1 | 1].c : 0);
    f[x].o = f[x << 1].o + f[x << 1 | 1].o;

    return;
}

void InitSegment(int x, int l, int r)
{
    int m;

    if(l == r)
    {
        f[x].v = l;
        f[x].c = 1;

        return;
    }

    m = (l + r) >> 1;
    InitSegment(x << 1    , l    , m);
    InitSegment(x << 1 | 1, m + 1, r);
    PushupSegment(x);

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
    PushdownSegment(x);

    m = (l + r) >> 1;
    AddSegment(x << 1    , l    , m, s, t, v);
    AddSegment(x << 1 | 1, m + 1, r, s, t, v);
    PushupSegment(x);

    return;
}

long long SumSegment(int x, int l, int r, int s, int t)
{
    int m;

    if(l > t || r < s)
        return 0;
    if(l >= s && r <= t)
        return f[x].o;
    PushdownSegment(x);

    m = (l + r) >> 1;

    return SumSegment(x << 1, l, m, s, t) + SumSegment(x << 1 | 1, m + 1, r, s, t);
}

int main(void)
{
    int n, m, l, r;
    int i, j;
    vector<int> x, y;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d", &l, &r);
        q[r].push_back(make_pair(l, i));
    }

    InitSegment(1, 1, n);
    x.push_back(0);
    y.push_back(0);
    for(i = 1; i <= n; i ++)
    {
        AddSegment(1, 1, n, 1, n, -1);
        for(; x.size() > 1 && a[x.back()] > a[i]; x.pop_back())
            AddSegment(1, 1, n, x[x.size() - 2] + 1, x.back(),  a[x.back()]);
        for(; y.size() > 1 && a[y.back()] < a[i]; y.pop_back())
            AddSegment(1, 1, n, y[y.size() - 2] + 1, y.back(), -a[y.back()]);
        AddSegment(1, 1, n, x.back() + 1, i, -a[i]);
        x.push_back(i);
        AddSegment(1, 1, n, y.back() + 1, i,  a[i]);
        y.push_back(i);

        f[1].s ++;
        f[1].o += f[1].c;
        // printf("counting %d\n", f[1].c);

        for(j = 0; j < (signed)q[i].size(); j ++)
            o[q[i][j].second] = SumSegment(1, 1, n, q[i][j].first, i);
    }

    for(i = 1; i <= m; i ++)
        printf("%I64d\n", o[i]);

    return 0;
}