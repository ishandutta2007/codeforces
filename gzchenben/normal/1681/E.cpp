#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m, d[100005][2];
long long dis[100005][20][2][2];
void Init()
{
    for (int i = 1; i <= n - 2; i++)
    {
        dis[i][0][0][0] = abs(d[i][0] - d[i + 1][0]) + 1;
        dis[i][0][1][1] = abs(d[i][1] - d[i + 1][1]) + 1;
        dis[i][0][0][1] = 2 * i - d[i][0] - d[i + 1][1] + 3;
        dis[i][0][1][0] = 2 * i - d[i][1] - d[i + 1][0] + 3;
        // printf("%d - %d %d %d %d\n", i, dis[i][0][0][0], dis[i][0][0][1], dis[i][0][1][0], dis[i][0][1][1]);
    }
    for (int i = n - 2; i >= 1; i--)
    {
        for (int k = 1; i + (1 << k) <= n - 1; k++)
        {
            for (int x1 = 0; x1 <= 1; x1++)
            {
                for (int x2 = 0; x2 <= 1; x2++)
                {
                    dis[i][k][x1][x2] = min(dis[i][k - 1][x1][0] + dis[i + (1 << (k - 1))][k - 1][0][x2], dis[i][k - 1][x1][1] + dis[i + (1 << (k - 1))][k - 1][1][x2]);
                    // printf("%d %d %d %d - %d\n", i, k, x1, x2, dis[i][k][x1][x2]);
                }
            }
        }
    }
}
long long res[2][2], tmp[2][2];
void query(int x, int y)
{
    res[0][1] = res[1][0] = 1e15;
    res[0][0] = res[1][1] = 0;
    for (int i = 19; i >= 0; i--)
    {
        if (y - x <= (1 << i))
            continue;
        // printf("-- %d\n", i);
        for (int x1 = 0; x1 <= 1; x1++)
        {
            for (int x2 = 0; x2 <= 1; x2++)
            {
                tmp[x1][x2] = min(res[x1][0] + dis[x][i][0][x2], res[x1][1] + dis[x][i][1][x2]);
            }
        }
        for (int x1 = 0; x1 <= 1; x1++)
        {
            for (int x2 = 0; x2 <= 1; x2++)
            {
                res[x1][x2] = tmp[x1][x2];
            }
        }
        x += (1 << i);
    }
    // printf("%lld %lld %lld %lld\n", res[0][0], res[0][1], res[1][0], res[1][1]);
}
long long tmpdis[2][2];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%*d%d%d%*d", &d[i][0], &d[i][1]);
    }
    Init();
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int f1 = max(x1, y1), f2 = max(x2, y2);
        if (f1 == f2)
        {
            printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
            continue;
        }
        if (f1 > f2)
            swap(x1, x2), swap(y1, y2), swap(f1, f2);

        if (x1 == f1)
        {
            tmpdis[0][0] = abs(y1 - d[f1][0]);
            tmpdis[0][1] = 2 * f1 - y1 - d[f1][1];
        }
        else
        {
            tmpdis[0][0] = 2 * f1 - x1 - d[f1][0];
            tmpdis[0][1] = abs(x1 - d[f1][1]);
        }

        if (x2 == f2)
        {
            tmpdis[1][0] = abs(y2 - d[f2 - 1][0]);
            tmpdis[1][1] = 2 * f2 - y2 - d[f2 - 1][1];
        }
        else
        {
            tmpdis[1][0] = 2 * f2 - x2 - d[f2 - 1][0];
            tmpdis[1][1] = abs(x2 - d[f2 - 1][1]);
        }
        // printf("tmpdis %d %d %d %d\n", tmpdis[0][0], tmpdis[0][1], tmpdis[1][0], tmpdis[1][1]);
        query(f1, f2);
        long long ans = 1e15;
        for (int x1 = 0; x1 <= 1; x1++)
        {
            for (int x2 = 0; x2 <= 1; x2++)
            {
                ans = min(ans, tmpdis[0][x1] + tmpdis[1][x2] + res[x1][x2]);
            }
        }
        printf("%lld\n", ans + 1);
    }
}