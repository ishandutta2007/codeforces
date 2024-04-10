#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

ll inf = 1ll << 62;

void solve() {
    ll x, y;
    cin >> x >> y;
    vt<ll> c(6);
    for (ll &z : c) cin >> z;

    ll mx = max(x, y), mn = min(x, y);

    auto calc = [&](ll s) {
        ll ret = 0;

        if (s > 0) ret += c[0] * s;
        else ret -= c[3] * s;

        ll cx = x - s, cy = y - s;

        if (cx > 0) ret += c[5] * cx;
        else ret -= c[2] * cx;

        if (cy > 0) ret += c[1] * cy;
        else ret -= c[4] * cy;

        return ret;
    };
    cout << min({calc(mx), calc(mn), calc(0)}) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}