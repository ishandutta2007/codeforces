#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int vis[2001][2001], n, m;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct cc
{
    int x, y;
}vv, res;
int check(int x, int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    return 0;
}
queue <cc> qq;
void bfs()
{
    while(!qq.empty())
    {
        vv = qq.front();
        qq.pop();
        int x0 = vv.x;
        int y0 = vv.y;
        res = vv;
        for(int i = 0; i < 4; i++)
        {
            int x1 = x0 + dir[i][0];
            int y1 = y0 + dir[i][1];
            if(check(x1, y1) && !vis[x1][y1])
            {
                vis[x1][y1] = 1;
                vv.x = x1;
                vv.y = y1;
                res = vv;
                qq.push(vv);
            }
        }
    }
}
int main()
{
    int k, a, b;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(~scanf("%d %d", &n, &m))
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            vv.x = a;
            vv.y = b;
            vis[a][b] = 1;
            qq.push(vv);
        }
        bfs();
        printf("%d %d\n", res.x, res.y);
    }
    return 0;
}