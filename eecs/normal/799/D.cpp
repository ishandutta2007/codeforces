#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int a, b, h, w, n, x[maxn], f[maxn];

int main() {
    scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + n + 1, greater<>());
    auto solve = [&](int a, int b) {
        if (h >= a && w >= b) return 0;
        memset(f, -0x3f, sizeof(f)), f[h] = w;
        for (int i = 1; i <= min(40, n); i++) {
            for (int j = 100000; j; j--) if (f[j] > 0) {
                int k = min(100000LL, 1LL * j * x[i]);
                f[k] = max(f[k], f[j]);
                f[j] = min(100000LL, 1LL * f[j] * x[i]);
            }
            for (int j = a; j <= 100000; j++) {
                if (f[j] >= b) return i;
            }
        }
        return INT_MAX;
    };
    int ans = min(solve(a, b), solve(b, a));
    if (ans > 1e9) ans = -1;
    printf("%d\n", ans);
    return 0;
}