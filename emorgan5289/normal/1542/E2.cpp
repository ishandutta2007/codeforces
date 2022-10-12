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
    ll n, m; cin >> n >> m;
    vector<ll> dp1 = {1}, dp2;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll r = 0;
        dp2 = dp1;
        for (int j = 0; j < i-1; j++)
            dp2.pb(0);
        for (int j = 1; j < dp2.size(); j++)
            dp2[j] = (dp2[j]+dp2[j-1])%m;
        ll x = (dp2[0]*(i-1))%m, y = 0;
        for (int j = 0; j+2 < dp1.size(); j++) {
            if (j > 0) x = (x+dp1[j]*(i-1)-dp2[j-1]+m)%m;
            if (j > i-1) x = (x+dp2[j-i])%m;
            y = (y+x)%m;
            r += (dp1[j+2]*y)%m;
        }
        for (int j = n; j > i; j--)
            r = (r*j)%m;
        ans = (ans+r)%m;
        for (int j = dp2.size()-1; j >= i; j--)
            dp2[j] = (dp2[j]-dp2[j-i]+m)%m;
        swap(dp1, dp2);
    }
    cout << ans << "\n";
}