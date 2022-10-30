#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define N 200020
using namespace std;

vector<int> e[2][N];
bool u[2][N];
char o[N];

void Findroot(int x)
{
    static bool k[N];
    int i;

    if(k[x])
    {
        printf("-1\n");

        exit(0);
    }
    if(u[0][x])
        return;

    k[x] = u[0][x] = true;
    for(i = 0; i < (signed)e[0][x].size(); i ++)
        Findroot(e[0][x][i]);
    k[x] = false;

    return;
}

void DFS(int x, vector<int> *e, bool *u)
{
    int i;

    if(u[x])
        return;
    u[x] = true;

    for(i = 0; i < (signed)e[x].size(); i ++)
        DFS(e[x][i], e, u);

    return;
}

int main(void)
{
    int n, m, u, v;
    int i;

    scanf("%d %d", &n, &m);
    while(m --)
    {
        scanf("%d %d", &u, &v);
        e[0][u].push_back(v);
        e[1][v].push_back(u);
    }
    for(i = 1; i <= n; i ++)
        Findroot(i);

    fill(::u[0], ::u[0] + N, false);
    for(i = 1, v = 0; i <= n; i ++)
    {
        o[i] = ::u[0][i] || ::u[1][i] ? 'E' : 'A';
        v += o[i] == 'A';
        DFS(i, e[0], ::u[0]);
        DFS(i, e[1], ::u[1]);
    }
    printf("%d\n%s\n", v, o + 1);

    return 0;
}