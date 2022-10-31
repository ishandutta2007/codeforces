#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
using namespace std;

class Point
{
public:
    long long x;
    long long y;

    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y)
    {
        return;
    }

    Point operator-(Point that)
    {
        return Point(this -> x - that.x, this -> y - that.y);
    }

    long long Cross(Point that)
    {
        return this -> x * that.y - this -> y * that.x;
    }
};

int a[N];
long long s[N];
Point f[N];

long long BSFind0(int c, int v)
{
    int l, m, r;

    if(c == 1)
        return (long long)v * f[0].x - f[0].y;
    for(l = 1, r = c; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if((f[m] - f[m - 1]).Cross(Point(1, v)) >= 0)
            l = m;
        else
            r = m;
    }

    return max((long long)v * f[0].x - f[0].y, (long long)v * f[l].x - f[l].y);
}

long long BSFind1(int c, int v)
{
    int l, m, r;

    if(c == 1)
        return (long long)v * f[0].x - f[0].y;
    for(l = 1, r = c; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if((f[m] - f[m - 1]).Cross(Point(-1, -v)) <= 0)
            l = m;
        else
            r = m;
    }

    return max((long long)v * f[0].x - f[0].y, (long long)v * f[l].x - f[l].y);
}

int main(void)
{
    int n;
    int i, c;
    long long o;

    scanf("%d", &n);
    for(i = 1, o = 0; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    c = 0;
    f[c ++] = Point(0, 0);
    for(i = 1; i <= n; i ++)
    {
        o = max(o, s[i] - (long long)i * a[i] + BSFind0(c, a[i]));
        while(c > 1 && (Point(i, s[i]) - f[c - 1]).Cross(f[c - 2] - f[c - 1]) <= 0)
            c --;
        f[c ++] = Point(i, s[i]);
    }

    c = 0;
    f[c ++] = Point(n + 1, s[n]);
    for(i = n; i >= 1; i --)
    {
        o = max(o, s[i - 1] - (long long)i * a[i] + BSFind1(c, a[i]));
        while(c > 1 && (Point(i, s[i - 1]) - f[c - 1]).Cross(f[c - 2] - f[c - 1]) >= 0)
            c --;
        f[c ++] = Point(i, s[i - 1]);
    }
    // cout<<o<<endl;

    for(i = 1; i <= n; i ++)
        o += (long long)i * a[i];
    printf("%I64d\n", o);

    return 0;
}