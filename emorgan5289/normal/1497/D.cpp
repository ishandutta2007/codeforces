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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> tag(n), s(n);
        for (int i = 0; i < n; i++)
            cin >> tag[i];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        vector<ll> dp(n+2);
        ll ans = 0;
        for (int y = n; y >= 1; y--)
            for (int x = 1; x < y; x++) {

                ll yx = dp[y]+abs(s[x-1]-s[y-1]);
                ll xy = dp[x]+abs(s[y-1]-s[x-1]);
                if (tag[x-1] == tag[y-1]) xy = yx = -inf_ll;

                dp[x] = max(yx, dp[x]);
                dp[y] = max(xy, dp[y]);

                cmax(ans, max(xy, yx));
            }
        for (auto& row : dp) debug(row);
        cout << ans << "\n";
    }
}