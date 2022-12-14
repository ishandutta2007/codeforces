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

void solve() {
    ll n, h;
    cin >> n >> h;

    auto f = [&](ll x) {
        ll s = min(x, h - 1);
        ll cnt = s * (s + 1) / 2;
        if (x >= h) {
            ll r = x - h + 1;
            cnt += r * (h - 1);
            cnt += (r / 2) * (r / 2 + 1);
            if (r & 1) cnt += r / 2 + 1;
        }

        return cnt >= n;
    };

    ll l = 0, r = 2e9 + 5;
    while (l + 1 < r) {
        ll mi = (l + r) / 2;
        if (!f(mi)) l = mi;
        else r = mi;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}