#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1000020
using namespace std;

vector<int> e[N];
int d[N], h[N], s[N];
int *f[N], g[N], c;
int o[N];

void InitChain(int x, int p)
{
    int i;

    for(i = 0, h[x] = x, s[x] = 1; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
        {
            d[e[x].at(i)] = d[x] + 1;
            InitChain(e[x].at(i), x);
            if(s[x] < s[e[x].at(i)] + 1)
            {
                s[x] = s[e[x].at(i)] + 1;
                h[x] = e[x].at(i);
            }
        }

    return;
}

void DFS(int x, int p)
{
    int i, j;

    o[x] = 0;
    f[x][0] ++;
    if(h[x] != x)
    {
        f[h[x]] = f[x] + 1;
        DFS(h[x], x);
        if(f[x][o[h[x]] + 1] > f[x][o[x]])
            o[x] = o[h[x]] + 1;
    }

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p && e[x].at(i) != h[x])
        {
            f[e[x].at(i)] = g + c;
            c += s[e[x].at(i)];
            DFS(e[x].at(i), x);

            for(j = 0; j < s[e[x].at(i)]; j ++)
            {
                f[x][j + 1] += f[e[x].at(i)][j];
                if((f[x][j + 1] > f[x][o[x]]) || (f[x][j + 1] == f[x][o[x]] && j + 1 < o[x]))
                    o[x] = j + 1;
            }
        }

    return;
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

    InitChain(0, 0);
    // for(i=0;i<n;i++)cout<<h[i]<<' ';cout<<endl;
    f[0] = g;
    c = s[0];
    DFS(0, 0);
    // cout<<c<<endl;
    // return 0;

    for(i = 0; i < n; i ++)
        printf("%d\n", o[i]);

    return 0;
}