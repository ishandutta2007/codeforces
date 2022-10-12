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
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> x(n), y(m);
        set<int> sx, sy;
        for (int i = 0; i < n; i++)
            cin >> x[i], sx.insert(x[i]);
        for (int i = 0; i < m; i++)
            cin >> y[i], sy.insert(y[i]);
        vector<array<ll, 2>> p(k);
        vector<array<ll, 2>> a, b; 
        for (int i = 0; i < k; i++) {
            ll w, z; cin >> w >> z;
            if (sx.count(w) && !sy.count(z))
                a.pb({lower_bound(all(x), w)-x.begin(), lower_bound(all(y), z)-y.begin()});
            if (!sx.count(w) && sy.count(z))
                b.pb({lower_bound(all(y), z)-y.begin(), lower_bound(all(x), w)-x.begin()});
        }
        map<ll, vector<ll>> ga, gb;
        for (auto& [w, z] : a) ga[w].pb(z);
        for (auto& [w, z] : b) gb[w].pb(z);
        ll ans = 0;
        map<ll, ll> cur;
        for (auto& [_, v] : ga) {
            for (auto& z : v)
                ans += cur[z];
            for (auto& z : v)
                cur[z]++;
        }
        cur.clear();
        for (auto& [_, v] : gb) {
            for (auto& z : v)
                ans += cur[z];
            for (auto& z : v)
                cur[z]++;
        }
        cout << ans << "\n";
    }
}