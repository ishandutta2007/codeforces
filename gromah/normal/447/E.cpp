#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define M 1048576 + 5
#define Mod 1000000009
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m, A[N];

struct Segment_Tree
{
    int sum, da, db;
}h[M];

inline int Inc(int a, int b)
{
    return a + b - (a + b >= Mod ? Mod : 0);
}

struct Rec
{
    int r, c, num[3][3];
    inline Rec operator * (const Rec a)
    {
        Rec b;
        b.r = r, b.c = a.c;
        for (int i = 0; i < b.r; i ++)
            for (int j = 0; j < b.c; j ++)
            {
                b.num[i][j] = 0;
                for (int k = 0; k < c; k ++)
                    b.num[i][j] = Inc(b.num[i][j], (LL) num[i][k] * a.num[k][j] % Mod);
            }
        return b;
    }
}f, g, Mul[N];

inline void Calc(int a, int b, int t)
{
    f.r = 1, f.c = 3;
    f.num[0][0] = a, f.num[0][1] = b, f.num[0][2] = 0;
    f = f * Mul[t];
}

inline void Prepare()
{
    g.r = g.c = 3;
    g.num[1][0] = g.num[0][1] = g.num[1][1] = g.num[0][2] = g.num[2][2] = 1;
    Mul[0].r = Mul[0].c = 3;
    Mul[0].num[0][0] = Mul[0].num[1][1] = Mul[0].num[2][2] = 1;
    for (int i = 1; i <= n; i ++)
    {
        Mul[i] = Mul[i - 1] * g;
        scanf("%d", A + i);
    }
}

inline void update(int x)
{
    h[x].sum = Inc(h[ls(x)].sum, h[rs(x)].sum);
}

inline void Build(int x, int l, int r)
{
    if (l == r)
    {
        h[x].sum = A[l];
        return ;
    }
    int mid = l + r >> 1;
    Build(ls(x), l, mid);
    Build(rs(x), mid + 1, r);
    update(x);
}

inline void apply(int x, int l, int r, int a, int b)
{
    h[x].da = Inc(h[x].da, a);
    h[x].db = Inc(h[x].db, b);
    Calc(a, b, r + 1 - l);
    h[x].sum = Inc(h[x].sum, f.num[0][2]);
}

inline void push(int x, int l, int r)
{
    if (h[x].da || h[x].db)
    {
        int mid = l + r >> 1;
        apply(ls(x), l, mid, h[x].da, h[x].db);
        Calc(h[x].da, h[x].db, mid + 1 - l);
        apply(rs(x), mid + 1, r, f.num[0][0], f.num[0][1]);
        h[x].da = h[x].db = 0;
    }
}

inline void Modify(int x, int l, int r, int s, int t, int a, int b)
{
    if (l == s && r == t)
    {
        apply(x, l, r, a, b);
        return ;
    }
    push(x, l, r);
    int mid = l + r >> 1;
    if (t <= mid) Modify(ls(x), l, mid, s, t, a, b);
    else if (s > mid) Modify(rs(x), mid + 1, r, s, t, a, b);
    else
    {
        Modify(ls(x), l, mid, s, mid, a, b);
        Calc(a, b, mid + 1 - s);
        Modify(rs(x), mid + 1, r, mid + 1, t, f.num[0][0], f.num[0][1]);
    }
    update(x);
}

inline int Query(int x, int l, int r, int s, int t)
{
    if (l == s && r == t)
        return h[x].sum;
    push(x, l, r);
    int mid = l + r >> 1;
    if (t <= mid) return Query(ls(x), l, mid, s, t);
    else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
    else return Inc(Query(ls(x), l, mid, s, mid), Query(rs(x), mid + 1, r, mid + 1, t));
}

int main()
{
    scanf("%d%d", &n, &m);
    Prepare();
    Build(1, 1, n);
    while (m --)
    {
        int op, u, v;
        scanf("%d%d%d", &op, &u, &v);
        if (op == 1)
            Modify(1, 1, n, u, v, 1, 1);
        else printf("%d\n", Query(1, 1, n, u, v));
    }
    
//    while (1) ;
    return 0;
}