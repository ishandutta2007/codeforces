#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <math.h>
using namespace std;

bool sign = false;

struct NODE
{
    int x, y;
    void update(int X, int Y, int _x, int _y)
    {
        if (abs(X-_x)+abs(Y-_y)>abs(X-x)+abs(Y-y)) return;
        if (abs(X-_x)+abs(Y-_y)<abs(X-x)+abs(Y-y))
        {
            x = _x, y = _y;
            return;
        }
        if (!sign && _x>x) return;
        if (sign && _y>y) return;
        if (_x<x && !sign)
        {
            x = _x, y = _y;
            return;
        }
        if (_y<y && sign)
{
            x = _x, y = _y;
            return;
}
        if (!sign) y = min(y, _y);
        if (sign) x = min(x, _x);
    }
};

const int maxn = 2007, maxnum = 100000000;
      int n, m, k, k_sqrt;
      int L[maxn][maxn], R[maxn][maxn];

NODE count(int x, int y)
{
    NODE p;
    p.x = p.y = maxnum;
    for (int i = 0; i < n; i++)
    {
if (x-i <= 0 && x+i > n) break;
if (i > abs(p.x-x)+abs(p.y-y)) break;
        if (x-i >= 1)
{
        int l = L[x-i][y], r = R[x-i][y];
        if (l>=1) p.update(x, y, x-i, l);
        if (r<=m) p.update(x, y, x-i, r);
}
        if (i && x+i <= n)
{
        int l = L[x+i][y], r = R[x+i][y];
        if (l>=1) p.update(x, y, x+i, l);
        if (r<=m) p.update(x, y, x+i, r);
}
    }
    return p;
}

void insert(int x, int y)
{
    int l = L[x][y-1], r = R[x][y+1];
    for (int j = l; j <= r; j++)
    {
        if (L[x][j]==y) L[x][j] = l;
        if (R[x][j]==y) R[x][j] = r;
    }
}

void work()
{
sign = false;
if (n > m)
{
swap(n, m);
sign = true;
}
    for (int i = 1; i <= n; i++)
    {
        L[i][0] = 0, R[i][m+1] = m+1;
        for (int j = 1; j <= m; j++) L[i][j] = R[i][j] = j;
    }
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
if (sign) swap(x, y);
        NODE p = count(x, y); 
        insert(p.x, p.y);
if (sign) swap(p.x, p.y);
        printf("%d %d\n", p.x, p.y);
    }
}

int main()
{
    while (scanf("%d%d%d", &n, &m, &k)!=EOF) work();
}