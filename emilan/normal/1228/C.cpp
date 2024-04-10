#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      (a).begin(), (a).end()
#define RALL(a)     (a).rbegin(), (a).rend()

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

const ll kMod = 1e9 + 7;

ll mod_pow(ll b, ll e) {
    ll r = 1;
    for (; e > 0; e /= 2, b = b * b % kMod) {
        if (e & 1) r = r * b % kMod;
    }
    return r;
}

void solve() {
    int x;
    ll n;
    cin >> x >> n;

    ll ans = 1;
    auto f = [&](int p) {
        for (i128 i = p; i <= n; i *= p) {
            ans = ans * mod_pow(p, n / ll(i)) % kMod;
        }
    };

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            f(i);
            x /= i;
            for (; x % i == 0; x /= i);
        }
    }
    if (x != 1) f(x);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}