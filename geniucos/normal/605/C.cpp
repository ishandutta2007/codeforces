#include<iomanip>
#include<fstream>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int nr, N, X, Y, st[100009];

struct point
{
    int x, y;
    bool operator < (const point &other) const
    {
        if (x == other.x) return y > other.y;
        return x < other.x;
    }
    point ()
    {
        x = y = 0;
    }
    point (int x, int y)
    {
        this->x = x;
        this->y = y;
    }
}O, P, a[100009];

long long Det (point a, point b, point c)
{
    return 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * a.x * c.y - 1LL * b.x * a.y - 1LL * c.x * b.y;
}

int sg (point a, point b, point c)
{
    long long val = Det (a, b, c);
    if (val < 0) return -1;
    if (val == 0) return 0;
    return 1;
}

void Get (point p1, point p2, long long &a, long long &b, long long &c)
{
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = 1LL * p1.x * p2.y - 1LL * p2.x * p1.y;
}

bool Cross (point p1, point p2)
{
    return (sg (O, p1, P) * sg (O, p2, P) <= 0);
}

long double Time (point p1, point p2, int X, int Y)
{
    long double alpha = (long double) X / Y, y;
    long long a, b, c;
    Get (p1, p2, a, b, c);
    y = (long double) -c / ((long double) alpha * a + b);
    return (long double) Y / y;
}

int main()
{
//freopen ("input", "r", stdin);
//ofstream cout ("output");
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &X, &Y), P = point (X, Y), O = point (0, 0);
int maxx = 0, maxy = 0;
for (int i=1; i<=N; i++)
{
    int xp, yp;
    scanf ("%d %d", &xp, &yp);
    if (xp > maxx) maxx = xp;
    if (yp > maxy) maxy = yp;
    a[i] = point (xp, yp);
}
a[++N] = point (maxx, 0);
a[++N] = point (0, maxy);
sort (a + 1, a + N + 1), nr = 0;
for (int i=1; i<=N; i++)
{
    while (nr >= 2 && Det (a[st[nr - 1]], a[st[nr]], a[i]) >= 0) nr --;
    st[++nr] = i;
}
for (int i=1; i<nr; i++)
{
    point p1 = a[st[i]], p2 = a[st[i + 1]];
    if (Cross (p1, p2))
    {
        long double curr = Time (p1, p2, X, Y);
        cout << fixed << setprecision (15) << curr << '\n';
        return 0;
    }
}
return 0;
}