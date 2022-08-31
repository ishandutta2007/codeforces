#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int maxn = 2100;
int cnt[2][maxn][26];
int dp[maxn][maxn];
string s[2];

int solve() {
    int n = s[0].size();
    forn(i, 2) forn(j, n + 1) forn(k, 26) cnt[i][j][k] = 0;
    forn(i, 2) forn(j, n) forn(k, 26) cnt[i][j + 1][k] = cnt[i][j][k] + (s[i][j] == 'a' + k);
    bool ok = true;
    forn(k, 26) ok &= cnt[0][n][k] == cnt[1][n][k];
    if (!ok) return -1;
    forn(i, n + 1) forn(j, n + 1) dp[i][j] = 0;
    forn(i, n + 1) forn(j, n + 1) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        if (s[0][i] == s[1][j]) {
            bool ok = true;
            forn(k, 26) ok &= cnt[0][i][k] <= cnt[1][j][k];
            if (ok) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    return n - dp[n][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n >> s[0] >> s[1];
        cout << solve() << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}