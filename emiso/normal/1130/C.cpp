#include <bits/stdc++.h>

using namespace std;

int n, c[55][55], cnt = 1, xo, xd, yo, yd, ans = INT_MAX;
char g[55][55];

void dfs(int x, int y, int cor) {
    if(x == 0 || y == 0 || x > n || y > n || g[x][y] == '1' || c[x][y]) return;
    c[x][y] = cor;
    dfs(x + 1, y, cor);
    dfs(x - 1, y, cor);
    dfs(x, y + 1, cor);
    dfs(x, y - 1, cor);
}

int main() {
    scanf("%d %d %d %d %d", &n, &xo, &yo, &xd, &yd);
    for(int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(g[i][j] == '0' && !c[i][j])
                dfs(i, j, cnt++);


    int c1 = c[xo][yo], c2 = c[xd][yd];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                for(int l = 1; l <= n; l++)
                    if(c[i][j] == c1 && c[k][l] == c2)
                        ans = min(ans, (k-i)*(k-i) + (l-j)*(l-j));

    printf("%d\n", ans);
    return 0;
}