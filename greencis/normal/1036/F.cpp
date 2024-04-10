#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

inline ll binpow(ll x, ll deg) {
    if (pow(x, deg) > 2e18)
        return 2e18;
    ll ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans *= x;
        deg >>= 1;
        x *= x;
    }
    return ans;
}

inline ll root(ll x, ll deg) {
    ll ans = pow(x, 1.0 / deg);
    while (binpow(ans, deg) < x) ++ans;
    while (binpow(ans, deg) > x) --ans;
    return ans;
}

int t, mobius[60];
ll x;

int main() {
    ios_base::sync_with_stdio(false);

    mobius[1] = 1;
    for (int i = 2; i <= 59; ++i) {
        int sq = 0;
        int cnt = 0;
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                ++cnt;
                int cur = 0;
                while (x % j == 0)
                    x /= j, ++cur;
                if (cur > 1)
                    sq = 1;
            }
        }
        if (x > 1)
            ++cnt;
        mobius[i] = (sq ? 0 : cnt % 2 ? -1 : 1);
    }

    cin >> t;
    while (t--) {
        cin >> x;
        ll ans = x - 1;
        for (int i = 2; i <= 59 && (1LL << i) <= x; ++i)
            ans += mobius[i] * (root(x, i) - 1);
        cout << ans << "\n";
    }
}