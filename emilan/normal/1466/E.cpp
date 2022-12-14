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

const ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vt<ll> a(n);
    vt<int> bits(60);
    for (ll &x : a) {
        cin >> x;
        for (int i = 0; i < 60; i++) {
            bits[i] = (bits[i] + (x & 1ll << i)) % mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll l = a[i] % mod * n % mod,
           r = 0;
        for (int j = 0; j < 60; j++) {
            if (a[i] & 1ll << j) r = (r + bits[j]) % mod;
            else l = (l + bits[j]) % mod;
        }
        ans = (ans + l * r) % mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}