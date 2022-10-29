#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 500 + 10;
struct node{
    int sum;
    int son[10];
}tri[N];
int n, m, tot;
char s[N];
int ans1, ans2;
int f[N][N][11], g[N][N][11], tmp[N][11], tmp1[N][11];
void dfs(int x, int deep) {
    for (int i = 0; i < 10; i ++)
        if (tri[x].son[i]) {
            int y = tri[x].son[i];
            dfs(y, deep + 1);
            for (int j = 0; j <= tot; j ++)
                for (int k = 0; k <= 10; k++)
                    tmp[j][k] = f[x][j][k], tmp1[j][k] = g[x][j][k];
            for (int j = 2; j <= tot; j ++)
                for (int l = 10; l >= 0; l --)
                    for (int k = 0; k <= l; k ++)
                        f[x][j-1][l] = max(f[x][j - 1][l], tmp[j - 1][l - k] + f[y][j][k]);
            for (int j = 1; j <= tot; j ++)
                for (int l = 0; l <= 10; l ++)
                    for (int k = 0; k <= l - 1; k ++)
                        f[x][j][l] = max(f[x][j][l], tmp[j][l - k - 1] + g[y][j + 1][k]);

            for (int j = 1; j <= tot; j ++)
                for (int l = 0; l <= 10; l ++) {
                    for (int k = 0; k <= l; k++)
                        g[x][j][l] = max(g[x][j][l], tmp1[j][l - k] + f[y][1][k]);
                    for (int k = 0; k < l; k++)
                        g[x][j][l] = max(g[x][j][l], tmp1[j][l - k - 1] + g[y][1][k]);
                }
        }
    for (int i = 1; i <= tot; i ++)
        f[x][i][0] += max(tri[x].sum * (deep - i), 0), g[x][i][0] +=tri[x].sum * deep;
}
int main() {
    scanf("%d %d", &n, &m);
    tot = 1;
    while (n --) {
        int x;
        scanf("%s %d", s, &x);
        int y = 1;
        char *w = s;
        while (w[0] >= '0' && w[0] <= '9') {
            if (!tri[y].son[w[0] - '0'])
                tri[y].son[w[0] - '0'] = ++ tot;
            y = tri[y].son[w[0] - '0'];
            w ++;
            ans1 += x;
        }
        tri[y].sum += x;
    }
    dfs(1, 0);
    for (int j = 0; j <= m; j ++)
        ans2 = max(ans2, g[1][1][j]);
    printf("%d\n", ans1 - ans2);
    return 0;
}