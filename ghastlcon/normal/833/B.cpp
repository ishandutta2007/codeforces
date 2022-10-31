#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 35020
#define M 60
#pragma GCC optimize("O3")
using namespace std;

class Node
{
public:
    Node *s[2];
    int v;

    Node(int _v = 0) : v(_v)
    {
        s[0] = s[1] = NULL;

        return;
    }
};

int n;
int a[N], b[N], c[N];
Node *r[N];
int f[M][N];

void InsertChairman(Node *&x, Node *k, int l, int r, int p)
{
    int m;

    if(l == r)
    {
        x = new Node((k ? k -> v : 0) + 1);

        return;
    }

    m = (l + r) >> 1;
    x = new Node();
    if(p <= m)
    {
        InsertChairman(x -> s[0], k -> s[0], l, m, p);
        x -> s[1] = k -> s[1];
    }
    else
    {
        InsertChairman(x -> s[1], k -> s[1], m + 1, r, p);
        x -> s[0] = k -> s[0];
    }
    x -> v = x -> s[0] -> v + x -> s[1] -> v;

    return;
}

int SumChairman(Node *x, int l, int r, int s, int t)
{
    int m;

    if(x == ::r[0] || l > t || r < s)
        return 0;
    if(l >= s && r <= t)
        return x -> v;

    m = (l + r) >> 1;

    return SumChairman(x -> s[0], l, m, s, t) + SumChairman(x -> s[1], m + 1, r, s, t);
}

void CDQ(int x, int l, int r, int s, int t)
{
    int i, m, v, k;
    int p, q;

    if(l > r)
        return;
    if(l == r)
    {
        v = SumChairman(::r[l], 1, n + 1, l + 1, n + 1);
        for(i = s; i <= min(t, l); i ++)
            f[x][l] = max(f[x][l], f[x - 1][i - 1] + v - SumChairman(::r[i - 1], 1, n + 1, l + 1, n + 1));

        return;
    }

    m = (l + r) >> 1;
    v = SumChairman(::r[m], 1, n + 1, m + 1, n + 1);
    for(i = s, p = q = -1; i <= min(t, m); i ++)
        if(p < (k = f[x - 1][i - 1] + v - SumChairman(::r[i - 1], 1, n + 1, m + 1, n + 1)))
        {
            p = k;
            q = i;
        }
    if(p == -1)
        throw;

    f[x][m] = p;
    CDQ(x, l    , m - 1, s, q);
    CDQ(x, m + 1, r    , q, t);

    return;
}

int main(void)
{
    int m;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        b[i] = n + 1;
    }
    for(i = n; i >= 1; i --)
    {
        c[i] = b[a[i]];
        b[a[i]] = i;
    }
    // for(i=1;i<=n;i++)cout<<c[i]<<' ';cout<<endl;

    r[0] = new Node();
    r[0] -> s[0] = r[0] -> s[1] = r[0];
    for(i = 1; i <= n; i ++)
        InsertChairman(r[i], r[i - 1], 1, n + 1, c[i]);
    // while(1){int a,b;cin>>a>>b;cout<<Count(a,b)<<endl;}

    for(i = 1; i <= n; i ++)
        f[1][i] = SumChairman(r[i], 1, n + 1, i + 1, n + 1);
    for(i = 2; i <= m; i ++)
        CDQ(i, 1, n, 1, n);
    printf("%d\n", f[m][n]);

    return 0;
}