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

// Mod combinatorics toolkit
vt<ll> inv, fact, finv;

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * finv[r] % mod * finv[n - r] % mod;
}

// Precalculate up to (including) n
void init_comb(int n, ll m) {
    inv.resize(n + 1);
    fact.resize(n + 1);
    finv.resize(n + 1);

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++)
        fact[i] = fact[i - 1] * i % m;

    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = m - m / i * inv[m % i] % m;

    finv[0] = finv[1] = 1;
    for (int i = 2; i <= n; i++)
        finv[i] = finv[i - 1] * inv[i] % m;
}

ll mod_exp(ll b, int e) {
    ll r = 1;
    for (; e; e >>= 1, b = b * b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n;

    if (ll _k; cin >> _k && _k >= n) return void(cout << 0);
    else k = int(_k);

    ll ans = 0;
    for (int i = 0; i < n - k; i++) {
        ll d = C(n - k, i) * mod_exp(n - k - i, n) % mod;
        if (~i & 1) ans += d;
        else ans -= d;
    }
    ans %= mod;
    if (ans < 0) ans += mod;

    if (k) ans = ans * C(n, k) * 2 % mod;

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    init_comb(2e5 + 1, mod);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}