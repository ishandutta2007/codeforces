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

const int N = 1e6+5;
int n, k, l;
ll a[N], dp[N], ul[N], ur[N];

ll solve() {
    ll x = 0, y = N, ans = inf_ll;
    while (x < y) {
        int m = (x+y)/2;
        dp[0] = ul[0] = ur[0] = 0;
        for (int i = 1; i <= n; i++) {
            int j = max(0, i-l);
            ll p = dp[i-1]+a[i-1], q = dp[j]+m;
            if (p < q) {
                dp[i] = p;
                ul[i] = ul[i-1];
                ur[i] = ur[i-1];
            } else if (p > q) {
                dp[i] = q;
                ul[i] = ul[j]+1;
                ur[i] = ur[j]+1;
            } else {
                dp[i] = p;
                ul[i] = min(ul[i-1], ul[j]+1);
                ur[i] = max(ur[i-1], ur[j]+1);
            }
        }
        debug(m, k, ul[n], ur[n], dp[n]);
        if (k >= ul[n] && (k <= ur[n] || m == 0))
            return dp[n]-m*k;
        if (ul[n] < k)
            y = m;
        else
            x = m+1;
    }
    assert(false);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c >= 'a';
    }
    ll ans = solve();
    for (int i = 0; i < n; i++)
        a[i] ^= 1;
    ans = min(ans, solve());
    cout << ans << "\n";
}