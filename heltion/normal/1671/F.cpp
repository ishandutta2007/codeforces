#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mx = 12;
    vector a(mx + 1, vector(mx, vector<LL>(mx)));
    for (int n = 2; n <= mx; n += 1) {
        vector<int> v(n), p(n);
        function<void(int, int, int)> DFS = [&](int i, int mxx, int k) {
            if (k >= mx) return;
            if (i == n) {
                int x = 0;
                for (int i = 1; i < n; i += 1)
                    if (p[i] < p[i - 1])
                        x += 1;
                a[n][k][x] += 1;
                return;
            }
            if (i and i != n and mxx < i) return;
            for (int j = 0; j < n; j += 1)
                if (not v[j]) {
                    v[j] = 1;
                    p[i] = j;
                    int nk = k;
                    for (int x = j + 1; x < n; x += 1)
                        if (v[x]) nk += 1;
                    DFS(i + 1, max(mxx, j), nk);
                    v[j] = 0;
                }
        };
        DFS(0, 0, 0);
    }
    vector f(mx, vector<map<pair<int, int>, int>>(mx));
    vector<int> v;
    LL ans = 0, c = 0;
    function<void(int)> DFS = [&](int s) {
        c += 1;
        vector dp(mx, vector<LL>(mx));
        dp[0][0] = 1;
        for (int i : v) {
            vector ndp(mx, vector<LL>(mx));
            for (int k = 0; k < mx; k += 1)
                for (int x = 0; x < mx; x += 1)
                    for (int pk = 0; pk < k; pk += 1)
                        for (int px = 0; px < x; px += 1)
                            ndp[k][x] = (ndp[k][x] + dp[pk][px] * a[i][k - pk][x - px]) % mod;
            dp.swap(ndp);
        }
        if (22 - s == 6 and v.size() == 2) {
            for (int k = 0; k <= 3; k += 1)
                for (int x = 0; x <= 1; x += 1)
                    //cout << k << " " << x << " " << dp[k][x] << "\n";
                    ;
        }
        for (int k = 1; k < mx; k += 1)
            for (int x = 1; x < mx; x += 1) 
                if (dp[k][x]) {
                    f[k][x][{v.size(), 22 - s}] = (f[k][x][{v.size(), 22 - s}] + dp[k][x]) % mod;
                }
        for (int i = 2; i <= mx and i <= s; i += 1) {
            v.push_back(i);
            DFS(s - i);
            v.pop_back();
        }
    };
    DFS(22);
    vector<LL> ff(mx * 2), g(mx * 2);
    for (int i = 0; i < mx * 2; i += 1)
        g[i] = power(ff[i] = i ? ff[i - 1] * i % mod : 1, mod - 2);
    auto C = [&](LL x, LL y) {
        if (y < 0 or x < y) return 0LL;
        LL res = 1;
        for (LL i = x - y + 1; i <= x; i += 1)
            res = res * i % mod;
        return res * g[y] % mod;
    };
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k, x;
        cin >> n >> k >> x;
        LL ans = 0;
        for (auto& [p, c] : f[k][x]) {
            auto [a, b] = p;
            //if (C(n - b + a, a)) cout << a << " " << b << " " << k << " " << x << " " << c << " " << C(n - b + a, a) << "\n";
            ans += C(n - b + a, a) * c % mod;
        }
        cout << ans % mod << "\n";
    }   
}