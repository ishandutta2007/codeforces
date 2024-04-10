#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5
int n;
struct HEHE
{
    int x, y, f, num;
}h[N];

bool cmp1(HEHE u, HEHE v)
{
    return u.x < v.x;
}

bool cmp2(HEHE u, HEHE v)
{
    return u.num < v.num;
}

int Search(int l, int r, int y, int op)
{
    if (l == r) return l;
    int mid = l + r + op >> 1;
    if (op == 1)
    {
        if (h[mid].x >= y) return Search(l, mid - 1, y, op);
        else return Search(mid, r, y, op);
    }
    else
    {
        if (h[mid].x <= y) return Search(mid + 1, r, y, op);
        else return Search(l, mid, y, op);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d", &h[i].x, &h[i].y);
        h[i].num = i;
    }
    sort(h + 1, h + n + 1, cmp1);
    for (int i = 1; i <= n; i ++)
    {
        int u = Search(1, n, h[i].y, 1);
        if (u == 1 && h[1].x >= h[i].y) u --;
        int v = Search(1, n, h[i].y, 0);
        if (v == n && h[n].x <= h[i].y) v ++;
        h[i].f = v - u - 1;
    }
    sort(h + 1, h + n + 1, cmp2);
    for (int i = 1; i <= n; i ++)
        printf("%d %d\n", n - 1 + h[i].f, n - 1 - h[i].f);
    return 0;
}