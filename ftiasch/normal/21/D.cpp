// Codeforces Alpha Round #21
// Problem D -- Traveling Graph
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 15
#define M 2000
#define INF 100000000

#define BIT(x) (1 << (x))

using namespace std;

int n, m, u[M], v[M], w[M], d[N], g[N][N], f[1 << N];

int main()
{
    scanf("%d%d", &n, &m);
    int answer = 0;
    memset(d, 0, sizeof(d));
    for(int i = 0; i != n; ++ i)
        for(int j = 0; j != n; ++ j)
            g[i][j] = i == j? 0: INF;
    for(int i = 0; i != m; ++ i)
    {
        scanf("%d%d%d", u + i, v + i, w + i);
        u[i] --, v[i] --;
        answer += w[i];
        d[u[i]] ++, d[v[i]] ++;
        g[u[i]][v[i]] = min(g[u[i]][v[i]], w[i]);
        g[v[i]][u[i]] = g[u[i]][v[i]];
    }
    for(int k = 0; k != n; ++ k)
        for(int i = 0; i != n; ++ i)
            for(int j = 0; j != n; ++ j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for(int i = 0; i != m; ++ i)
        if(g[0][u[i]] == INF)
        {
            printf("-1\n");
            return 0;
        }
    f[0] = 0;
    for(int i = 1, j = 0; i != BIT(n); ++ i)
    {
        f[i] = INF;
        if(i == BIT(j + 1))
            j ++;
        for(int k = 0; k != j; ++ k)
            f[i] = min(f[i], f[i ^ BIT(j) ^ BIT(k)] + g[j][k]);
    }
    int mask = 0, count = 0;
    for(int i = 0; i != n; ++ i)
        if(d[i] & 1)
            mask |= BIT(i);
    printf("%d\n", f[mask] == INF? -1: answer + f[mask]);
    return 0;
}