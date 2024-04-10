#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define N 5020
using namespace std;

vector<int> e[N];
bool u[N], v[N];
vector<int> x[N], y[N];
bool f[N][N], g[N][N];
char o[N];

void DFS(int x, bool v, vector<int> &p, vector<int> &q)
{
    int i;

    if(u[x])
    {
        if(::v[x] ^ v)
        {
            printf("NO\n");

            exit(0);
        }

        return;
    }
    u[x] = true;
    ::v[x] = v;
    (v ? q : p).push_back(x);

    for(i = 0; i < (signed)e[x].size(); i ++)
        DFS(e[x][i], v ^ 1, p, q);

    return;
}

void Reduce13(vector<int> &x, int &p)
{
    int i;

    for(i = 0; i < (signed)x.size(); i ++)
        if(p)
        {
            o[x[i]] = '1';
            p --;
        }
        else
            o[x[i]] = '3';

    return;
}

void Reduce2(vector<int> &x)
{
    int i;

    for(i = 0; i < (signed)x.size(); i ++)
        o[x[i]] = '2';

    return;
}

int main(void)
{
    int n, m, u, v, w[3];
    int i, j, k, c;

    scanf("%d %d %d %d %d", &n, &m, &w[0], &w[1], &w[2]);
    while(m --)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }

    for(i = c = 0; i < n; i ++)
        if(!::u[i])
        {
            c ++;
            DFS(i, false, x[c], y[c]);
        }

    f[0][0] = true;
    for(i = 1; i <= c; i ++)
        for(j = 0; j <= w[1]; j ++)
        {
            if(j >= x[i].size() && f[i - 1][j - x[i].size()])
            {
                f[i][j] = true;
                g[i][j] = false;
            }
            else if(j >= y[i].size() && f[i - 1][j - y[i].size()])
                f[i][j] = g[i][j] = true;
        }

    if(f[c][w[1]])
    {
        for(i = c, j = w[1]; i >= 1; i --)
        {
            Reduce13(g[i][j] ? x[i] : y[i], w[0]);
            Reduce2 (g[i][j] ? y[i] : x[i]);
            j -= (g[i][j] ? y[i] : x[i]).size();
        }
        printf("YES\n%s\n", o);
    }
    else
        printf("NO\n");

    return 0;
}