#include <bits/stdc++.h>
using namespace std;

int n, K, c[100], w[100][100], f[11][100], ans = INT_MAX;
mt19937 rnd(time(0));

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &w[i][j]);
        }
    }
    int st = clock();
    while (1.0 * (clock() - st) / CLOCKS_PER_SEC < 1) {
        for (int i = 1; i <= n; i++) {
            c[i] = rnd() % 2;
        }
        memset(f, 0x3f, sizeof(f)), f[0][1] = 0;
        for (int i = 0; i < K; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) if (j ^ k && c[j] ^ c[k]) {
                    f[i + 1][k] = min(f[i + 1][k], f[i][j] + w[j][k]);
                }
            }
        }
        ans = min(ans, f[K][1]);
    }
    printf("%d\n", ans);
    return 0;
}