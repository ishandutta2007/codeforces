#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], c[maxn], d[maxn];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), d[a[i]]++;
    }
    for (int i = 1, t = 0; i <= n; i++) if (d[i] & 1) {
        if (t) puts("0"), exit(0);
        t = 1;
    }
    int p = 1;
    while (p <= n && a[p] == a[n - p + 1]) p++;
    if (p > n) printf("%lld\n", 1LL * n * (n + 1) / 2), exit(0);
    ans -= 1LL * p * p;
    auto solve = [&]() {
        memset(c, 0, sizeof(c));
        int q = p;
        for (int i = 1; i < p; i++) c[a[i]]++;
        while (q <= (n + 1) / 2) {
            if (2 * ++c[a[q]] > d[a[q]]) break;
            q++;
        }
        if (n % 2 && q == (n + 1) / 2 && d[a[q]] % 2) q++;
        if (q > (n + 1) / 2) {
            while (a[q] == a[n - q + 1]) q++;
        }
        ans += 1LL * p * q;
    };
    solve(), reverse(a + 1, a + n + 1), solve();
    printf("%lld\n", ans);
    return 0;
}