#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
const int M = 207;

const ll Inf = 2e18;

ll dp[N][M];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> s(k), t(k), d(k), w(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i] >> t[i] >> d[i] >> w[i];
        --s[i], --t[i];
    }
    vector <pair <int, int>> mx(n + 1, make_pair(-1, -1));
    vector <vector <pair <int, int>>> whob(n), whoe(n);
    for (int i = 0; i < k; ++i) {
        whob[s[i]].push_back({w[i], d[i]});
        whoe[t[i]].push_back({w[i], d[i]});
    }
    multiset <pair <int, int>> cur;
    for (int i = 0; i < n; ++i) {
        for (auto p : whob[i]) {
            cur.insert(p);
        }
        if (!cur.empty()) mx[i] = (*cur.rbegin());
        for (auto p : whoe[i]) {
            cur.erase(cur.find(p));
        }
    }
    vector <pair <int, int>> cr = mx;
    for (int i = n - 2; i >= 0; --i) {
        if (mx[i] == make_pair(-1, -1)) {
            mx[i] = mx[i + 1];
        }
    }
    vector <ll> sum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        if (mx[i] == make_pair(-1, -1)) {
            continue;
        }
        sum[i] = mx[i].first + sum[mx[i].second];
    }  
    for (int i = 0; i < n; ++i) {
        dp[i][0] = sum[i];
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = Inf;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= m; ++j) {
            if (cr[i].first == -1) {
                dp[i][j] = dp[i + 1][j];
            }
            else {
                int a = cr[i].first;
                int b = cr[i].second;
                dp[i][j] = min(dp[i][j], a + dp[b][j]);
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }
    }
    cout << dp[0][m] << '\n';
}