#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr  LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
LL f(int h, int s) {
    if (s) return 4 * (power(2, 2 * h - 2) + mod - power(mod - 2, h - 1)) % mod * power(3, mod - 2) % mod;
    return 2 * (power(2, 2 * h - 1) + power(mod - 2, h - 1)) % mod * power(3, mod - 2) % mod;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<LL> w;
    map<char, int> mp = {{'w', 0}, {'y', 0}, {'g', 1}, {'b', 1}, {'r', 2}, {'o', 2}};
    map<LL, int> s;
    for (int i = 0; i < m; i += 1){
        LL u;
        string c;
        cin >> u >> c;
        s[u] = mp[c[0]];
        w.push_back(u);
    }
    if (not s.count(1)) {
        w.push_back(1);
        s[1] = -1;
    }
    for (int i = 0; i < m; i += 1)
        for (int j = i + 1; j < m; j += 1) {
            LL u = w[i], v = w[j];
            while (u != v) {
                if (u > v) u /= 2;
                else v /= 2;
            }
            if (not s.count(u)) {
                w.push_back(u);
                s[u] = -1;
            }
        }
    sort(w.begin(), w.end(), greater<LL>());
    int k = w.size();
    vector<int> par(k, -1), ds(k, -1);
    for (int i = 0; i < k; i += 1)
        for (int j = i + 1; j < k; j += 1) {
            LL u = w[i];
            for (ds[i] = 0; u > w[j]; u >>= 1) ds[i] += 1;
            if (u == w[j]) {
                par[i] = j;
                break;
            }
        }
    vector<vector<LL>> dp(k, vector<LL>(3, 1));
    vector<LL> size(k);
    for (int i = 0; i < k; i += 1) {
        int h = 0;
        for (LL u = w[i]; u < (1LL << n); u <<= 1) h += 1;
        size[i] += (1LL << h) - 2;
        if (par[i] != -1) size[par[i]] -= (1LL << h) - 1 + ds[i] - 1;
        for (int j = 0; j < 3; j += 1)
            dp[i][j] = dp[i][j] * power(4, size[i]) % mod;
        if (s[w[i]] != -1) {
            for (int j = 0; j < 3; j += 1) 
                if (j != s[w[i]]) dp[i][j] = 0;
                else dp[i][j] = dp[i][j] * power(2, mod - 2) % mod;
        }
        if (par[i] != -1) {
            for (int p = 0; p < 3; p += 1){
                LL s = 0;
                for (int j = 0; j < 3; j += 1)
                    s = (s + dp[i][j] * f(ds[i], j == p)) % mod;
                dp[par[i]][p] = dp[par[i]][p] * s % mod;
            }
        }
        //cout << w[i] << " - " << size[i] << ": ";
        //for (LL x : dp[i]) cout << x << " "; cout << "\n";
    }
    cout << (dp.back()[0] + dp.back()[1] + dp.back()[2]) * 2 % mod << "\n";
    return 0;
}