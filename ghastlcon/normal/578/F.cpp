#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define N 120
#define M 420
using namespace std;

int p;
char a[N][N];
int f[M][M], g[N * N];

inline int Mod(int x)
{
    return x + ((x >> 31) & p);
}

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % p;
        x = (long long)x * x % p;
    }

    return o;
}

int Gauss(int n)
{
    int i, j, k;
    int t, v, o;

    for(i = o = 1; i < n; i ++)
    {
        for(j = i; j < n && !f[j][i]; j ++)
            ;
        if(j == n)
            return 0;
        if(i != j)
        {
            swap(f[i], f[j]);
            o = Mod(-o);
        }

        o = (long long)o * f[i][i] % p;
        t = Power(f[i][i], p - 2);
        for(j = i + 1; j < n; j ++)
        {
            v = (long long)f[j][i] * t % p;
            for(k = i; k < n; k ++)
                f[j][k] = Mod(f[j][k] - (long long)v * f[i][k] % p);
        }
    }

    return o;
}

int GetUFS(int x)
{
    int i, t;

    for(i = x; g[i] > -1; i = g[i])
        ;
    while(x != i)
    {
        t = g[x];
        g[x] = i;
        x = t;
    }

    return i;
}

void MergeUFS(int u, int v)
{
    u = GetUFS(u);
    v = GetUFS(v);
    if(u != v)
    {
        if(g[u] > g[v])
            swap(u, v);
        g[u] += g[v];
        g[v] = u;
    }
    else
    {
        cout << 0 << endl;
        exit(0);
    }

    return;
}

void AddEdge(int u, int v, vector<int> &g)
{
    u = (int)(lower_bound(g.begin(), g.end(), GetUFS(u)) - g.begin());
    v = (int)(lower_bound(g.begin(), g.end(), GetUFS(v)) - g.begin());
    f[u][u] = Mod(f[u][u] + 1 - p);
    f[v][v] = Mod(f[v][v] + 1 - p);
    f[u][v] = Mod(f[u][v] - 1);
    f[v][u] = Mod(f[v][u] - 1);

    return;
}

int main(void)
{
    int n, m;
    int i, j, o;
    vector<int> v;

    cin >> n >> m >> p;
    memset(g, -1, sizeof(g));
    for(i = 0; i < n; i ++)
    {
        cin >> a[i];
        for(j = 0; j < m; j ++)
            if(a[i][j] == '\\')
                MergeUFS((i + 1) * (m + 1) + j + 1, i * (m + 1) + j);
            else if(a[i][j] == '/')
                MergeUFS((i + 1) * (m + 1) + j, i * (m + 1) + j + 1);
    }

    for(i = 0; i <= n; i ++)
        for(j = 0; j <= m; j ++)
            if(~(i + j) & 1)
                v.push_back(GetUFS(i * (m + 1) + j));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
            if(a[i][j] == '*' && ~(i + j) & 1 && GetUFS((i + 1) * (m + 1) + j + 1) != GetUFS(i * (m + 1) + j))
                AddEdge((i + 1) * (m + 1) + j + 1, i * (m + 1) + j, v);
            else if(a[i][j] == '*' && (i + j) & 1 && GetUFS((i + 1) * (m + 1) + j) != GetUFS(i * (m + 1) + j + 1))
                AddEdge((i + 1) * (m + 1) + j, i * (m + 1) + j + 1, v);
    o = Gauss(v.size());

    memset(f, 0, sizeof(f));
    v.clear();
    for(i = 0; i <= n; i ++)
        for(j = 0; j <= m; j ++)
            if((i + j) & 1)
                v.push_back(GetUFS(i * (m + 1) + j));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
            if(a[i][j] == '*' && ~(i + j) & 1 && GetUFS((i + 1) * (m + 1) + j) != GetUFS(i * (m + 1) + j + 1))
                AddEdge((i + 1) * (m + 1) + j, i * (m + 1) + j + 1, v);
            else if(a[i][j] == '*' && (i + j) & 1 && GetUFS((i + 1) * (m + 1) + j + 1) != GetUFS(i * (m + 1) + j))
                AddEdge((i + 1) * (m + 1) + j + 1, i * (m + 1) + j, v);

    cout << Mod(o + Gauss(v.size()) - p) << endl;

    return 0;
}