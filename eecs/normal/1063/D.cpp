#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, l, r, k, ans = -1;

int main() {
    scanf("%lld %lld %lld %lld", &n, &l, &r, &k);
    l--, r--;
    r = (r - l + n) % n;
    if (n >= 2000) {
        for (ll c = 0; c <= k / n; c++) for (int o : {0, 1}) {
            ll lb = k - r - 1 - o - c * n;
            ll rb = k - r - c * n - 1;
            if (rb < 0) continue;
            ll num = min(n, (rb + o + n - r - 1) / (c + 1));
            ll inc = min(r - (num - (n - r - 1) - o), rb + o + n - r - 1 - num * (c + 1));
            if (num < n - r - 1 + o) {
                num = min(n, rb / c);
                inc = min(r, rb - num * c);
                if (num * (c + 1) + inc >= lb) ans = max(ans, num);
            } else {
                if (num * (c + 1) - (n - r - 1) - o + inc >= lb) ans = max(ans, num);
            }
        }
    } else {
        for (int sl = 0; sl <= r; sl++) for (int o : {0, 1}) {
            for (int sr = 0; sr <= n - r - 1; sr++) {
                ll num = sl + sr + o + n;
                ll c = (max(0LL, k - r - 1 - sl - o) + num - 1) / num;
                if (c * num + sl + r < k) ans = max(ans, num - n);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}