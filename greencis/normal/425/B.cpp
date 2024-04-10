//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    int ans = 1e9;
    for (int zzz = 0; zzz < 2; ++zzz) {
        for (int z = 0; z < n; ++z) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                int tmp = 0;
                for (int j = 0; j < m; ++j)
                    tmp += v[i][j] != v[z][j];
                cur += min(tmp, m - tmp);
            }
            ans = min(ans, cur);
        }
        if (n <= k) {
            for (int mask = 1 << n; mask--; ) {
                int cur = 0;
                for (int i = 0; i < n; ++i)
                    cur += ((mask >> i) & 1);
                for (int j = 1; j < m; ++j) {
                    int tmp = 0;
                    for (int i = 0; i < n; ++i)
                        tmp += v[i][j] != (v[i][0] ^ ((mask >> i) & 1));
                    cur += min(tmp, n - tmp);
                }
                ans = min(ans, cur);
            }
        }
        vector<vector<int>> u(m, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                u[j][i] = v[i][j];
        swap(u, v);
        swap(n, m);
    }
    if (ans > k) ans = -1;
    cout << ans << endl;
}