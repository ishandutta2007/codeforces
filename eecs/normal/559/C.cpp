#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 1000000007;
int h, w, n, f[maxn];
int fact[200010], finv[200010];
pair<int, int> p[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + n + 1), p[0] = {1, 1};
    for (int i = fact[0] = finv[0] = 1; i <= h + w; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) {
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    auto calc = [&](int r, int c) {
        return binom(r + c, r);
    };
    for (int i = n; ~i; i--) {
        f[i] = calc(h - p[i].first, w - p[i].second);
        for (int j = i + 1; j <= n; j++) if (p[j].second >= p[i].second) {
            f[i] = (f[i] - 1LL * f[j] * calc(p[j].first - p[i].first, p[j].second
                - p[i].second) % P + P) % P;
        }
    }
    printf("%d\n", f[0]);
    return 0;
}