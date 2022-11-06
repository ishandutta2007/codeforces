#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 10000 + 5
#define K 1000000 + 5
#define INF 0x7fffffff
int n, m, k, p;
LL ans, S[2][N], h[2][N * 5], D[2][N * 5], f[2][K];

void update(int op, int x)
{
    h[op][x] = max(h[op][x << 1], h[op][x << 1 | 1]);
}

void Build(int op, int x, int l, int r)
{
    if (l == r)
    {
        h[op][x] = S[op][l];
        return ;
    }
    int mid = l + r >> 1;
    Build(op, x << 1, l, mid);
    Build(op, x << 1 | 1, mid + 1, r);
    update(op, x);
}

void begin()
{
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            int t;
            scanf("%d", &t);
            S[0][i] += t, S[1][j] += t;
        }
    Build(0, 1, 1, n);
    Build(1, 1, 1, m);
}

void apply(int op, int x, int l, int r, int d)
{
    h[op][x] += d;
    D[op][x] += d;
}

void push(int op, int x, int l, int r)
{
    if (D[op][x])
    {
        int mid = l + r >> 1;
        apply(op, x << 1, l, mid, D[op][x]);
        apply(op, x << 1 | 1, mid + 1, r, D[op][x]);
        D[op][x] = 0;
    }
}

void Modify(int op, int x, int l, int r, int s, int t, int d)
{
    if (l == s && r == t)
    {
        apply(op, x, l, r, d);
        return ;
    }
    push(op, x, l, r);
    int mid = l + r >> 1;
    if (t <= mid) Modify(op, x << 1, l, mid, s, t, d);
    else if (s > mid) Modify(op, x << 1 | 1, mid + 1, r, s, t, d);
    else Modify(op, x << 1, l, mid, s, mid, d), Modify(op, x << 1 | 1, mid + 1, r, mid + 1, t, d);
    update(op, x);
}

int Query(int op, int x, int l, int r)
{
    if (l == r) return l;
    push(op, x, l, r);
    int mid = l + r >> 1;
    if (h[op][x << 1] >= h[op][x << 1 | 1])
        return Query(op, x << 1, l, mid);
    else return Query(op, x << 1 | 1, mid + 1, r);
}

void work()
{
    for (int i = 1; i <= k; i ++)
    {
        f[0][i] = f[0][i - 1] + h[0][1];
        f[1][i] = f[1][i - 1] + h[1][1];
        int q0 = Query(0, 1, 1, n);
        int q1 = Query(1, 1, 1, m);
        Modify(0, 1, 1, n, q0, q0, -p * m);
        Modify(1, 1, 1, m, q1, q1, -p * n);
    }
    ans = (LL) -INF * INF;
    for (int i = 0; i <= k; i ++)
        ans = max(ans, f[0][i] + f[1][k - i] - (LL) i * (k - i) * p);
}

void end()
{
    cout << ans << endl;
}

int main()
{
    begin();
    work();
    end();
    return 0;
}