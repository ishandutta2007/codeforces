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
        vector<ll> a(n);
        vector<array<ll, 2>> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i][0] >> b[i][1];
        map<ll, ll, greater<>> f;
        set<array<ll, 2>> bad;
        for (ll x : a)
            f[x]++;
        for (auto& x : b)
            bad.insert(x);
        for (auto& [x, _] : f)
            bad.insert({x, x});
        map<ll, vector<ll>> c;
        for (auto& [x, fx] : f)
            c[fx].pb(x);
        ll ans = 0;
        for (auto& [fx, vx] : c)
            for (auto& [fy, vy] : c) {
                if (fy < fx) continue;
                for (ll x : vx) {
                    if ((fx+fy)*(x+vy[0]) < ans) break;
                    for (ll y : vy) {
                        if (!bad.count({min(x, y), max(x, y)})) {
                            cmax(ans, (fx+fy)*(x+y));
                            break;
                        }
                    }
                }
            }
        cout << ans << "\n";
    }
}