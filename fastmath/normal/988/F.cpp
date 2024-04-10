#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 2007;
const int INF = 1e9 + 7;

int dp[MAXN][MAXN];
int dp1[MAXN];
pair <int, int> a[MAXN];
pair <int, int> b[MAXN];

bool check(int p, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i].first + 1 <= p && p <= a[i].second) return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x, n, m;
    cin >> x >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; ++i) cin >> b[i].first >> b[i].second;

    for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) dp[i][j] = INF;
    for (int i = 0; i < MAXN; ++i) dp1[i] = INF;

    dp1[0] = 0;
    for (int i = 0; i <= x; ++i) {
        bool ch = check(i, n);

        if (i) {
            if (!ch) {
                dp1[i] = dp1[i - 1];
            }
            else {
                for (int j = 0; j < m; ++j) dp1[i] = min(dp1[i], dp[i - 1][j] + b[j].second);        
            }
        }

        for (int j = 0; j < m; ++j) {
            if (i < b[j].first) {
                dp[i][j] = INF;
            }
            else if (i == b[j].first) {
                dp[i][j] = dp1[i];
            }
            else if (b[j].first < i) {
                dp[i][j] = dp[i - 1][j] + b[j].second;
            }
            dp1[i] = min(dp1[i], dp[i][j]);
        }
    }

    if (dp1[x] == INF) cout << "-1\n";
    else cout << dp1[x] << '\n';

    return 0;
}