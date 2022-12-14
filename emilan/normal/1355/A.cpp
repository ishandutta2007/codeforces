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
    ll a, k;
    cin >> a >> k;

    for (int i = 1; i < min(1000ll, k); i++) {
        ll mn = 9, mx = 0;
        for (ll t = a; t; t /= 10) {
            mn = min(mn, t % 10);
            mx = max(mx, t % 10);
        }
        a += mn * mx;
    }

    cout << a << '\n';
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