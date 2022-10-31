#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#define N 1000020
#define S 26
using namespace std;

int a[N];
bool b[N];
int s[N][S], f[N], h[N];
multiset<int> g;

void DFS(int x, int p, int v)
{
    int i;

    if(x)
    {
        f[x] = f[p] + 1;
        if(b[x])
            f[x] = min(f[x], v + *g.begin() + 1);
    }

    h[x] = b[x];
    for(i = 0; i < S; i ++)
        if(s[x][i])
        {
            g.insert(f[x] - v);
            DFS(s[x][i], x, v + h[x]);
            g.erase(g.lower_bound(f[x] - v));
            h[x] += h[s[x][i]];
        }

    return;
}

int main(void)
{
    int n, m, p;
    char c;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d %c", &p, &c);
        s[p][c - 97] = i;
    }

    scanf("%d", &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d", &a[i]);
        b[a[i]] = true;;
    }
    DFS(0, 0, 0);

    for(i = 0; i < m; i ++)
        printf("%d%c", f[a[i]], " \n"[i == m - 1]);

    return 0;
}