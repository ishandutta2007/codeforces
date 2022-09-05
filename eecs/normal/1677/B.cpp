#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, n, m, sum[maxn], f[maxn], g[maxn];
char str[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %s", &n, &m, str + 1);
        for (int i = 1; i <= n * m; i++) {
            sum[i] = sum[i - 1] + str[i] - '0';
        }
        for (int i = 1; i <= n * m; i++) {
            if (i <= m) f[i] = sum[i] == 0;
            else f[i] = f[i - m] + (sum[i - m] == sum[i]);
            if (i <= m) g[i] = str[i] == '0';
            else g[i] = g[i - m] & (str[i] == '0');
        }
        for (int i = 1; i <= n * m; i++) {
            g[i] += g[i - 1];
        }
        for (int i = 1; i <= n * m; i++) {
            int ans = f[i];
            ans += g[i] - g[max(0, i - m)];
            ans += max(0, m - i) + n - (i + m - 1) / m;
            printf("%d ", n + m - ans);
        }
        putchar('\n');
    }
    return 0;
}