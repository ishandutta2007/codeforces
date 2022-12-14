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
    ll n, k;
    cin >> n >> k;
    if (k > 1.5e5) return void(cout << -1);

    ll sum = k * (k + 1) / 2;
    ll ans = -1;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (sum <= n / i) ans = max(ans, i);
            if (sum <= i) ans = max(ans, n / i);
        }
    }

    if (~ans) {
        for (int i = 1; i < k; i++) cout << i * ans << ' ';
        cout << n - ans * (k - 1) * k / 2;
    } else cout << -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}