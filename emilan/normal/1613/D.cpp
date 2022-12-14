#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
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

ll mod_norm(ll x) {
    x %= kMod;
    if (x < 0) x += kMod;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<array<ll, 2>> dp_(n + 3);
    auto dp = [&](int i, int j) -> ll& {
        return dp_[i + 1][j];
    };
    dp(0, 0) = 1;
    for (int x : a) {
        tie(
            dp(x - 1, 1),
            dp(x + 1, 0),
            dp(x + 1, 1)
        ) = tuple{
            mod_norm(2 * dp(x - 1, 1) + dp(x - 1, 0)),
            mod_norm(2 * dp(x + 1, 0) + dp(x, 0)),
            mod_norm(2 * dp(x + 1, 1))
        };
    }

    ll ans = kMod - 1;
    for (auto [x, y] : dp_) ans = mod_norm(ans + x + y);
    cout << ans << '\n';
    cerr << "=====\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}