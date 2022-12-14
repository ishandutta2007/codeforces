#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

// dp[shield][position][moves]
int dp[81][81][2100];

inline int sqr(int x) { return x * x; }

const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<int> p;
    for (int i = 0; i < n; i++) {
        if (a[i]) p.push_back(i + 1);
    }
    int m = sz(p);

    memset(dp, inf, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < m; i++) {
        for (int u = i; u < n - m + i + 1; u++) {
            for (int k = 0; k < 2000; k++) {
                for (int v = u + 1; v < n - m + i + 2; v++) {
                    dp[i + 1][v][k + abs(v - p[i])] = min(
                        dp[i][u][k] + sqr(v - u - 1),
                        dp[i + 1][v][k + abs(v - p[i])]
                    );
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= n * (n - 1) / 2; i++) {
        if (i < 2000) {
            for (int j = m; j <= n; j++) {
                ans = min(dp[m][j][i] + sqr(n - j), ans);
            }
        }
        cout << (sqr(n - m) - ans) / 2 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}