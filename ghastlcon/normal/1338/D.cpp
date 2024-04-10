
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 100020
using namespace std;

vector<int> e[N];
int f[N][2];

int DFS(int x, int p)
{
    int i, v, o;

    f[x][1] = 1;
    for(i = 0, o = 1; i < (signed)e[x].size(); i ++)
        if((v = e[x][i]) != p)
        {
            o = max(o, DFS(v, x));
            o = max(o, f[x][0] + max(f[v][0], f[v][1]));
            o = max(o, f[x][1] + f[v][0]);

            f[x][0] = max(f[x][0], max(f[v][0], f[v][1]) + (int)e[x].size() - 2);
            f[x][1] = max(f[x][1], f[v][0] + 1);
        }

    return o;
}

int main(void)
{
    int n, u, v;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }
    printf("%d\n", DFS(0, -1));

    return 0;
}