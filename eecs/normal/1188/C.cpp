#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, P = 998244353;
int n, K, ans, a[maxn], cur[maxn], f[maxn], g[maxn];

void red(int &x) { x < 0 ? x += P : 0; }

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), cur[i] = i - 1;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i * (K - 1) <= 100000; i++) {
        memset(g, 0, sizeof(g));
        for (int j = 1; j <= n; j++) {
            while (cur[j] && a[j] - a[cur[j]] < i) cur[j]--;
        }
        for (int k = 1; k <= K; k++) {
            for (int j = 1; j <= n; j++) {
                f[j] = k == 1 ? 1 : g[cur[j]];
            }
            for (int j = 1; j <= n; j++) {
                g[j] = g[j - 1], red(g[j] += f[j] - P);
            }
        }
        red(ans += g[n] - P);
    }
    printf("%d\n", ans);
    return 0;
}