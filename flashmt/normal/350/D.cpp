#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int MAXR = 20000;

struct event
{
    long long x, y, a, b, c;
    int type;
    
    event(long long _x, long long _y, long long _a, long long _b, long long _c, int _type)
    {
        x = _x; y = _y; a = _a; b = _b; c = _c; type = _type;
    }
    
    bool operator < (event u) const
    {
        if (a != u.a) return a < u.a;
        if (b != u.b) return b < u.b;
        if (c != u.c) return c < u.c;
        if (x != u.x) return x < u.x;
        if (y != u.y) return y < u.y;
        return type < u.type;
    }
};

vector < pair <int,int> > circle[MAXR + 10];
vector <event> e;

long long gcd(long long x, long long y)
{
    return x && y ? gcd(y, x % y) : x + y;
}

void reduce(long long &a, long long &b, long long &c)
{
    long long g = gcd(gcd(a, b), c);
    a /= g; b /= g; c /= g;
}

int main()
{
    int n, m, x, y, xx, yy, r;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        x *= 2; y *= 2; xx *= 2; yy *= 2;
        if (x > xx || (x == xx && y > yy)) swap(x, xx), swap(y, yy);
        long long a = yy - y, b = x - xx, c = - a * x - b * y;
        if (a < 0) a = -a, b = -b, c = -c;
        reduce(a, b, c);
        e.push_back(event(x, y, a, b, c, -1));
        e.push_back(event(xx, yy, a, b, c, 1));
    }
    while (m--)
    {
        cin >> x >> y >> r;
        circle[r * 2].push_back(make_pair(x * 2, y * 2));
    }

    for (int r = 1; r <= MAXR; r++)
        for (int i = 0; i < int(circle[r].size()); i++) 
            for (int j = i + 1; j < int(circle[r].size()); j++)
            {
                int x = circle[r][i].first, y = circle[r][i].second;
                int xx = circle[r][j].first, yy = circle[r][j].second;
                int xm = (x + xx) / 2, ym = (y + yy) / 2;
                long long sqrDist = (1LL * x - xx) * (x - xx) + (1LL * y - yy) * (y - yy);
                
                if (sqrDist <= 4LL * r * r) continue;
                
                long long a = x - xx, b = y - yy, c = - a * xm - b * ym;
                if (a < 0) a = -a, b = -b, c = -c;
                reduce(a, b, c);
                e.push_back(event(xm, ym, a, b, c, 0));
            }
            
    long long ans = 0;
    sort(e.begin(), e.end());
    for (int i = 0, cnt = 0; i < int(e.size()); i++)
    {
        if (!i || e[i].a != e[i - 1].a || e[i].b != e[i - 1].b || e[i].c != e[i - 1].c) cnt = abs(e[i].type);
        else cnt -= e[i].type;
        if (!e[i].type) ans += cnt;
    }
                
    cout << ans << endl;
}