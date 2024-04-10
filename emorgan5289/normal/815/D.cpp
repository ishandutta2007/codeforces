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

vector<array<ll, 2>> hull(vector<array<ll, 2>> a) {
    vector<array<ll, 2>> b, c;
    sort(all(a));
    for (auto& [x, y] : a) {
        if (!b.empty() && b.back()[1] <= y)
            continue;
        b.pb({x, y});
    }
    debug(b);
    for (int i = 0; i+1 < b.size(); i++)
        c.pb({b[i+1][0], b[i][1]});
    if (c.empty()) c.pb({0, 0});
    return c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, p, q, r; cin >> n >> p >> q >> r;
    vector<array<ll, 2>> a(n+2), b(n+2), c(n+2);
    for (int i = 0; i < n; i++) {
        ll x, y, z; cin >> x >> y >> z;
        a[i] = {p-x, q-y};
        b[i] = {p-x, r-z};
        c[i] = {q-y, r-z};
    }
    a[n] = {0, q}, a[n+1] = {p, 0};
    b[n] = {0, r}, b[n+1] = {p, 0};
    c[n] = {0, r}, c[n+1] = {q, 0};
    debug(a);
    debug(b);
    debug(c);
    a = hull(a), b = hull(b), c = hull(c);
    debug(a);
    debug(b);
    debug(c);
    deque<array<ll, 2>> v;
    ll ans = 0, sz = 0;
    for (auto& [x, y] : c) {
        if (v.empty()) sz += x*y;
        else sz += y*(x-v.back()[0]);
        v.pb({x, y});
    }
    debug(v, sz);
    vector<vector<array<ll, 2>>> ev(p+2);
    ev[1].pb({0, a[0][1]});
    ev[1].pb({1, b[0][1]});
    a.pb({p+1, 0});
    b.pb({p+1, 0});
    for (int i = 0; i+1 < a.size(); i++)
        ev[a[i][0]+1].pb({0, a[i+1][1]});
    for (int i = 0; i+1 < b.size(); i++)
        ev[b[i][0]+1].pb({1, b[i+1][1]});
    for (int i = 1; i <= p; i++) {
        for (auto& [t, x] : ev[i]) {
            if (t == 0) {
                while (v.size() > 1 && v[v.size()-2][0] >= x) {
                    sz -= (v[v.size()-1][0]-v[v.size()-2][0])*v[v.size()-1][1];
                    v.pop_back();
                }
                if (v.size() > 0 && v.back()[0] > x) {
                    sz -= (v.back()[0]-x)*v.back()[1];
                    v.back()[0] = x;
                }
            } else {
                while (v.size() > 1 && v[1][1] >= x) {
                    sz -= (v[0][1]-v[1][1])*v[0][0];
                    v.pop_front();
                }
                if (v.size() > 0 && v.front()[1] > x) {
                    sz -= (v.front()[1]-x)*v.front()[0];
                    v.front()[1] = x;
                }
            }
        }
        // debug(sz);
        // debug(v);
        ans += sz;
    }
    cout << ans << "\n";
}