#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 200020
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

    long long Cross(Point that)
    {
        return (long long)this -> x * that.y - (long long)this -> y * that.x;
    }
};

Point a[N];
pair<int, pair<double, double> > b[N];

bool Compare(Point a, Point b)
{
    return !a.Cross(b) ? a.y < b.y : a.Cross(b) < 0;
}

bool Check(int n, double m)
{
    int i, j, k;
    long long s, t, v;

    for(i = t = 0; i < n; i ++)
        t += a[i].x;
    for(i = s = 0; i < n; i = j)
    {
        for(j = i, v = 0; j < n && !a[i].Cross(a[j]); j ++)
            v += a[j].x;
        for(k = i; k < j; k ++)
            b[k] = make_pair(a[k].y, make_pair(a[k].y * (1 - m * (s + v) / t), a[k].y * (1 - m * (s + a[k].x) / t)));
        s += v;
    }
    // for(i=0;i<n;i++)printf("[%d,%f] ",b[i].first,b[i].second);puts("");

    sort(b, b + n);
    for(i = m = 0; i < n; i = j)
    {
        for(j = i; j < n && b[i].first == b[j].first; j ++)
            if(b[j].second.first < m)
                return false;
        for(k = i; k < j; k ++)
            m = max(m, b[k].second.second);
    }

    return true;
}

int main(void)
{
    int n;
    int i;
    double l, m, r;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i].y);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i].x);

    sort(a, a + n, Compare);
    // for(i=0;i<n;i++)printf("time=%d, val=%d (%.10f)\n",a[i].x,a[i].y,(double)a[i].y/a[i].x);
    for(l = 0, r = 1; r - l > 1e-9; )
    {
        m = (l + r) / 2;
        if(Check(n, m))
            l = m;
        else
            r = m;
    }
    printf("%.7f\n", l);

    return 0;
}