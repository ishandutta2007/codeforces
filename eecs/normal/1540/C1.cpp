#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, P = 1000000007;
int n, ans, q, x, a[maxn], c[maxn], b[maxn], f[maxn][maxn * maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &b[i]), b[i] += b[i - 1];
    }
    scanf("%d", &q);
    while (q--) {
        memset(f, 0, sizeof(f));
        scanf("%d", &x), ans = 0;
        int cur = 0;
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int l = -b[i] - x, r = c[i] - b[i] - x;
            cur += l;
            for (int j = 0; j <= i * 100; j++) if (f[i - 1][j]) {
                for (int k = 0; k <= r - l; k++) {
                    red(f[i][j + k] += f[i - 1][j] - P);
                }
            }
            for (int j = 0; j <= i * 100; j++) {
                if (cur + j < 0) f[i][j] = 0;
                if (i == n) red(ans += f[i][j] - P);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}