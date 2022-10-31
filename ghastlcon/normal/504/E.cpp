#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 300020
#define M 19
using namespace std;

const int M0 = 998244353, M1 = 1000000007;
const int B0 = 137, B1 = 893;
const int R0 = 276885295, R1 = 705487127;

inline int Mod0(int x)
{
    return x + ((x >> 31) & M0);
}

class Hash
{
public:
    int x;
    int y;

    Hash(int _x = 0, int _y = 0) : x(_x), y(0)
    {
        return;
    }

    Hash operator+(Hash that)
    {
        return Hash(Mod0(this -> x + that.x - M0), 0);
    }

    Hash operator-(Hash that)
    {
        return Hash(Mod0(this -> x - that.x), 0);
    }

    Hash operator*(Hash that)
    {
        return Hash((long long)this -> x * that.x % M0, 0);
    }

    bool operator==(Hash that)
    {
        return this -> x == that.x;
    }
};

char a[N];
vector<int> e[N];
Hash f[N], g[N], p[N], q[N];
int d[N], r[M][N], s[3][N];
vector<int> h[2][N];

void DFS(int x, int p)
{
    int i;

    for(i = 1, r[0][x] = p; i < M; i ++)
        r[i][x] = r[i - 1][r[i - 1][x]];

    if(x)
    {
        d[x] = d[p] + 1;
        f[x] = f[p] * Hash(B0, B1) + Hash(a[x], a[x]);
        g[x] = g[p] + ::p[d[x]] * Hash(a[x], a[x]);
    }

    s[1][x] = -1;
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != p)
        {
            DFS(e[x][i], x);
            if(s[0][e[x][i]] > s[0][x])
            {
                s[0][x] = s[0][e[x][i]];
                s[1][x] = e[x][i];
            }
        }
    s[0][x] ++;

    return;
}

void Chain(int x, int p, int t)
{
    int i, k;

    s[2][x] = t;
    if(x == t)
    {
        k = x;
        for(i = 0; i < s[0][x]; i ++)
        {
            h[1][x].push_back(k);
            k = r[0][k];
        }
    }
    h[0][t].push_back(x);
    if(s[1][x] != -1)
        Chain(s[1][x], x, t);

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != p && e[x][i] != s[1][x])
            Chain(e[x][i], x, e[x][i]);

    return;
}

int GetLCA(int u, int v)
{
    int i, t;

    if(d[u] < d[v])
        swap(u, v);
    t = d[u] - d[v];

    for(i = 0; i < M; i ++)
        if(t & (1 << i))
            u = r[i][u];
    if(u == v)
        return u;

    for(i = M - 1; i > -1; i --)
        if(r[i][u] != r[i][v])
        {
            u = r[i][u];
            v = r[i][v];
        }

    return r[0][u];
}

int KthChain(int x, int k)
{
    int y;

    if(!k)
        return x;

    x = r[31 - __builtin_clz(k)][x];
    k ^= 1 << (31 - __builtin_clz(k));
    if(!k)
        return x;

    y = s[2][x];
    if(d[x] - d[y] >= k)
        return h[0][y][d[x] - d[y] - k];

    return h[1][y][k - (d[x] - d[y])];
}

Hash Hashing(int u, int v, int w, int l)
{
    int t;

    if(l <= d[u] - d[w] + 1)
        return f[u] - f[KthChain(u, l)] * p[l];

    t = KthChain(v, d[v] - d[w] - 1);
    v = KthChain(v, d[u] + d[v] - d[w] * 2 + 1 - l);

    return f[u] - f[r[0][w]] * p[d[u] - d[w] + 1] + (g[v] - g[w]) * q[d[t]] * p[d[u] - d[w] + 1];
}

int Solve(int u, int v, int x, int y)
{
    int w, z;
    int l, m, r;

    w = GetLCA(u, v);
    z = GetLCA(x, y);
    for(l = 0, r = min(d[u] + d[v] - d[w] * 2, d[x] + d[y] - d[z] * 2) + 2; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(Hashing(u, v, w, m) == Hashing(x, y, z, m))
            l = m;
        else
            r = m;
    }

    return l;
}

int main(void)
{
    int n, m, u, v, x, y;
    int i;

    for(i = 1, p[0] = q[0] = Hash(1, 1); i < N; i ++)
    {
        p[i] = p[i - 1] * Hash(B0, B1);
        q[i] = q[i - 1] * Hash(R0, R1);
    }

    scanf("%d %s", &n, a + 1);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    e[0].push_back(1);
    DFS(0, 0);
    Chain(0, 0, 0);

    scanf("%d", &m);
    while(m --)
    {
        scanf("%d %d %d %d", &u, &v, &x, &y);
        printf("%d\n", Solve(u, v, x, y));
    }

    return 0;
}
// cnm