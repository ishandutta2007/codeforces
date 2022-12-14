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

const ll mod = 998244353;
const int maxn = 50;
ll inv[maxn], fact[maxn], finv[maxn];

void solve() {
    ll d;
    int q;
    cin >> d >> q;

    vt<ll> p;
    for (ll i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            while (d % i == 0) d /= i;
            p.push_back(i);
        }
    }
    if (d != 1) p.push_back(d);
    int m = sz(p);

    while (q--) {
        ll u, v;
        cin >> u >> v;

        int sum_neg = 0, sum_pos = 0;
        ll ans = 1;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            while (u % p[i] == 0) {
                u /= p[i];
                cnt--;
            }

            while (v % p[i] == 0) {
                v /= p[i];
                cnt++;
            }

            if (cnt < 0) sum_neg -= cnt;
            else sum_pos += cnt;
            ans = ans * finv[abs(cnt)] % mod;
        }

        ans = ans * fact[sum_neg] % mod * fact[sum_pos] % mod;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }

    fact[0] = finv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}