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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    ll r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<ll> h(n), k(n);
    for (int i = 0; i < n; i++) {
        h[i] = min((a[i] + 2) * r1, r1 + r2);
        k[i] = min(a[i] * r1 + r3, h[i] + 2 * d);
    }

    vt<ll> s(n);
    s.back() = k.back();
    for (int i = n - 2; i >= 0; i--) {
        s[i] = s[i + 1] + h[i] + 2 * d;
    }

    vt<ll> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + k[i - 1] + d;
        if (i > 1) p[i] = min(p[i],
                p[i - 2] + h[i - 2] + h[i - 1] + 4 * d);
    }

    ll ans = p.back() - d;
    for (int i = 0; i < n; i++) {
        ans = min(ans, p[i] + s[i]);
    }

    cout << ans;
}