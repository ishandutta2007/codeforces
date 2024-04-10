#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#define N 100020
using namespace std;
 
vector<int> e[N];
int d[N];
bool u[N], v[N];
 
void DFS(int x, int s, int m)
{
    static vector<int> t;
    int i;
 
    if(d[x])
    {
        if(s - d[x] >= m)
        {
            printf("2\n%d\n", s - d[x]);
            for(; t.back() != x; t.pop_back())
                printf("%d ", t.back() + 1);
            printf("%d\n", x + 1);
 
            throw 0;
        }
 
        return;
    }
 
    d[x] = s;
    t.push_back(x);
    for(i = 0; i < (signed)e[x].size(); i ++)
        DFS(e[x][i], s + 1, m);
    t.pop_back();

    if(!u[x])
    {
        u[x] = v[x] = true;
        for(i = 0; i < (signed)e[x].size(); i ++)
            u[e[x][i]] = true;
    }

    return;
}
 
int main(void)
{
    int n, m, u, v;
    int i, j;
 
    scanf("%d %d", &n, &m);
    while(m --)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }
    m = (int)ceil(sqrt(n));
 
    try
    {
        DFS(0, 1, m);
        printf("1\n");
        for(i = j = 0; i < n && j < m; i ++)
            if(::v[i])
                printf("%d%c", i + 1, " \n"[++ j == m]);
    }
    catch(...)
    {
    }
 
    return 0;
}