#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int ans;

struct Point
{
    int x, y, a, b;
    Point (int _x = 0, int _y = 0, int _a = 0, int _b = 0)
    {
        x = _x;
        y = _y;
        a = _a;
        b = _b;
    }
    Point rotate()
    {
        int _x = a - (y - b);
        int _y = b + (x - a);
        return Point(_x, _y, a, b);
    }
    bool operator == (const Point u) const
    {
        return (x == u.x && y == u.y);
    }
}P[9];

inline int Cross(Point s1, Point t1, Point s2, Point t2)
{
    int x1 = t1.x - s1.x, y1 = t1.y - s1.y;
    int x2 = t2.x - s2.x, y2 = t2.y - s2.y;
    return x1 * y2 - x2 * y1;
}

inline int Multi(Point s1, Point t1, Point s2, Point t2)
{
    int x1 = t1.x - s1.x, y1 = t1.y - s1.y;
    int x2 = t2.x - s2.x, y2 = t2.y - s2.y;
    return x1 * x2 + y1 * y2;
}

inline int dis(Point u, Point v)
{
    int _x = u.x - v.x, _y = u.y - v.y;
    return _x * _x + _y * _y;
}

inline bool Judge()
{
    if (P[1] == P[2] || P[1] == P[3] || P[1] == P[4])
        return 0;
    int _2 = 2, _3 = 3, _4 = 4;
    if (Cross(P[1], P[2], P[3], P[4]))
        swap(_2, _3);
    else if (Cross(P[1], P[4], P[2], P[3]))
        swap(_3, _4);
    if (!Cross(P[1], P[_2], P[_3], P[_4]) && !Cross(P[1], P[_4], P[_2], P[_3]) && !Multi(P[1], P[_2], P[1], P[_4]) && dis(P[1], P[_2]) == dis(P[1], P[_4]))
        return 1;
    return 0;
}

inline void dfs(int z, int step)
{
    if (step >= ans)
        return ;
    if (z > 4)
    {
        if (Judge())
            ans = min(ans, step);
        return ;
    }
    for (int i = 0; i < 4; i ++)
    {
        dfs(z + 1, step + i);
        P[z] = P[z].rotate();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
    {
        for (int i = 1; i <= 4; i ++)
        {
            int x, y, a, b;
            scanf("%d%d%d%d", &x, &y, &a, &b);
            P[i] = Point(x, y, a, b);
        }
        ans = 100;
        dfs(1, 0);
        ans = ans == 100 ? -1 : ans;
        printf("%d\n", ans);
    }
    return 0;
}