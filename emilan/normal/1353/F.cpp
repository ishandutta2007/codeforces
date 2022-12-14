#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

ll dp[100][100], h[100][100];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, m;
        cin >> n >> m;
        set<ll, greater<ll>> heights;
        rep(i, n) rep(j, m) {
            cin >> h[i][j];
            h[i][j] -= i + j;
            if (h[i][j] <= h[0][0]) heights.insert(h[i][j]);
        }

        rep(i, n) fill(dp[i], dp[i] + m, 1ll << 61);
        dp[0][0] = h[0][0];
        ll mn = 1ll << 61;
        for (ll low : heights) {
            rep(i, n) rep(j, m) {
                if (h[i][j] < low) continue;
                if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + h[i][j]);
                if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + h[i][j]);
            }
            mn = min(mn, dp[n - 1][m - 1] - low * (n + m - 1));
        }

        cout << mn << '\n';
    }
}