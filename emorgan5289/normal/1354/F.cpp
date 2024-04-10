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

const ll N = 100;
array<ll, 3> a[N];
ll dp[N][N], res[2*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        for (ll i = 0; i < n; i++) {
            cin >> a[i][1] >> a[i][0];
            a[i][2] = i+1;
        }
        sort(a, a+n);
        ll ans = 0;
        for (ll r = 0; r < n; r++) {
            fill(dp[0]+1, dp[0]+k, -inf_ll);
            dp[0][0] = 0;
            for (ll i = 1; i <= n; i++)
                for (ll j = 0; j < k; j++) {
                    if (i-1 == r) {
                        dp[i][j] = dp[i-1][j]; continue;
                    }
                    dp[i][j] = dp[i-1][j]+a[i-1][0]*(k-1);
                    if (j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[i-1][1]+a[i-1][0]*(j-1));
                }
            ll c = dp[n][k-1]+a[r][1]+a[r][0]*(k-1);
            if (c > ans) {
                ans = c;
                res[2*n-k-1] = a[r][2];
                int p = k-2, q = 2*n-k-2, j = k-1;
                for (int i = n; i > 0; i--) {
                    if (i-1 == r) continue;
                    // debug(p, q);
                    if (j == 0 || dp[i-1][j]+a[i-1][0]*(k-1) >= dp[i-1][j-1]+a[i-1][1]+a[i-1][0]*(j-1)) {
                        res[q--] = -a[i-1][2]; res[q--] = a[i-1][2];
                    } else {
                        res[p--] = a[i-1][2]; j--;
                    }
                }
                // debug(vector(res, res+2*n-k));
                // debug(ans);
            }
        }
        cout << 2*n-k << "\n";
        for (int i = 0; i < 2*n-k; i++)
            cout << res[i] << " \n"[i == 2*n-k-1];
    }
}