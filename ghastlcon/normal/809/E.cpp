#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 200020
#define M 18
#define MOD 1000000007
using namespace std;

namespace Sieve
{
    int p[N], c;
    bool u[N];
    int f[N], g[N];

    int Power(int x, int y)
    {
        int o;

        for(o = 1; y; y >>= 1)
        {
            if(y & 1)
                o = (long long)o * x % MOD;
            x = (long long)x * x % MOD;
        }

        return o;
    }

    void Sieve(void)
    {
        int i, j;

        f[1] = g[1] = 1;
        for(i = 2; i < N; i ++)
        {
            if(!u[i])
            {
                p[c ++] = i;
                f[i] = i - 1;
                g[i] = -1;
            }

            for(j = 0; j < c && i * p[j] < N; j ++)
            {
                u[i * p[j]] = true;
                if(!(i % p[j]))
                {
                    f[i * p[j]] = f[i] * p[j];
                    g[i * p[j]] = 0;
                    break;
                }
                f[i * p[j]] = f[i] * (p[j] - 1);
                g[i * p[j]] = -g[i];
            }
        }

        return;
    }
}

extern int a[N];
extern int d[N];

namespace Tree
{
    vector<int> e[N];
    bool b[N];
    int s[2][N];

    int DFS(int x)
    {
        int i, o;

        s[0][x] = s[1][x] = 0;
        for(i = o = 0; i < (signed)e[x].size(); i ++)
        {
            o = (o + DFS(e[x].at(i))) % MOD;
            o = (o + (long long)s[0][x] * s[0][e[x].at(i)] % MOD * d[x] % MOD * 2) % MOD;
            if(b[x])
                o = (o + (long long)s[0][e[x].at(i)] * Sieve::f[a[x]] % MOD * d[x] % MOD * 2) % MOD;
            s[0][x] = (s[0][x] + s[0][e[x].at(i)]) % MOD;
            s[1][x] = (s[1][x] + s[1][e[x].at(i)]) % MOD;
        }
        if(b[x])
        {
            o = (o + (long long)Sieve::f[a[x]] * Sieve::f[a[x]] % MOD * d[x] % MOD) % MOD;
            s[0][x] = (s[0][x] + Sieve::f[a[x]]) % MOD;
            s[1][x] = (s[1][x] + (long long)Sieve::f[a[x]] * d[x] % MOD) % MOD;
        }

        // printf("dfs to %d %lld %lld\n", x, s[0][x], s[1][x]);

        return o;
    }

    int Solve(vector<int> &s)
    {
        int i, o;

        o = -2 * DFS(0) % MOD;
        // printf("sigma %lld\n", o);
        // for(int x:s)cout<<x+1<<' ';cout<<endl;
        for(i = 0; i < (signed)s.size(); i ++)
            if(b[s.at(i)])
            {
                o = (o + (long long)Sieve::f[a[s.at(i)]] * d[s.at(i)] % MOD * Tree::s[0][0] % MOD) % MOD;
                o = (o + (long long)Sieve::f[a[s.at(i)]] * Tree::s[1][0] % MOD) % MOD;
            }

        return o;
    }
}

int a[N];
vector<int> c[N], e[N];
int f[M][N], d[N], l[N];
vector<int> s;
int o[N];

bool Compare(int a, int b)
{
    return l[a] < l[b];
}

void DFS(int x, int p)
{
    static int k;
    int i;

    l[x] = k ++;
    for(i = 1, f[0][x] = p; i < M; i ++)
        f[i][x] = f[i - 1][f[i - 1][x]];

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            d[e[x].at(i)] = d[x] + 1;
            DFS(e[x].at(i), x);
        }

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
            u = f[i][u];
    if(u == v)
        return u;

    for(i = M - 1; i > -1; i --)
        if(f[i][u] != f[i][v])
        {
            u = f[i][u];
            v = f[i][v];
        }

    return f[0][u];
}

int main(void)
{
    int n, u, v;
    int i, j, k, o;

    Sieve::Sieve();
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        c[a[i]].push_back(i);
    }
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }
    DFS(0, 0);

    for(i = 1; i <= n; i ++)
    {
        for(j = 1; i * j <= n; j ++)
            for(k = 0; k < (signed)c[i * j].size(); k ++)
            {
                s.push_back(c[i * j].at(k));
                Tree::b[c[i * j].at(k)] = true;
            }
        s.push_back(0);
        sort(s.begin(), s.end(), Compare);
        k = s.size();
        for(j = 1; j < k; j ++)
            s.push_back(GetLCA(s.at(j - 1), s.at(j)));
        sort(s.begin(), s.end(), Compare);
        s.erase(unique(s.begin(), s.end()), s.end());

        for(j = 1; j < (signed)s.size(); j ++)
            Tree::e[GetLCA(s.at(j - 1), s.at(j))].push_back(s.at(j));
        ::o[i] = Tree::Solve(s);
        // printf("%d : %lld\n", i, o[0][i]);

        for(j = 0; j < (signed)s.size(); j ++)
        {
            Tree::e[s.at(j)].clear();
            Tree::b[s.at(j)] = false;
        }
        s.clear();
    }

    for(i = 1, o = 0; i <= n; i ++)
    {
        for(j = 1, v = 0; i * j <= n; j ++)
            v = (v + (long long)Sieve::g[j] * ::o[i * j]) % MOD;
        o = (o + (long long)v * i % MOD * Sieve::Power(Sieve::f[i], MOD - 2) % MOD) % MOD;
    }
    printf("%lld\n", ((long long)o * Sieve::Power((long long)n * (n - 1) % MOD, MOD - 2) % MOD + MOD) % MOD);

    return 0;
}