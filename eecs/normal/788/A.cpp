#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        a[i] = abs(a[i] - a[i + 1]) * (i & 1 ? -1 : 1);
    }
    long long ans = -1e18;
    long long cur = 0, suf_mx = 0, suf_mn = 0;
    for (int i = n - 1; i; i--) {
        cur += a[i];
        if (i & 1) ans = max(ans, -(cur - suf_mx));
        else ans = max(ans, cur - suf_mn);
        suf_mx = max(suf_mx, cur), suf_mn = min(suf_mn, cur);
    }
    printf("%lld\n", ans);
    return 0;
}