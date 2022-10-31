#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1020
using namespace std;

double f[N][N], g[N][N];

int main(void)
{
    int n, m, x, y;
    int i, j;

    scanf("%d %d %d %d", &n, &m, &x, &y);
    if(m == 1)
        printf("%d.0000000000\n", (n - x) * 2);
    else
    {
        for(i = n - 1; i >= x; i --)
        {
            for(j = 1; j <= m; j ++)
            {
                g[j][j] = j == 1 || j == m ? 2 : 3;
                if(j != 1)
                    g[j][j - 1] = -1;
                if(j != m)
                    g[j][j + 1] = -1;
                g[j][m + 1] = (j == 1 || j == m ? 3 : 4) + f[i + 1][j];
            }

            for(j = 1; j < m; j ++)
                if(g[j + 1][j])
                {
                    g[j + 1][j + 1] -= g[j][j + 1] * (g[j + 1][j] / g[j][j]);
                    g[j + 1][m + 1] -= g[j][m + 1] * (g[j + 1][j] / g[j][j]);
                    g[j + 1][j] = 0;
                }
            for(j = m; j > 1; j --)
                if(g[j - 1][j])
                {
                    g[j - 1][j - 1] -= g[j][j - 1] * (g[j - 1][j] / g[j][j]);
                    g[j - 1][m + 1] -= g[j][m + 1] * (g[j - 1][j] / g[j][j]);
                    g[j - 1][j] = 0;
                }
            for(j = 1; j <= m; j ++)
                f[i][j] = g[j][m + 1] / g[j][j];
        }
        printf("%.10f\n", f[x][y]);
    }

    return 0;
}