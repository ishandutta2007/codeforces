#include <bits/stdc++.h>
using namespace std;

int n, K, cnt[1 << 20];
double p[20], ans[20], f[1 << 20], s[1 << 20];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
    }
    for (int i = 1; i < 1 << n; i++) {
        int j = __builtin_ctz(i);
        s[i] = s[i ^ (1 << j)] + p[j];
        cnt[i] = __builtin_popcount(i);
    }
    f[0] = 1;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) if (!(i >> j & 1) && p[j] > 1e-9) {
            double t = p[j] / s[((1 << n) - 1) ^ i];
            f[i | (1 << j)] += f[i] * t;
            if (cnt[i] < K) ans[j] += f[i] * t;
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] < 1e-9) printf("0 ");
        else printf("%.9f ", ans[i]);
    }
    return 0;
}