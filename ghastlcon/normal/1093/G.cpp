#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 200020
#define K 5
using namespace std;

class Point
{
public:
    int p[K];

    Point(void)
    {
        memset(p, 0, sizeof(p));

        return;
    }
};

class Node
{
public:
    Point f[1 << K | 1];

    Node(void)
    {
        int i, j;

        for(i = 0; i < (1 << K); i ++)
            for(j = 0; j < K; j ++)
                f[i].p[j] = i & (1 << j) ? INT_MIN >> 8 : INT_MAX >> 8;

        return;
    }

    Node(Point _p)
    {
        int i;

        for(i = 0; i < (1 << K); i ++)
            f[i] = _p;

        return;
    }

    Node operator+(const Node &that) const
    {
        int i, j, s;
        Node o;

        for(i = 0; i < (1 << K); i ++)
        {
            for(j = s = 0; j < K; j ++)
                if(i & (1 << j))
                    s += this -> f[i].p[j] - that.f[i].p[j];
                else
                    s += that.f[i].p[j] - this -> f[i].p[j];
            o.f[i] = s >= 0 ? this -> f[i] : that.f[i];
        }

        return o;
    }
};

Point a[N];
Node f[N << 2];

void InitSegment(int x, int l, int r)
{
    int m;

    if(l == r)
    {
        f[x] = Node(a[l]);

        return;
    }

    m = (l + r) >> 1;
    InitSegment(x << 1    , l    , m);
    InitSegment(x << 1 | 1, m + 1, r);
    f[x] = f[x << 1] + f[x << 1 | 1];

    return;
}

void SetSegment(int x, int l, int r, int p, Point v)
{
    int m;

    if(l > p || r < p)
        return;
    if(l == r)
    {
        f[x] = Node(v);

        return;
    }

    m = (l + r) >> 1;
    SetSegment(x << 1    , l    , m, p, v);
    SetSegment(x << 1 | 1, m + 1, r, p, v);
    f[x] = f[x << 1] + f[x << 1 | 1];

    return;
}

Node GetSegment(int x, int l, int r, int s, int t)
{
    int m;

    if(l > t || r < s)
        return Node();
    if(l >= s && r <= t)
        return f[x];

    m = (l + r) >> 1;

    return GetSegment(x << 1, l, m, s, t) + GetSegment(x << 1 | 1, m + 1, r, s, t);
}

int main(void)
{
    int n, m, k;
    int i, j, p, l, r;
    Node t;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i ++)
        for(j = 0; j < k; j ++)
            scanf("%d", &a[i].p[j]);
    InitSegment(1, 0, n - 1);

    scanf("%d", &m);
    while(m --)
    {
        scanf("%d", &p);
        if(p == 1)
        {
            scanf("%d", &p);
            p --;
            for(i = 0; i < k; i ++)
                scanf("%d", &a[p].p[i]);
            SetSegment(1, 0, n - 1, p, a[p]);
        }
        else
        {
            scanf("%d %d", &l, &r);
            t = GetSegment(1, 0, n - 1, -- l, -- r);
            for(i = p = 0; i < (1 << k); i ++)
            {
                for(j = r = 0; j < k; j ++)
                    if(i & (1 << j))
                        r += t.f[i].p[j] - t.f[((1 << k) - 1) - i].p[j];
                    else
                        r += t.f[((1 << k) - 1) - i].p[j] - t.f[i].p[j];
                p = max(p, r);
            }
            printf("%d\n", p);
        }
    }

    return 0;
}