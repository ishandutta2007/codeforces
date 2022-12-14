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
    ll a, m;
    cin >> a >> m;

    ll x = m / __gcd(a, m);
    ll ans = x;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            x /= i;
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) ans = ans / x * (x - 1);

    cout << ans << '\n';
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