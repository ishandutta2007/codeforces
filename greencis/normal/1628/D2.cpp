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

int fact[1001001];
int invfact[1001001];
int deg2[1001001];

inline int C(int n, int k) {
    if (k < 0 || k > n || n < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = invfact[0] = 1;
    deg2[0] = 1;
    for (int i = 1; i < 1001001; ++i) {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = inv(fact[i]);
        deg2[i] = mul(deg2[i - 1], 2);
    }

    const int inv4 = inv(4);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m, k;
        cin >> n >> m >> k;
        --m;

        int ans = C(n, m);
        for (int i = 1; i <= n && i <= m; ++i) {
            int cur = mul(i + 3, deg2[i]);
            cur = mul(cur, C(n - i, m - i));
            cur = mul(cur, inv4);
            ans = add(ans, cur);
        }
        ans = mul(ans, inv(binpow(2, n - 1)));
        ans = mul(ans, k);
        cout << ans << '\n';
    }
}