#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
#define N 100020
#define S 26
using namespace std;

char a[N], b[N];
int *f[N], g[N], h[N][S];

int main(void)
{
    int n, m;
    int i, j, k;

    scanf("%s %s", a, b);
    n = (int)strlen(a);
    m = (int)strlen(b);

    for(i = 1; i < m; i ++)
    {
        for(g[i + 1] = g[i]; g[i + 1] && b[g[i + 1]] != b[i]; g[i + 1] = g[g[i + 1]])
            ;
        g[i + 1] += b[g[i + 1]] == b[i];
    }
    // for(i=0;i<=m;i++)cout<<g[i]<<' ';cout<<endl;

    for(i = 0; i <= m; i ++)
        for(j = 0; j < S; j ++)
        {
            h[i][j] = i;
            if(b[h[i][j]] - 97 == j)
                h[i][j] ++;
            else
                h[i][j] = h[g[h[i][j]]][j];
            // for(h[i][j] = i; h[i][j] && b[h[i][j]] - 97 != j; h[i][j] = g[h[i][j]])
            //     ;
            // h[i][j] += b[h[i][j]] - 97 == j;
        }

    for(i = 0; i <= n; i ++)
    {
        f[i] = new int[m + 1];
        for(j = 0; j <= m; j ++)
            f[i][j] = INT_MIN;
    }

    f[0][0] = 0;
    for(i = 0; i < n; i ++)
        for(j = 0; j <= m; j ++)
            if(f[i][j] >= 0)
            {
                // printf("at perv %d, match %d : %d\n", i, j, f[i][j]);
                if(a[i] == '?')
                    for(k = 0; k < 26; k ++)
                        f[i + 1][h[j][k]] = max(f[i + 1][h[j][k]], f[i][j] + (h[j][k] == m));
                else
                    f[i + 1][h[j][a[i] - 97]] = max(f[i + 1][h[j][a[i] - 97]], f[i][j] + (h[j][a[i] - 97] == m));
            }
    printf("%d\n", *max_element(f[n], f[n] + m + 1));

    return 0;
}