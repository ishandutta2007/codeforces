#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 1000020
using namespace std;

vector<pair<int, int> > e[N];
bool u[N];
int r[N];

void DFS(int x)
{
    static bool k;
    int i;

    for(; r[x] < (signed)e[x].size(); r[x] ++)
        if(!u[e[x][r[x]].second])
        {
            i = r[x];
            u[e[x][i].second] = true;
            DFS(e[x][i].first);
            if(k ^= 1)
                printf("%d %d\n", x, e[x][i].first);
            else
                printf("%d %d\n", e[x][i].first, x);
        }

    return;
}

int main(void)
{
    int n, m, u, v;
    int i;
    vector<int> t;

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(make_pair(v, i));
        e[v].push_back(make_pair(u, i));
    }
    for(i = 1; i <= n; i ++)
        if(e[i].size() & 1)
            t.push_back(i);
    if(t.size() & 1)
        throw;

    for(i = 0; i < (signed)t.size(); i += 2)
    {
        e[t[i]].push_back(make_pair(t[i + 1], m   ));
        e[t[i + 1]].push_back(make_pair(t[i], m ++));
    }
    if(m & 1)
        e[1].push_back(make_pair(1, m ++));

    printf("%d\n", m);
    DFS(1);

    return 0;
}