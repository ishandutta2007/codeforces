#include <bits/stdc++.h>
using namespace std;

int n, P, f[4000010], g[4000010];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d", &n, &P);
    int s = 0;
    for (int i = f[1] = 1; i <= n; i++) {
        red(s += f[i - 1] - P);
        red(g[i] += g[i - 1] - P);
        if (i > 1) red(f[i] = s + g[i] - P);
        for (int l = i; l <= n; l += i) {
            int r = min(n, l + i - 1);
            int o = 1LL * f[i] * (l / i) % P;
            red(g[l] += o - P), red(g[r + 1] -= o);
            for (int j = l / (i + 1) * (i + 1); j <= r; j += i + 1) {
                int L = max(j, l), R = min(j + i, r);
                o = 1LL * f[i] * (j / (i + 1)) % P;
                red(g[L] -= o), red(g[R + 1] += o - P);
            }
        }
    }
    printf("%d\n", f[n]);
    return 0;
}