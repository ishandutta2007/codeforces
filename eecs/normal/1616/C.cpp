#include <bits/stdc++.h>
using namespace std;

int T, n, a[75], f[75][75];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        if (n == 1) { puts("0"); continue; }
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                f[i][j] = max(2, f[i][j]);
                for (int k = j + 1; k <= n; k++) {
                    // (a[j] - a[i]) / (j - i) = (a[k] - a[j]) / (k - j)
                    if ((a[j] - a[i]) * (k - j) == (a[k] - a[j]) * (j - i)) {
                        f[j][k] = max(f[j][k], f[i][j] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, f[i][j]);
            }
        }
        printf("%d\n", n - ans);
    }
    return 0;
}