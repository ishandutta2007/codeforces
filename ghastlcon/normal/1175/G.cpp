#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <deque>
#include <utility>
#define N 20002
#define K 102
#define M 15
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y)
    {
        return;
    }

    Point operator-(Point that)
    {
        return Point(this -> x - that.x, this -> y - that.y);
    }

    long long Cross(Point that)
    {
        return (long long)this -> x * that.y - (long long)this -> y * that.x;
    }

    int Eval(int p)
    {
        return x * p + y;
    }
};

int n, f[K][N];
pair<int, int> q[M][N];
deque<Point> g[N << 1];
Point h[N << 2];

void InitSegment(int x, int l, int r)
{
    int m;

    h[x] = Point(0, INT_MAX >> 2);
    if(l == r)
        return;

    m = (l + r) >> 1;
    InitSegment(x << 1    , l    , m);
    InitSegment(x << 1 | 1, m + 1, r);

    return;
}

void InsertSegment(int x, int l, int r, int s, int t, Point v)
{
    int m, p[3], q[3];

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        m = (l + r) >> 1;
        p[0] = v.Eval(l);
        p[1] = v.Eval(r);
        p[2] = v.Eval(m);
        q[0] = h[x].Eval(l);
        q[1] = h[x].Eval(r);
        q[2] = h[x].Eval(m);

        if(l == r)
        {
            if(p[0] <= q[0])
                h[x] = v;
        }
        else
        {
            if(p[0] <= q[0] && p[1] <= q[1])
            {
                h[x] = v;

                return;
            }
            if(p[0] > q[0] && p[1] > q[1])
                return;

            if(p[0] <= q[0])
                if(p[2] <= q[2])
                {
                    InsertSegment(x << 1 | 1, m + 1, r, s, t, h[x]);
                    h[x] = v;
                }
                else
                    InsertSegment(x << 1, l, m, s, t, v);
            else
                if(p[2] <= q[2])
                {
                    InsertSegment(x << 1, l, m, s, t, h[x]);
                    h[x] = v;
                }
                else
                    InsertSegment(x << 1 | 1, m + 1, r, s, t, v);
        }

        return;
    }

    m = (l + r) >> 1;
    InsertSegment(x << 1    , l    , m, s, t, v);
    InsertSegment(x << 1 | 1, m + 1, r, s, t, v);

    return;
}

int MinSegment(int x, int l, int r, int p)
{
    int m, o;

    // printf("dfs to %d %d-%d\n", x, l, r);
    if(l > p || r < p)
        return INT_MAX >> 2;

    o = h[x].Eval(p);
    if(l == r)
        return o;

    m = (l + r) >> 1;
    o = min(o, min(MinSegment(x << 1, l, m, p), MinSegment(x << 1 | 1, m + 1, r, p)));

    return o;
}

Point Tangent(deque<Point> &f, Point v)
{
    int l, m, r;

    for(l = -1, r = (signed)f.size() - 1; l + 1 < r; )
    {
        m = (l + r) / 2;
        if((f[m + 1] - f[m]).Cross(v) > 0)
            l = m;
        else
            r = m;
    }

    return f[r];
}

int MaxRMQ(int l, int r)
{
    int t;

    t = 31 - __builtin_clz(r - l + 1);

    return max(q[t][l], q[t][r - (1 << t) + 1]).second;
}

int DP(int &c, int l, int r, int *f)
{
    int m;
    Point t;
    deque<Point> p, q;

    if(l == r)
    {
        g[c].clear();
        g[c].push_back(Point(l, f[l]));

        return c ++;
    }

    m = MaxRMQ(l + 1, r);
    p.swap(g[DP(c, l, m - 1, f)]);
    t = Tangent(p, Point(1, ::q[0][m].first));
    InsertSegment(1, 0, n, m, r, Point(::q[0][m].first, t.y - t.x * ::q[0][m].first));
    q.swap(g[DP(c, m, r    , f)]);

    if(p.size() > q.size())
    {
        for(; !q.empty(); q.pop_front())
        {
            for(; p.size() > 1 && (p.back() - p[p.size() - 2]).Cross(q.front() - p.back()) < 0; p.pop_back())
                ;
            p.push_back(q.front());
        }
        g[c].swap(p);
    }
    else
    {
        for(; !p.empty(); p.pop_back())
        {
            for(; q.size() > 1 && (q.front() - q[1]).Cross(p.back() - q.front()) > 0; q.pop_front())
                ;
            q.push_front(p.back());
        }
        g[c].swap(q);
    }

    return c ++;
}

int main(void)
{
    int k;
    int i, j, c;

    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &q[0][i].first);
        q[0][i].second = i;
    }
    for(i = 1; i < M; i ++)
        for(j = 1; j + (1 << i) - 1 <= n; j ++)
            q[i][j] = max(q[i - 1][j], q[i - 1][j + (1 << (i - 1))]);

    fill(f[0] + 1, f[0] + N, INT_MAX >> 2);
    for(i = 1; i <= k; i ++)
    {
        InitSegment(1, 0, n);
        DP(c = 0, 0, n, f[i - 1]);
        for(j = 0; j <= n; j ++)
            f[i][j] = MinSegment(1, 0, n, j);
    }
    printf("%d\n", f[k][n]);

    return 0;
}