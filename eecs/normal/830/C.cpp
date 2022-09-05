#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll K, ans, a[110];

int main() {
    scanf("%d %lld", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), K += a[i];
    }
    ll mx = *max_element(a + 1, a + n + 1) - 1;
    for (ll l = 1, r; l <= mx; l = r + 1) {
        r = LLONG_MAX;
        ll s = 0;
        for (int i = 1; i <= n; i++) if (a[i] - 1 >= l) {
            s += (a[i] - 1) / l;
            r = min(r, (a[i] - 1) / ((a[i] - 1) / l));
        }
        ll t = K / (s + n);
        if (l <= t) ans = max(ans, min(t, r));
    }
    if (mx < K / n) ans = max(ans, K / n);
    printf("%lld\n", ans);
    return 0;
}