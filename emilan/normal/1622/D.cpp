#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

const ll kMod = 998244353;

ll mod_pos(ll x) {
    x %= kMod;
    if (x < 0) x += kMod;
    return x;
}

ll solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 0) return 1;

    vector<ll> inv(n + 1, 1);
    vector<ll> fact(n + 1, 1);
    vector<ll> finv(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
        fact[i] = fact[i - 1] * i % kMod;
        finv[i] = finv[i - 1] * inv[i] % kMod;
    }

    auto C = [&](int n_, int r_) {
        return fact[n_] * finv[n_ - r_] % kMod * finv[r_] % kMod;
    };

    vector<int> pos{-1};
    REP(i, n) {
        if (s[i] == '1') pos.push_back(i);
    }
    pos.push_back(n);

    if (SZ(pos) < k + 2) return 1;

    ll ans = 0;
    for (int l = 1; l < SZ(pos) - k; l++) {
        for (int i = pos[l - 1] + 1; i + k <= pos[l + k]; i++) {
            if (i != pos[l]) ans = (ans + C(pos[l + k] - i - 1, k - 1));
        }
    }
    ans = (ans + C(pos[SZ(pos) - 1] - pos[SZ(pos) - k - 1] - 1, k - 1)) % kMod;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << '\n';
}