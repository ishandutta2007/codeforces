#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int mod = 1'000'000'007;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod)
        z -= mod;
    return z;
}
inline int sub(int x, int y) {
    return add(x, mod - y);
}
inline int mul(int x, int y) {
    return int(x * (ll)y % mod);
}
inline int binpow(int x, int deg) {
    int ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = mul(ans, x);
        deg >>= 1;
        x = mul(x, x);
    }
    return ans;
}
inline int inv(int x) {
    return binpow(x, mod - 2);
}

int dp[2005][2005]; // moves/how many additions must Bob do

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int inv2 = inv(2);
    for (int moves = 1; moves <= 2000; ++moves) {
        for (int addons = 0; addons <= moves; ++addons) {
            if (addons == 0)
                dp[moves][0] = dp[moves - 1][0];
            else if (addons == moves)
                dp[moves][moves] = add(dp[moves - 1][moves - 1], 1);
            else {
                //dp[moves][addons] = min(dp[moves - 1][addons - 1] + x, dp[moves - 1][addons] - x);
                //ld x = (dp[moves - 1][addons] - dp[moves - 1][addons - 1]) / 2;
               // x = clamp<ld>(0, x, 1);
                dp[moves][addons] = mul(inv2, add(dp[moves - 1][addons], dp[moves - 1][addons - 1]));
                //min(dp[moves - 1][addons - 1] + x, dp[moves - 1][addons] - x);
            }
        }
    }

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << setprecision(17) << fixed << mul(dp[n][m], k) << '\n';
    }
}