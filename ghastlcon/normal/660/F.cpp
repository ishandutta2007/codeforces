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

long long a[N];
long long s[N];
Point f[N];

long long BSFind(int c, long long v)
{
    int l, m, r;

    if(c == 1)
        return v * f[0].x - f[0].y;
    for(l = 1, r = c; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if((f[m] - f[m - 1]).Cross(Point(1, v)) >= 0)
            l = m;
        else
            r = m;
    }

    return max(v * f[0].x - f[0].y, (long long)v * f[l].x - f[l].y);
}

int main(void)
{
    int n;
    int i, c;
    long long o;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%I64d", &a[i]);
    for(i = n; i >= 1; i --)
        a[i] += a[i + 1];
    for(i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];

    c = 0;
    f[c ++] = Point(0, 0);
    for(i = 1, o = 0; i <= n; i ++)
    {
        o = max(o, s[i] - i * a[i + 1] + BSFind(c, a[i + 1]));
        while(c > 1 && (Point(i, s[i]) - f[c - 1]).Cross(f[c - 2] - f[c - 1]) <= 0)
            c --;
        f[c ++] = Point(i, s[i]);
    }
    printf("%I64d\n", o);

    return 0;
}