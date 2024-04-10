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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<int>> dp0(n, vector<int>(m));
        vector<vector<int>> dp1(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                dp0[i][j] = a[i][j] + min(i == 0 ? inf : dp0[i-1][j], j == 0 ? inf : dp0[i][j-1]);
                dp1[i][j] = a[i][j] + max(i == 0 ? -inf : dp1[i-1][j], j == 0 ? -inf : dp1[i][j-1]);
                if (i == 0 && j == 0)
                    dp0[i][j] = dp1[i][j] = a[i][j];
            }
        debug(dp0);
        debug(dp1);
        cout << (dp0[n-1][m-1] <= 0 && dp1[n-1][m-1] >= 0 && (n+m)%2 == 1 ? "YES" : "NO") << "\n";
    }
}