#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
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

int fact[100100];

inline int C(int n, int k) {
    if (k < 0 || k > n || n < 0) return 0;
    return mul(fact[n], mul(inv(fact[k]), inv(fact[n - k])));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < 100100; ++i)
        fact[i] = mul(fact[i - 1], i);

    int n;
    cin >> n;
    int b1 = 0, w1 = 0, b2 = 0, w2 = 0;
    string s;
    int bb = 0, ww = 0, bw = 0, wb = 0;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        v[i] = s;
        b1 += s[0] == 'B';
        w1 += s[0] == 'W';
        b2 += s[1] == 'B';
        w2 += s[1] == 'W';
        bb += s == "BB";
        bw += s == "BW";
        wb += s == "WB";
        ww += s == "WW";
    }

    int ans = 0;
    for (int x = 0; x <= n - b1; ++x) {
        int new_b1 = b1 + x;
        int new_w1 = n - new_b1;
        if (b1 > new_b1 || w1 > new_w1 || b2 > new_w1 || w2 > new_b1)
            continue;
        int cur = C(n - b1 - w1, x);
        cur = mul(cur, C(n - b2 - w2, new_w1 - b2));
        add(ans, cur);
    }

    if (bb == 0 && ww == 0) {
        int cur = 1;
        int all_bw = 1, all_wb = 1;
        for (int i = 0; i < n; ++i) {
            if (v[i][0] == 'B' || v[i][1] == 'W') all_wb = 0;
            if (v[i][0] == 'W' || v[i][1] == 'B') all_bw = 0;
            if (v[i] == "??")
                cur = mul(2, cur);
        }
        add(cur, mod - all_bw);
        add(cur, mod - all_wb);
        add(ans, mod - cur);
    }

    cout << ans << '\n';
}