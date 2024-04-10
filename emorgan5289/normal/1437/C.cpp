#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int dp[705][705];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (auto& x : a) cin >> x;
        sort(all(a));
        for (int j = 0; j < 700; j++)
            dp[0][j] = inf;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 700; j++) {
                dp[i][j] = inf;
                for (int k = 0; k < j; k++)
                    dp[i][j] = min(dp[i][j], abs(a[i-1]-j)+dp[i-1][k]);
            }
        for (int i = 1; i <= n; i++)
            debug(min_element(dp[i], dp[i]+700)-dp[i]-205);
        cout << *min_element(dp[n], dp[n]+700) << "\n";
    }
}