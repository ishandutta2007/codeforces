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
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        map<ll, vector<ll>> f;
        for (int i = 0; i < n; i++)
            f[a[i]].pb(i);
        vector<array<ll, 2>> v;
        for (auto& [x, y] : f)
            v.pb({ll(y.size()), x});
        sort(all(v), greater<>());
        debug(v);
        vector<array<ll, 2>> e;
        for (int i = 0; i < v.size(); i++) {
            ll c = i+1 == v.size() ? v[i][0] : v[i][0]-v[i+1][0];
            debug(i, c);
            for (int j = 0; j < c; j++)
                e.pb({v[i][1], v[0][1]});
            for (int j = 0; j < v[i][0]-c; j++)
                e.pb({v[i][1], v[i+1][1]});
        }
        vector<ll> p(n);
        for (auto& [x, y] : e) {
            p[f[x].back()] = y;
            f[x].pop_back();
        }
        for (int i = 0; i < n; i++)
            cout << p[i] << " \n"[i == n-1];
    }
}