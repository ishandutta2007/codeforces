#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

const int mod = 1000000007;

inline int binpow(int x, int deg) {
    int ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = ans * (ll)x % mod;
        deg >>= 1;
        x = x * (ll)x % mod;
    }
    return ans;
}

inline int inv(int x) { return binpow(x, mod - 2); }

inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int dp[105], dp2[105];

int main() {
    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<pair<ll, int>> v;
    for (ll i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            ++cnt;
        }
        if (cnt)
            v.emplace_back(i % mod, cnt);
    }
    if (n > 1)
        v.emplace_back(n % mod, 1);

    ll ans = 1;
    for (auto qqq : v) {
        int mx = qqq.second;
        fill(dp, dp + mx + 1, 0);
        dp[mx] = 1;
        for (int i = 1; i <= k; ++i) {
            fill(dp2, dp2 + mx + 1, 0);
            for (int from = 0; from <= mx; ++from) {
                const ll mult = inv(from + 1);
                for (int to = 0; to <= from; ++to) {
                    add(dp2[to], dp[from] * mult % mod);
                }
            }
            copy(dp2, dp2 + mx + 1, dp);
        }

        ll cur = 1;
        ll addon = 0;
        for (int j = 0; j <= mx; ++j) {
            addon = (addon + cur * dp[j]) % mod;
            cur = cur * qqq.first % mod;
        }
        ans = ans * addon % mod;
    }
    cout << ans << endl;
}