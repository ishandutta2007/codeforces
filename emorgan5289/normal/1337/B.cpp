#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int x, n, m; fin >> x >> n >> m;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        bool v = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                dp[i][j] = inf;
                if (max(i, j) == 0)
                    dp[i][j] = x;
                if (i != 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j]/2 + 10);
                if (j != 0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1]-10);
                v |= dp[i][j] <= 0;
            }
        cout << (v ? "YES" : "NO") << "\n";
    }
}