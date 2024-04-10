#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int mod = 998'244'353;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}
inline int mul(int x, int y) {
    return x * (ll)y % mod;
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
int fact[5005], invfact[5005];
inline int C(int n, int k) {
    if (k < 0 || k > n || n < 0)
        return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = invfact[0] = 1;
    for (int i = 1; i < 5005; ++i) {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = inv(fact[i]);
    }

    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> ones;
    for (int i = 0; i < n; ++i)
        if (s[i] == '1')
            ones.push_back(i);
    if (k == 0 || k > (int)ones.size()) {
        cout << "1\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i + k <= (int)ones.size(); ++i) {
        int L = (i == 0 ? 0 : ones[i - 1] + 1);
        int R = (i + k == (int)ones.size() ? n - 1 : ones[i + k] - 1);
        add(ans, C(R - L + 1, k));
        if (i + k < (int)ones.size())
            add(ans, mod - C(R - ones[i], k - 1));
    }
    cout << ans << endl;
}