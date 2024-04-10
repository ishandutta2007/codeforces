#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 2020
#define M 52
#define S 10
#define MOD 1000000007
using namespace std;

class Node
{
public:
    int s[S];
    int f;
    int l;

    Node(void) : f(-1), l(0)
    {
        memset(s, 0, sizeof(s));

        return;
    }
};

int f[M][N][M >> 1][2][2];
Node g[N];
int h[N][S];
int c, d;

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

inline void Modadd(int &x, int y)
{
    x = Mod(x + y - MOD);

    return;
}

void InsertSAM(int k)
{
    int b, p, q;

    p = d;
    g[d = c ++].l = g[p].l + 1;
    for(; p != -1 && !g[p].s[k]; p = g[p].f)
        g[p].s[k] = d;

    if(p == -1)
        g[d].f = 0;
    else
    {
        q = g[p].s[k];
        if(g[q].l == g[p].l + 1)
            g[d].f = q;
        else
        {
            g[b = c ++] = g[q];
            g[b].l = g[p].l + 1;
            g[q].f = g[d].f = b;

            for(; p != -1 && g[p].s[k] == q; p = g[p].f)
                g[p].s[k] = b;
        }
    }

    return;
}

void InitSAM(string x)
{
    int i, j;

    for(i = 0, c = 1; i < (signed)x.size(); i ++)
        InsertSAM(x[i] - 48);
    for(i = 0; i < c; i ++)
        for(j = 0; j < S; j ++)
            for(h[i][j] = i; h[i][j] != -1 && !g[h[i][j]].s[j]; h[i][j] = g[h[i][j]].f)
                ;

    return;
}

void Walk(int &p, int &l, int k)
{
    int q;

    q = p;
    p = h[p][k];
    if(p == -1)
        l = p = 0;
    else if(p == q)
    {
        l ++;
        p = g[p].s[k];
    }
    else
    {
        l = g[p].l + 1;
        p = g[p].s[k];
    }

    return;
}

int Solve(string x)
{
    int n, m;
    int i, p, l, v;
    int q, t;

    n = (int)x.size();
    m = n >> 1;

    memset(f, 0, sizeof(f));
    f[0][0][0][0][1] = 1;
    for(i = 0; i < n; i ++)
        for(p = 0; p < c; p ++)
            for(l = 0; l <= m; l ++)
                for(v = 0; v < S; v ++)
                {
                    q = p;
                    t = l;
                    Walk(q, t, v);
                    t = min(t, m);

                    if(t >= m)
                    {
                        Modadd(f[i + 1][q][t][1][0], f[i][p][l][0][0]);
                        Modadd(f[i + 1][q][t][1][0], f[i][p][l][1][0]);
                        if(v < x[i] - 48)
                        {
                            Modadd(f[i + 1][q][t][1][0], f[i][p][l][0][1]);
                            Modadd(f[i + 1][q][t][1][0], f[i][p][l][1][1]);
                        }
                        else if(v == x[i] - 48)
                        {
                            Modadd(f[i + 1][q][t][1][1], f[i][p][l][0][1]);
                            Modadd(f[i + 1][q][t][1][1], f[i][p][l][1][1]);
                        }
                    }
                    else
                    {
                        Modadd(f[i + 1][q][t][0][0], f[i][p][l][0][0]);
                        Modadd(f[i + 1][q][t][1][0], f[i][p][l][1][0]);
                        if(v < x[i] - 48)
                        {
                            Modadd(f[i + 1][q][t][0][0], f[i][p][l][0][1]);
                            Modadd(f[i + 1][q][t][1][0], f[i][p][l][1][1]);
                        }
                        else if(v == x[i] - 48)
                        {
                            Modadd(f[i + 1][q][t][0][1], f[i][p][l][0][1]);
                            Modadd(f[i + 1][q][t][1][1], f[i][p][l][1][1]);
                        }
                    }
                }

    for(p = v = 0; p < c; p ++)
        for(l = 0; l <= m; l ++)
            Modadd(v, Mod(f[n][p][l][1][0] + f[n][p][l][1][1] - MOD));

    return v;
}

bool Vaild(string x)
{
    int n, m;
    int i, p, l;

    n = (int)x.size();
    m = n >> 1;
    for(i = p = l = 0; i < n; i ++)
    {
        Walk(p, l, x[i] - 48);
        if(l >= m)
            return true;
    }

    return false;
}

int main(void)
{
    string s, l, r;

    cin >> s >> l >> r;
    InitSAM(s);
    cout << Mod(Mod(Solve(r) - Solve(l)) + Vaild(l) - MOD) << endl;

    // for(int i = 10; i <= 29; i ++) cout << Vaild(to_string(i)) << ' ';

    return 0;
}