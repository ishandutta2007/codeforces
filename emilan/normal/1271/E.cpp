#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

ll n, k;

ll countPath(ll y) {
    int len = 0;
    while ((y << len) + (1ll << len) - 1 <= n) len++;

    if (!len) return 0;
    if (y << len > n) return (1ll << len) - 1;

    ll l = 0, r = (1ll << len) - 1;
    while (l < r) {
        ll mi = (l + r + 1) / 2;

        ll cur = (y << len) + mi;

        if (cur <= n) l = mi;
        else r = mi - 1;
    }

    return (1ll << len) + l;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> k;

    ll ans = 1;

    if (countPath(2) + countPath(3) >= k) {
        ll l = 1, r = n / 2;
        while (l < r) {
            ll mi = (l + r + 1) / 2;

            ll cnt = countPath(mi * 2) + countPath(mi * 2 + 1);

            if (cnt >= k) l = mi;
            else r = mi - 1;
        }
        ans = max(ans, l * 2);
    }

    if (countPath(3) >= k) {
        ll l = 1, r = n / 2;
        while (l < r) {
            ll mi = (l + r + 1) / 2;

            ll cnt = countPath(mi * 2 + 1);

            if (cnt >= k) l = mi;
            else r = mi - 1;
        }
        ans = max(ans, l * 2 + 1);
    }

    cout << ans;
}