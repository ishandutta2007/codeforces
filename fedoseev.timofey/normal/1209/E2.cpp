#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    if (m > n) {
        vector <int> mx(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mx[j] = max(mx[j], a[i][j]);
            }
        }
        vector <int> id(m);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&] (int i, int j) {
            return mx[i] > mx[j];
        });
        vector <vector <int>> b(n);
        for (int t = 0; t < n; ++t) {
            for (int i = 0; i < n; ++i) {
                b[i].push_back(a[i][id[t]]);
            }
        }
        a = b;
        m = n;
    }
    int sz = (1 << n);
    vector <vector <int>> best(m, vector <int> (sz));
    
    for (int j = 0; j < m; ++j) {
        vector <int> cur;
        for (int i = 0; i < n; ++i) cur.push_back(a[i][j]);
        for (int mask = 0; mask < sz; ++mask) {
            for (int t = 0; t < n; ++t) {
                rotate(cur.begin(), cur.begin() + 1, cur.end());
                int sum = 0;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        sum += cur[i];
                    }
                }
                best[j][mask] = max(best[j][mask], sum);
            }
        }
    }
    vector <vector <int>> dp(m + 1, vector <int> (sz));
    for (int i = 1; i <= m; ++i) {
        for (int mask = 0; mask < sz; ++mask) {
            dp[i][mask] = dp[i - 1][mask];
            for (int pmask = mask; pmask > 0; pmask = (pmask - 1) & mask) {
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ pmask] + best[i - 1][pmask]);
            }
        }
    }
    cout << dp[m][sz - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}