#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 1020
#define S 4
#define MOD 1000000009
using namespace std;

class Node
{
public:
    int s[S];
    int f;
    int g;

    Node(void) : f(0), g(0)
    {
        return;
    }
};

char a[N];
Node f[N];
queue<int> q;
int g[N / 10][N][11];

inline int ID(char c)
{
    return c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3;
}

void InsertACAM(char *s)
{
    static int c = 1;
    int i, p;

    for(i = p = 0; s[i]; i ++)
    {
        if(!f[p].s[ID(s[i])])
            f[p].s[ID(s[i])] = c ++;
        p = f[p].s[ID(s[i])];
    }
    f[p].g = max(f[p].g, (signed)strlen(s));

    return;
}

void InitACAM(void)
{
    int i, s, t;

    for(i = 0; i < S; i ++)
        if(f[0].s[i])
            q.push(f[0].s[i]);

    for(; !q.empty(); q.pop())
    {
        s = q.front();
        for(i = 0; i < S; i ++)
            if(f[s].s[i])
            {
                t = f[s].s[i];
                f[t].f = f[s].f;
                while(f[t].f && !f[f[t].f].s[i])
                    f[t].f = f[f[t].f].f;

                f[t].f = f[f[t].f].s[i];
                f[t].g = max(f[t].g, f[f[t].f].g);
                q.push(t);
                // printf("%d : %d\n",t,f[t].g);
            }
            else
                f[s].s[i] = f[f[s].f].s[i];
    }

    return;
}

int DFS(int x, int n, int m)
{
    int i;

    if(m <= f[x].g)
        m = 0;
    if(!n)
        return !m;

    if(m > 10)
        return 0;
    if(g[x][n][m] != -1)
        return g[x][n][m];

    for(i = g[x][n][m] = 0; i < 4; i ++)
        g[x][n][m] = (g[x][n][m] + DFS(f[x].s[i], n - 1, m + 1)) % MOD;
    // printf("%d %d %d : %d\n",x,n,m,g[x][n][m]);

    return g[x][n][m];
}

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);
    while(m --)
    {
        scanf("%s", a);
        InsertACAM(a);
    }
    InitACAM();

    memset(g, -1, sizeof(g));
    printf("%d\n", DFS(0, n, 0));

    return 0;
}