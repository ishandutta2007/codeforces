#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int T, n, a[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                scanf("%d", &a[i][j]);
                if (i > n && j > n) ans += a[i][j];
            }
        }
        ans += min({a[1][2 * n], a[1][n + 1], a[n][2 * n], a[n][n + 1], a[n + 1][1], a[n + 1][n], a[2 * n][1], a[2 * n][n]});
        printf("%lld\n", ans);
    }
    return 0;
}