#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <utility>
#define N 100020
using namespace std;

class Point
{
public:
    long long x;
    long long y;
    int p;

    Point(long long _x = 0, long long _y = 0, int _p = 0) : x(_x), y(_y), p(_p)
    {
        return;
    }

    Point operator+(Point that)
    {
        return Point(this -> x + that.x, this -> y + that.y);
    }

    Point operator-(Point that)
    {
        return Point(this -> x - that.x, this -> y - that.y);
    }

    long long Dot(Point that)
    {
        return (long long)this -> x * that.x + (long long)this -> y * that.y;
    }

    long long Cross(Point that)
    {
        return (long long)this -> x * that.y - (long long)this -> y * that.x;
    }

    bool operator<(Point that) const
    {
        return this -> x != that.x ? this -> x < that.x : this -> y < that.y;
    }
};

int n, m;
int a[N];
vector<Point> f[N];
int g[2][N];
long long h[2][N];
bool u[N];

void RebuildCHT(int k)
{
    int i;
    vector<Point> o;

    f[k].clear();
    for(i = k * m; i < (k + 1) * m && i < n; i ++)
        if(!u[i])
            f[k].push_back(Point(a[i], h[0][i] - (long long)g[0][i] * a[i], i));

    sort(f[k].begin(), f[k].end());
    for(i = 0; i < (signed)f[k].size(); i ++)
    {
        for(; o.size() > 1 && (f[k][i] - o.back()).Cross(o.back() - o[o.size() - 2]) >= 0; o.pop_back())
            ;
        o.push_back(f[k][i]);
    }
    f[k] = o;

    return;
}

pair<long long, int> TangentCHT(int k)
{
    int l, m, r;

    if(f[k].empty())
        return make_pair(LLONG_MAX >> 2, -1);
    for(l = -1, r = (signed)f[k].size() - 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if((f[k][m + 1] - f[k][m]).Cross(Point(1, g[1][k])) <= 0)
            r = m;
        else
            l = m;
    }

    return make_pair(h[1][k] + f[k][r].y - (long long)g[1][k] * f[k][r].x, f[k][r].p);
}

int main(void)
{
    int i, j, p;
    long long o, s;
    pair<long long, int> v;

    scanf("%d", &n);
    m = (int)sqrt(n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    fill(g[1], g[1] + n, 1);
    for(i = 0; i <= (n - 1) / m; i ++)
        RebuildCHT(i);
    for(i = o = s = 0; i < n; i ++)
    {
        for(j = 0, v = make_pair(LLONG_MAX >> 2, -1); j <= (n - 1) / m; j ++)
            v = min(v, TangentCHT(j));
        p = v.second;
        s -= v.first;

        for(j = 0; j < p / m; j ++)
            h[1][j] -= a[p];
        for(j = p / m * m; j < p; j ++)
            h[0][j] -= a[p];
        for(j = p / m + 1; j <= (n - 1) / m; j ++)
            g[1][j] ++;
        for(j = p + 1; j < (p / m + 1) * m && j < n; j ++)
            g[0][j] ++;
        u[p] = true;
        RebuildCHT(p / m);
        // f[p] = LLONG_MIN >> 2;
        // for(j = 0; j < p; j ++)
        //     f[j] += a[p];
        // for(j = p + 1; j < n; j ++)
        //     f[j] += a[j];
        o = max(o, s);
        // printf("%d:%lld\n",i,s);
    }
    printf("%I64d\n", o);

    return 0;
}