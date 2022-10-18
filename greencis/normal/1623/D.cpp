#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int mod = 1'000'000'007;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m, yb, xb, yd, xd, p;
        cin >> n >> m >> yb >> xb >> yd >> xd >> p;
        p = mul(p, inv(100));
        int q = mod + 1 - p;
        int dy = 1, dx = 1;
        map<pair<pii, pii>, int> mp;
        vector<int> clean;
        int period;
        for (int mv = 0; ; ++mv) {
            if (yb + dy > n || yb + dy < 1) dy *= -1;
            if (xb + dx > m || xb + dx < 1) dx *= -1;
            int& rf = mp[{{yb, xb}, {dy, dx}}];
            if (rf) {
               // cerr << yd << " " << xd << endl;
                assert(rf == 1);
                period = mv;
                break;
            }
            rf = mv + 1;
            if (yb == yd || xb == xd)
                clean.push_back(mv);
            yb += dy;
            xb += dx;
        }
        int k = clean.size();
        int qk = binpow(q, k);
        int c = inv(mod + 1 - qk);
        int ans = 0;
        int qkmult = 1;
//        cerr << k << endl;
//        for (int x : clean)
//            cerr << x << " ";
//        cerr << endl;
        for (int i = 0; i < k; ++i) {
            int cur = mul(c, clean[i]);
            int cur2 = mul(mul(c, c), mul(period, qk));
            add(cur, cur2);
            cur = mul(cur, qkmult);
            add(ans, cur);
            qkmult = mul(qkmult, q);
        }
        ans = mul(ans, p);
        cout << ans << '\n';
    }
}