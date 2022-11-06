#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 600000 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, T, size, L[N], R[N], q[N];
LL Ans[N];

struct Querys
{
    int l, r, id;
    Querys (int _l = 0, int _r = 0, int _id = 0) {l = _l, r = _r, id = _id;}
    bool operator < (const Querys a) const
    {
        return r < a.r;
    }
}Ask[N];

struct Segment_Tree
{
    LL num, delta;
}h[M];

inline void apply(int x, int d)
{
    h[x].num += d;
    h[x].delta += d;
}

inline void push(int x)
{
    if (h[x].delta)
    {
        apply(ls(x), h[x].delta);
        apply(rs(x), h[x].delta);
        h[x].delta = 0;
    }
}

inline void Modify(int x, int l, int r, int s, int t, int d)
{
    if (l == s && r == t)
    {
        apply(x, d);
        return ;
    }
    push(x);
    int mid = l + r >> 1;
    if (t <= mid)
        Modify(ls(x), l, mid, s, t, d);
    else if (s > mid)
        Modify(rs(x), mid + 1, r, s, t, d);
    else Modify(ls(x), l, mid, s, mid, d), Modify(rs(x), mid + 1, r, mid + 1, t, d);
}

inline LL Query(int x, int l, int r, int t)
{
    if (l == r)
        return h[x].num;
    push(x);
    int mid = l + r >> 1;
    if (t <= mid)
        return Query(ls(x), l, mid, t);
    else return Query(rs(x), mid + 1, r, t);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d", L + i, R + i);
        R[i] += L[i];
    }
    scanf("%d", &T);
    for (int i = 1; i <= T; i ++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        Ask[i] = Querys(l, r, i);
    }
    sort(Ask + 1, Ask + T + 1);
    
    int t = 1;
    for (int i = 1; i <= n; i ++)
    {
        for (; R[q[size]] <= R[i] && size; size --)
            if (R[q[size]] < L[i])
                Modify(1, 1, n, q[size - 1] + 1, q[size], L[i] - R[q[size]]);
        q[++ size] = i;
        while (Ask[t].r == i && t <= T)
        {
            Ans[Ask[t].id] = Query(1, 1, n, Ask[t].l);
            t ++;
        }
    }
    for (int i = 1; i <= T; i ++)
        printf("%I64d\n", Ans[i]);
    
    return 0;
}