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

const ll mod = 1e9 + 7,
         iv2 = 5e8 + 4;

void solve() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    ll sqn = ll(sqrt(n));

    for (int i = 1; i <= min(sqn, m); i++) {
        ans = (ans + n % i) % mod;
    }

    for (int i = 1; i <= n / sqn; i++) {
        ll head = max(n / (i + 1), sqn) + 1,
           tail = min(n / i, m),
           cnt = tail - head + 1;
        if (cnt <= 0) continue;

        cnt %= mod;
        ans = (ans +
            n % mod * cnt -
            i * cnt % mod * ((head + tail) % mod) % mod * iv2
        ) % mod;
    }

    ans = (ans + n % mod * (max(m - n, 0ll) % mod)) % mod;

    if (ans < 0) ans += mod;
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