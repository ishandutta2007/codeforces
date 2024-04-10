// Codeforces Beta Round #10
// Problem D -- LCIS
#include <cstdio>
#include <cstring>

#define maxN 502

using namespace std;

int n, m, a[maxN], b[maxN], g[maxN], f[maxN][maxN], p[maxN][maxN][2];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", a + i);
    scanf("%d", &m);
    for(int j = 1; j <= m; ++ j)
        scanf("%d", b + j);
    for(int j = 1; j <= m + 1; ++ j)
        g[j] = n + 1;
    memset(f, 0, sizeof(f));
    for(int i = n; i >= 1; -- i)
    {
        int max = 0, ind = m + 1;
        for(int j = m; j >= 1; -- j)
        {
            f[i][j] = -maxN;
            if(a[i] == b[j] && max + 1 > f[i][j])
                f[i][j] = max + 1, p[i][j][0] = g[ind], p[i][j][1] = ind, g[j] = i;
            if(a[i] < b[j] && f[g[j]][j] > max)
                max = f[g[j]][j], ind = j;
        }
    }
    int max = 0, ind_i, ind_j;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(f[i][j] > max)
                max = f[i][j], ind_i = i, ind_j = j;
    printf("%d\n", max);
    while(ind_i <= n && ind_j <= m)
    {
        printf("%d ", a[ind_i]);
        int tmp_i = ind_i, tmp_j = ind_j;
        ind_i = p[tmp_i][tmp_j][0], ind_j = p[tmp_i][tmp_j][1];
    }
    printf("\n");
    return 0;
}