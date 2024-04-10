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
        int n; cin >> n;
        vector<int> a(n+2);
        for (int i = 1; i <= n; i++)
            cin >> a[i], a[i]--;
        vector<int> dp(n+2, -inf);
        dp[n+1] = -1;
        for (int i = n; i >= 0; i--) {
            vector<int> f(n);
            int mf = 0;
            for (int j = i+1; j < n+2; j++) {
                if (2*mf <= j-i-1 && (j-i)%2 == 1 && (i == 0 || j == n+1 || a[i] == a[j]))
                    dp[i] = max(dp[i], dp[j]+1);
                mf = max(mf, ++f[a[j]]);
            }
        }
        debug(dp);
        cout << dp[0] << "\n";
    }
}