#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, q, a[maxn][maxn], ans[maxn * maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = (i - 1) * m + j;
        }
    }
    while (q--) {
        int op, x, y, z;
        scanf("%d %d", &op, &x);
        if (op == 1) {
            int o = a[x][1];
            for (int i = 2; i <= m; i++) a[x][i - 1] = a[x][i];
            a[x][m] = o;
        } else if (op == 2) {
            int o = a[1][x];
            for (int i = 2; i <= n; i++) a[i - 1][x] = a[i][x];
            a[n][x] = o;
        } else {
            scanf("%d %d", &y, &z);
            ans[a[x][y]] = z;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", ans[(i - 1) * m + j]);
        }
        putchar('\n');
    }
    return 0;
}