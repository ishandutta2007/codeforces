#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10010;
int n;
ll ans, h[maxn], pre[maxn], suf[maxn], mn[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
    }
    // a * x + b * y
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        ll mn = LLONG_MAX;
        for (int j = i; j; j--) {
            mn = min(mn, h[j]);
            pre[i] = max(pre[i], (i - j + 1) * mn);
        }
    }
    for (int i = n; i; i--) {
        suf[i] = suf[i + 1];
        ll mn = LLONG_MAX;
        for (int j = i; j <= n; j++) {
            mn = min(mn, h[j]);
            suf[i] = max(suf[i], (j - i + 1) * mn);
        }
    }
    for (int i = 0; i <= n; i++) {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    auto solve = [&]() {
        // a * x + b * (x + y) + c * (x/y): fix x + y
        vector<ll> cand;
        for (int i = 1; i <= n; i++) {
            cand.push_back(h[i]);
        }
        sort(cand.begin(), cand.end(), greater<>());
        for (int i = 1; i <= n; i++) {
            int l = i, r = i;
            while (l > 1 && h[l - 1] >= h[i]) l--;
            while (r < n && h[r + 1] >= h[i]) r++;
            mn[l] = h[i];
            int lb = l, rb = r;
            for (int j = l - 1; j; j--) {
                if (j < l) mn[j] = min(mn[j + 1], h[j]);
            }
            for (ll x : cand) {
                while (lb > 1 && h[lb - 1] >= x) lb--;
                while (rb < n && h[rb + 1] >= x) rb++;
                ans = max(ans, (l - lb) * x + (r - l + 1) * h[i] + (rb - r) * x);
            }
            for (int k = r + 1; k <= n; k++) {
                mn[k] = min(k == r + 1 ? LLONG_MAX : mn[k - 1], h[k]);
            }
            // y <= h[i] - x
            ll mx = 0;
            lb = l, rb = n;
            for (ll x : cand) if (x <= h[i]) {
                while (lb > 1 && h[lb - 1] >= x) lb--;
                // for (rb = r + 1; rb <= n; rb++) mx = max(mx, (rb - l + 1) * min(mn[rb], h[i] - x));
                while (rb > r && x + mn[rb] <= h[i]) mx = max(mx, (rb - l + 1) * mn[rb]), rb--;
                if (rb > r) mx = max(mx, (rb - l + 1) * (h[i] - x));
                ans = max(ans, (r - lb + 1) * x + mx);
            }
        }
    };
    solve();
    reverse(h + 1, h + n + 1), solve();
    printf("%lld\n", ans);
    return 0;
}