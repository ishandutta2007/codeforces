#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 998244353;
inline int binpow(int x, int deg) {
    int ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = ans * ll(x) % mod;
        deg >>= 1;
        x = x * ll(x) % mod;
    }
    return ans;
}
inline int inv(int x) { return binpow(x, mod - 2); }
inline int mul(int x, int y) { return x * ll(y) % mod; }
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int n, m, a[1005][1005], dp[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    vector<pair<int, pii>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            v.push_back({a[i][j], {i, j}});
        }
    }
    sort(all(v));
    int sum = 0, sumx = 0, sumy = 0;
    for (int i = 0; i < n * m; ) {
        int idx = i;
        while (idx < n * m && v[i].first == v[idx].first)
            ++idx;
        if (i > 0) {
            int divr = inv(i);
            for (int j = i; j < idx; ++j) {
                int cur = (binpow(v[j].second.first, 2) + binpow(v[j].second.second, 2)) % mod;
                add(cur, mul(sum, divr));
                add(cur, mul(mod - mul(sumx, 2 * v[j].second.second), divr));
                add(cur, mul(mod - mul(sumy, 2 * v[j].second.first), divr));
                dp[v[j].second.first][v[j].second.second] = cur;
            }
        }
        for (; i < idx; ++i) {
            add(sumx, v[i].second.second);
            add(sumy, v[i].second.first);
            add(sum, binpow(v[i].second.first, 2));
            add(sum, binpow(v[i].second.second, 2));
            add(sum, dp[v[i].second.first][v[i].second.second]);
        }
    }

    int y, x;
    cin >> y >> x;
    cout << dp[y - 1][x - 1] << endl;
}