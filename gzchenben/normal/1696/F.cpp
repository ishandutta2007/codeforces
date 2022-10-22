#include <cstdio>
using namespace std;
bool flag[105][105][105];
int n, t, dis[105][105];
bool vis[105], ans, con[105][105];
void dfs(int x, int pre)
{
    vis[x] = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] && i != pre && flag[i][pre][x])
            ans = false;
        if (!vis[i] && flag[i][pre][x])
        {
            con[x][i] = con[i][x] = true;
            dfs(i, x);
        }
    }
}
void dfs2(int x, int Now, int pre)
{
    dis[x][Now] = dis[x][pre] + 1;
    if (Now == x)
        dis[x][Now] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != pre && con[Now][i])
        {
            dfs2(x, i, Now);
        }
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    flag[i][j][k] = true;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    char tmp;
                    scanf(" %c", &tmp);
                    flag[i][i + j][k] = (tmp == '1');
                    flag[i + j][i][k] = (tmp == '1');
                }
            }
        }
        bool res = false;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                vis[j] = false;
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                {
                    con[j][k] = false;
                    dis[j][k] = 0;
                }
            ans = true;
            vis[1] = vis[i] = true;
            con[1][i] = con[i][1] = true;
            dfs(1, i);
            dfs(i, 1);
            if (!ans)
                continue;
            // printf("testing %d\n", i);
            for (int j = 1; j <= n; j++)
            {
                dfs2(j, j, 0);
            }
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    // printf("dis[%d][%d] = %d\ncon[%d][%d] = %d\n", j, k, dis[j][k], j, k, con[j][k]);
                    for (int l = 1; l <= n; l++)
                    {
                        if (dis[j][l] == dis[k][l] && !flag[j][k][l])
                            ans = false;
                        if (dis[j][l] != dis[k][l] && flag[j][k][l])
                            ans = false;
                    }
                }
            }
            if (ans)
            {
                printf("Yes\n");
                res = true;
                for (int j = 1; j <= n; j++)
                {
                    for (int k = j + 1; k <= n; k++)
                    {
                        if (con[j][k])
                            printf("%d %d\n", j, k);
                    }
                }
                break;
            }
        }
        if (!res)
            printf("No\n");
    }
}