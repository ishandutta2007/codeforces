#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 1000020
#pragma GCC optimize("O3")
using namespace std;
 
class Node
{
public:
    int v;
    int a;
 
    Node(int _v = 0) : v(_v), a(0)
    {
        return;
    }
};
 
int a[N + 20], b[N + 20];
Node f[(N + 20) << 2];
 
void MaintainSegment(int x)
{
    f[x << 1    ].v += f[x].a;
    f[x << 1    ].a += f[x].a;
    f[x << 1 | 1].v += f[x].a;
    f[x << 1 | 1].a += f[x].a;
    f[x].a = 0;
 
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
        f[x].v += v;
 
        return;
    }
    if(f[x].a)
        MaintainSegment(x);
 
    m = (l + r) >> 1;
    AddSegment(x << 1    , l    , m, s, t, v);
    AddSegment(x << 1 | 1, m + 1, r, s, t, v);
    f[x].v = min(f[x << 1].v, f[x << 1 | 1].v);
 
    return;
}
 
int FindSegment(int x, int l, int r)
{
    int m;
 
    if(l == r)
        return l;
    if(f[x].a)
        MaintainSegment(x);
 
    m = (l + r) >> 1;
    if(f[x << 1].v < 0)
        return FindSegment(x << 1, l, m);
 
    return FindSegment(x << 1 | 1, m + 1, r);
}
 
int main(void)
{
    int n, m, q, p, x;
    int i;
 
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        AddSegment(1, 1, N, N - a[i], N, -1);
    }
    for(i = 1; i <= m; i ++)
    {
        scanf("%d", &b[i]);
        AddSegment(1, 1, N, N - b[i], N,  1);
    }

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d", &p);
        if(p == 1)
        {
            scanf("%d %d", &p, &x);
            AddSegment(1, 1, N, N - a[p], N, 1);
            AddSegment(1, 1, N, N - (a[p] = x), N, -1);
        }
        else
        {
            scanf("%d %d", &p, &x);
            AddSegment(1, 1, N, N - b[p], N, -1);
            AddSegment(1, 1, N, N - (b[p] = x), N, 1);
        }
 
        x = N - FindSegment(1, 1, N);
        printf("%d\n", !x ? -1 : x);
    }
 
    return 0;
}