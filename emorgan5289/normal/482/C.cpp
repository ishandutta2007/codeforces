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

using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = a[0].size();
    vector<ll> dp(1<<m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            int x = 0;
            for (int k = 0; k < m; k++)
                if (a[i][k] == a[j][k])
                    x |= 1<<k;
            dp[x] |= (1ll<<i)|(1ll<<j);
        }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < 1<<m; i++)
            if (i&(1<<j)) dp[i^(1<<j)] |= dp[i];
    ld ans = 0;
    vector<ld> f(m+1);
    f[0] = 1;
    for (int i = 1; i <= m; i++)
        f[i] = i*f[i-1];
    debug(f);
    for (int i = 0; i < 1<<m; i++) {
        int x = __builtin_popcount(i);
        ans += __builtin_popcountll(dp[i])*f[x]*f[m-x]/f[m]/n;
    }
    cout << setprecision(25) << fixed << ans << "\n";
}