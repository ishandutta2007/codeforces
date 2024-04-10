#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 300020
using namespace std;

class Node
{
public:
    pair<int, int> x;
    pair<int, int> y;
    int a;

    Node(void)
    {
        return;
    }

    Node operator+(Node that)
    {
        Node o;

        if(this -> x.first == that.x.first)
        {
            o.x = this -> x;
            o.x.second += that.x.second;
            if(this -> y.first == that.y.first)
            {
                o.y = this -> y;
                o.y.second += that.y.second;
            }
            else
                o.y = min(this -> y, that.y);
        }
        else if(this -> x.first < that.x.first)
        {
            o.x = this -> x;
            if(this -> y.first == that.x.first)
            {
                o.y = this -> y;
                o.y.second += that.x.second;
            }
            else
                o.y = min(this -> y, that.x);
        }
        else
        {
            o.x = that.x;
            if(this -> x.first == that.y.first)
            {
                o.y = this -> x;
                o.y.second += that.y.second;
            }
            else
                o.y = min(this -> x, that.y);
        }
        o.a = 0;

        return o;
    }
};

int a[N], b[N];
Node f[N << 2];

void MaintainSegment(int x)
{
    f[x << 1].x.first += f[x].a;
    f[x << 1].y.first += f[x].a;
    f[x << 1].a += f[x].a;
    f[x << 1 | 1].x.first += f[x].a;
    f[x << 1 | 1].y.first += f[x].a;
    f[x << 1 | 1].a += f[x].a;
    f[x].a = 0;

    return;
}

void InitSegment(int x, int l, int r)
{
    int m;

    if(l == r)
    {
        f[x].x.second = 1;
        f[x].y.first = N;

        return;
    }

    m = (l + r) >> 1;
    InitSegment(x << 1    , l    , m);
    InitSegment(x << 1 | 1, m + 1, r);
    f[x] = f[x << 1] + f[x << 1 | 1];

    return;
}

void AddSegment(int x, int l, int r, int s, int t, int v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        f[x].a += v;
        f[x].x.first += v;
        f[x].y.first += v;

        return;
    }
    if(f[x].a)
        MaintainSegment(x);

    m = (l + r) >> 1;
    AddSegment(x << 1    , l    , m, s, t, v);
    AddSegment(x << 1 | 1, m + 1, r, s, t, v);
    f[x] = f[x << 1] + f[x << 1 | 1];

    return;
}

Node GetSegment(int x, int l, int r, int s, int t)
{
    int m;

    if(l >= s && r <= t)
        return f[x];
    if(f[x].a)
        MaintainSegment(x);

    m = (l + r) >> 1;
    if(t <= m)
        return GetSegment(x << 1    , l    , m, s, t);
    if(s >  m)
        return GetSegment(x << 1 | 1, m + 1, r, s, t);

    return GetSegment(x << 1, l, m, s, t) + GetSegment(x << 1 | 1, m + 1, r, s, t);
}

int main(void)
{
    int n;
    int i;
    long long o;
    Node v;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }

    InitSegment(1, 1, n);
    for(i = 1, o = 0; i <= n; i ++)
    {
        AddSegment(1, 1, n, 1, i, 1);
        if(b[i] != 1 && a[b[i] - 1] < i)
            AddSegment(1, 1, n, 1, a[b[i] - 1], -1);
        if(b[i] != n && a[b[i] + 1] < i)
            AddSegment(1, 1, n, 1, a[b[i] + 1], -1);   

        if(i != 1)
        {
            v = GetSegment(1, 1, n, 1, i - 1);
            if(v.x.first <= 2)
            {
                // printf("%d : X %d blocks, count %d\n", i, v.x.first, v.x.second);
                if(v.x.first <= 0)
                    throw;
                o += v.x.second;
            }
            if(v.y.first <= 2)
            {
                // printf("%d : Y %d blocks, count %d\n", i, v.y.first, v.y.second);
                if(v.y.first <= 0)
                    throw;
                o += v.y.second;
            }
        }
    }
    printf("%I64d\n", o);

    return 0;
}