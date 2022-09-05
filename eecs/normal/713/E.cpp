#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int m, n, a[maxn], p[maxn], f[maxn];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i + n] = a[i] + m;
    }
    sort(a + 1, a + (n << 1 | 1));
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i + 1] - a[i]);
    }
    for (int i = 2; i <= n + 1; i++) if (a[i] - a[i - 1] == mx) {
        copy(a + i, a + i + n, p + 1);
        for (int j = 1; j <= n; j++) p[j] -= a[i];
        break;
    }
    auto chk = [&](int x) {
        auto solve = [&](int st) {
            for (int i = st; i <= n; i++) {
                f[i] = f[i - 1];
                if (f[i - 1] >= p[i] - 1) f[i] = p[i] + x;
                if (f[i - 1] >= p[i] - x - 1) f[i] = max(f[i], p[i]);
                if (i > st && f[i - 2] >= p[i] - x - 1) f[i] = max(f[i], p[i - 1] + x);
            }
        };
        f[1] = x, solve(2); // 1: R
        if (f[n] >= m - 1) return 1;
        f[1] = 0, solve(2); // 1: L
        if (f[n] >= m - x - 1) return 1;
        f[2] = max(p[2], x), solve(3); // 1: R; 2: L
        if (f[n] >= m + p[2] - x - 1) return 1;
        return 0;
    };
    int l = 0, r = mx, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}