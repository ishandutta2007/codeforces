#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> Pii;
#define N 100000 + 5
#define x first
#define y second
#define mp make_pair

int n, m, cnt, depth, Size, low[99][99], dfn[99][99];
char s[N], _s[N];
bool Vis[99][99];
Pii Stack[N];

inline void dfs(int x, int y)
{
    dfn[x][y] = low[x][y] = ++ depth;
    Stack[++ Size] = mp(x, y);
    Vis[x][y] = 1;
    
    int tx, ty;
    if (_s[y] == '^')
        tx = x - 1, ty = y;
    else tx = x + 1, ty = y;
    if (tx && ty && tx <= n && ty <= m)
    {
        if (!dfn[tx][ty])
            dfs(tx, ty), low[x][y] = min(low[x][y], low[tx][ty]);
        else if (Vis[tx][ty]) low[x][y] = min(low[x][y], dfn[tx][ty]);
    }
    
    if (s[x] == '<')
        tx = x, ty = y - 1;
    else tx = x, ty = y + 1;
    if (tx && ty && tx <= n && ty <= m)
    {
        if (!dfn[tx][ty])
            dfs(tx, ty), low[x][y] = min(low[x][y], low[tx][ty]);        
        else if (Vis[tx][ty]) low[x][y] = min(low[x][y], dfn[tx][ty]);
    }
    
    if (dfn[x][y] == low[x][y])
    {
        Pii j;
        cnt ++;
        do
        {
            j = Stack[Size --];
            Vis[j.x][j.y] = 0;
        } while (j != mp(x, y));
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    scanf("%s", _s + 1);
    dfs(1, 1);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (!dfn[i][j]) dfs(i, j);
    if (cnt > 1)
        puts("NO");
    else puts("YES");
    return 0;
}