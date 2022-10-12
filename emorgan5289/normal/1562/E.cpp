#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 5005;
int lcp[N][N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s; s += '$';
        for (int i = 0; i < n; i++)
            lcp[i][n] = lcp[n][i] = 0;
        for (int i = n-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--)
                lcp[i][j] = s[i] == s[j] ? lcp[i+1][j+1]+1 : 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            fill(dp[i], dp[i]+n, 1);
            for (int j = 0; j < i; j++)
                if (s[j+lcp[i][j]] < s[i+lcp[i][j]])
                    cmax(dp[i][i+lcp[i][j]], dp[j][n-1]+1);
            for (int j = i+1; j < n; j++)
                cmax(dp[i][j], dp[i][j-1]+1);
            cmax(ans, dp[i][n-1]);
        }
        cout << ans << "\n";
    }
}