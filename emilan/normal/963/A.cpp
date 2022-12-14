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

const ll mod = 1e9 + 9;

ll mod_pow(ll b, int e) {
    ll r = 1;
    for (; e; e >>= 1, b = b * b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

ll mod_inv(ll a, ll b = mod) {
    return a > 1 ? b - mod_inv(b % a, a) * b / a : 1;
}

void solve() {
    int n, k;
    ll a, b;
    string s;
    cin >> n >> a >> b >> k >> s;

    ll base = 0;
    for (int i = 0; i < k; i++) {
        base = (
            base
            + (s[i] == '+' ? 1 : mod - 1)
            * mod_pow(a, n - i) % mod
            * mod_pow(b, i)
        ) % mod;
    }

    ll ratio = mod_pow(mod_inv(a), k) * mod_pow(b, k) % mod;
    ll ans;
    if (ratio == 1) ans = base * (n + 1) / k % mod;
    else {
        ans = base
            * (mod_pow(ratio, (n + 1) / k) - 1) % mod
            * mod_inv(ratio - 1) % mod;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}