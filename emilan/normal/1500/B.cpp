#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// array<ll, 3> egcd(ll x, ll y) {
//     ll xs = 1, xt = 0, ys = 0, yt = 1;
//     while (y != 0) {
//         ll q = x / y;
//         tie(x, y) = make_pair(y, x - q * y);
//         tie(xs, ys) = make_pair(ys, xs - q * ys);
//         tie(xt, yt) = make_pair(yt, xt - q * yt);
//     }
// 
//     return {x, xs, xt};
// }

ll inv(ll x, ll m) {
    ll xs = 1, ms = 0;
    while (m != 0) {
        ll q = x / m;
        tie(x, m) = make_pair(m, x - q * m);
        tie(xs, ms) = make_pair(ms, xs - q * ms);
    }

    return xs;
}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<int> idx(2 * max(n, m) + 1, -1);
    for (int i = 0; i < m; i++) {
        idx[b[i]] = i;
    }

    int Gcd = gcd(n, m);
    int N = n / Gcd, M = m / Gcd;
    vector<int> gd(n, -1);
    for (int i = 0; i < n; i++) {
        int j = idx[a[i]];
        if (j == -1 || (j - i + n) % Gcd != 0) continue;

        gd[i] = inv(N, M) * (j - i) / Gcd % M;
        if (gd[i] < 0) gd[i] += M;
    }

    ll l = -1, r = 2e18;
    while (l + 1 < r) {
        ll mi = (l + r) / 2;
        
        ll days = 0;
        for (int i = 0; i < n; i++) {
            ll cnt = (mi + n - i) / n;
            days += cnt;
            if (cnt > 0 && gd[i] != -1) {
                days -= (cnt - 1 + M - gd[i]) / M;
            }
        }

        if (days >= k) r = mi;
        else l = mi;
    }

    cout << r + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}