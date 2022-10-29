#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int N = 100001;
char s[N];
int l[N][26], r[N][26], g[3][N], f[251][251][251];
int q, n;
void update(int *x, int v)
{
    if (!*x || *x > v) *x = v;
}
int main()
{
    scanf("%d %d", &n, &q);
    scanf(" %s", s + 1);
    for (int i = 1; i <= n ; i ++) {
        s[i] -= 'a';
        for (int j = 0; j < 26; j ++)
            l[i][j] = l[i - 1][j];
        if (i != 1)l[i][s[i - 1]] = i - 1;
    }
    for (int i = n ; i >= 0 ; i --)
    {
        for (int j = 0; j < 26; j ++)
            r[i][j] = r[i + 1][j];
        if (i != n)r[i][s[i + 1]] = i + 1;
    }
    while (q --)
    {
        char sig, c;
        int x;
        scanf(" %c %d", &sig, &x);
        x --;
        if (sig == '+') {
            scanf(" %c", &c), g[x][++g[x][0]] = c - 'a';
            if (x == 0) {
                for (int i = g[0][0] - 1; i <= g[0][0]; i ++)
                    for (int j = 0; j <= g[1][0]; j ++)
                        for (int k = 0; k <= g[2][0]; k ++)
                            if (f[i][j][k] || (!i && !j && !k))
                            {
                                if (i != g[0][0] && r[f[i][j][k]][g[0][i + 1]])
                                    update(&f[i + 1][j][k], r[f[i][j][k]][g[0][i + 1]]);
                                if (j != g[1][0] && r[f[i][j][k]][g[1][j + 1]])
                                    update(&f[i][j + 1][k], r[f[i][j][k]][g[1][j + 1]]);
                                if (k != g[2][0] && r[f[i][j][k]][g[2][k + 1]])
                                    update(&f[i][j][k + 1], r[f[i][j][k]][g[2][k + 1]]);
                            }
            } else
            if (x == 1){
                for (int i = 0; i <= g[0][0]; i ++)
                    for (int j = g[1][0] - 1; j <= g[1][0]; j ++)
                        for (int k = 0; k <= g[2][0]; k ++)
                            if (f[i][j][k] || (!i && !j && !k))
                            {
                                if (i != g[0][0] && r[f[i][j][k]][g[0][i + 1]])
                                    update(&f[i + 1][j][k], r[f[i][j][k]][g[0][i + 1]]);
                                if (j != g[1][0] && r[f[i][j][k]][g[1][j + 1]])
                                    update(&f[i][j + 1][k], r[f[i][j][k]][g[1][j + 1]]);
                                if (k != g[2][0] && r[f[i][j][k]][g[2][k + 1]])
                                    update(&f[i][j][k + 1], r[f[i][j][k]][g[2][k + 1]]);
                            }
            } else{
                for (int i = 0; i <= g[0][0]; i ++)
                    for (int j = 0; j <= g[1][0]; j ++)
                        for (int k = g[2][0] - 1; k <= g[2][0]; k ++)
                            if (f[i][j][k] || (!i && !j && !k))
                            {
                                if (i != g[0][0] && r[f[i][j][k]][g[0][i + 1]])
                                    update(&f[i + 1][j][k], r[f[i][j][k]][g[0][i + 1]]);
                                if (j != g[1][0] && r[f[i][j][k]][g[1][j + 1]])
                                    update(&f[i][j + 1][k], r[f[i][j][k]][g[1][j + 1]]);
                                if (k != g[2][0] && r[f[i][j][k]][g[2][k + 1]])
                                    update(&f[i][j][k + 1], r[f[i][j][k]][g[2][k + 1]]);
                            }
            }
        }else {
            if (x == 0) {
                for (int i = 0; i <= g[1][0]; i ++)
                    for (int j = 0; j <= g[2][0]; j ++)
                        f[g[0][0]][i][j]= 0;

            } else
            if (x == 1){
                for (int i = 0; i <= g[0][0]; i ++)
                    for (int j = 0; j <= g[2][0]; j ++)
                        f[i][g[1][0]][j]= 0;

            } else{
                for (int i = 0; i <= g[0][0]; i ++)
                    for (int j = 0; j <= g[1][0]; j ++)
                        f[i][j][g[2][0]]= 0;
            }
            g[x][0]--;
        }
        if (f[g[0][0]][g[1][0]][g[2][0]]|| (!g[0][0] && !g[1][0] && !g[2][0]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}