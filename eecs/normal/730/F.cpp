#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, maxm = 10010, INF = 1000000000;
int n, B, p[maxn][maxm], f[maxm], g[maxm], a[maxn], sum[maxn], use[maxn];

int main() {
    scanf("%d %d", &n, &B);
    int m = 10000;
    for (int i = 1; i <= m; i++) {
        f[i] = g[i] = INF;
    }
    int cur = g[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        sum[i] = sum[i - 1] + x;
        cur = min(cur + x / 10, m);
        for (int j = 0; j <= cur; j++) {
            f[j] = g[j], g[j] = INF;
        }
        for (int j = 0; j <= cur; j++) {
            if (f[j] <= sum[i - 1]) {
                int b = B - sum[i - 1] + f[j] + j;
                for (int k = 0; k <= x / 2 && k <= b; k++) {
                    int y = j + (x - k) / 10;
                    if (f[j] + x - k < g[y]) {
                        g[y] = f[j] + x - k;
                        p[i][y] = k;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= cur; i++) {
        if (g[i] < g[ans]) ans = i;
    }
    printf("%d\n", g[ans]);
    for (int i = n; i >= 1; ans -= (a[i] - p[i][ans]) / 10, i--) {
        use[i] = p[i][ans];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", use[i]);
    }
    return 0;
}