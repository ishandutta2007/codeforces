#include <bits/stdc++.h>
using namespace std;

int n, m, f[1 << 18], e[1 << 18], sum[18][1 << 18], pre[1 << 18], ans[18];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        e[1 << u] |= 1 << v, sum[v][1 << u] += w;
    }
    for (int i = 1; i < 1 << n; i++) if (i & (i - 1)) {
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            e[i] |= e[1 << j];
            for (int k = 0; k < n; k++) sum[k][i] += sum[k][1 << j];
        }
    }
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 0; i < (1 << n) - 1; i++) {
        int S = ((1 << n) - 1) ^ i, cost = f[i];
        for (int k = 0; k < n; k++) {
            if (i >> k & 1) cost += sum[k][S];
        }
        for (int j = S; j; j = (j - 1) & S) if (!(e[j] & S)) {
            if (cost < f[i | j]) f[i | j] = cost, pre[i | j] = i;
        }
    }
    for (int S = (1 << n) - 1, cur = n; S; S = pre[S], cur--) {
        int T = S ^ pre[S];
        for (int i = 0; i < n; i++) {
            if (T >> i & 1) ans[i] = cur;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}