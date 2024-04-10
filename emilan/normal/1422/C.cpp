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
    string s;
    cin >> s;
    int n = sz(s);

    vt<ll> ten(n);
    ten.back() = 1;
    for (int i = n - 1; i > 0; i--) {
        ten[i - 1] = ten[i] * 10 % mod;
    }

    ll ans = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
        int cur = s[i] - '0';
        ans = (ans + 
            (i * ll(i + 1) / 2 * cur +
             ll(n - i) * acc)
            % mod * ten[i]) % mod;
        acc += cur;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}