#include <bits/stdc++.h>
using namespace std;

const int maxn = 55, P = 998244353;
int n, m, l[maxn], r[maxn], f[100010], g[100010], w[100010];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    for (int i = 1; i <= m; i++) {
        bool flag = 1;
        for (int j = 1; j <= n; j++) {
            if ((l[j] + i - 1) / i > r[j] / i) { flag = 0; break; }
        }
        if (!flag) continue;
        int U = m / i;
        fill(f, f + U + 1, 0), f[0] = 1;
        for (int j = 1; j <= n; j++) {
            int lb = (l[j] + i - 1) / i, rb = r[j] / i;
            for (int k = 1; k <= U; k++) {
                (f[k] += f[k - 1]) %= P;
            }
            copy(f, f + U + 1, g);
            for (int k = 0; k <= U; k++) {
                if (k < lb) { f[k] = 0; continue; }
                f[k] = (g[k - lb] - (k <= rb ? 0 : g[k - rb - 1]) + P) % P;
            }
        }
        for (int k = 0; k <= U; k++) (w[i] += f[k]) %= P;
    }
    for (int i = m; i; i--) {
        for (int j = i + i; j <= m; j += i) w[i] = (w[i] - w[j] + P) % P;
    }
    printf("%d\n", w[1]);
    return 0;
}