#include <bits/stdc++.h>
using namespace std;

int n, K, m, e[85][85], f[85][85][85];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d %d", &n, &K, &m);
    if (K > n) puts("-1"), exit(0);
    memset(e, 0x3f, sizeof(e));
    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        chk(e[u][v], c);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        f[1][i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            for (int j = i + len - 1; j <= n; j++) {
                for (int k = i + 1; k <= j; k++) {
                    chk(f[len][i][j], f[len - 1][j][k] + e[i][j]);
                }
            }
        }
        for (int i = len; i <= n; i++) {
            for (int j = 1; j + len - 1 <= i; j++) {
                for (int k = j; k < i; k++) {
                    chk(f[len][i][j], f[len - 1][j][k] + e[i][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    chk(f[len][i][k], f[len - 1][j][k] + e[i][j]);
                }
            }
        }
        for (int i = n; i; i--) {
            for (int j = i - 1; j; j--) {
                for (int k = j; k; k--) {
                    chk(f[len][i][k], f[len - 1][j][k] + e[i][j]);
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            chk(ans, f[K][i][j]);
        }
    }
    if (ans > 1e9) puts("-1");
    else printf("%d\n", ans);
    return 0;
}