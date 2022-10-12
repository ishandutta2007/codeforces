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
    vector<array<ll, 3>> e(m);
    vector<vector<array<ll, 3>>> adj(n);
    map<array<ll, 3>, array<ll, 2>> p;
    for (int i = 0; i < m; i++) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        e[i] = {x, y, w};
        adj[x].pb({w, y, i});
        adj[y].pb({w, x, i});
    }

    debug(e);

    vector<array<ll, 3>> r;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        array<vector<array<ll, 2>>, 3> v;
        ll c = 0;
        for (auto& [w, j, ei] : adj[i]) {
            if (v[w].empty()) v[w].pb({j, ei});
            else {
                auto [k, kei] = v[w].back();
                v[w].pop_back();
                p[{k, i, kei}] = {j, ei};
                p[{j, i, ei}] = {k, kei};
            }
            c += w;
        }
        if (c%2 == 1) ans++;
        if (!v[1].empty() && !v[2].empty()) {
            p[{v[1][0][0], i, v[1][0][1]}] = v[2][0];
            p[{v[2][0][0], i, v[2][0][1]}] = v[1][0];
            v[1].pop_back();
            v[2].pop_back();
        }
        debug(i, v[1], v[2]);
        if (!v[1].empty())
            r.pb({i, v[1][0][0], v[1][0][1]});
        if (!v[2].empty())
            r.pb({i, v[2][0][0], v[2][0][1]});
    }

    debug(r);

    debug(p);

    set<array<ll, 3>> d;

    auto trav = [&](ll x, ll y, ll ei) {
        while (!d.count({x, y, ei}) && !d.count({y, x, ei})) {
            d.insert({x, y, ei});
            if (!p.count({x, y, ei}))
                break;
            auto [z, zei] = p[{x, y, ei}];
            x = y, y = z, ei = zei;
        }
    };

    for (auto [x, y, ei] : r)
        if (!d.count({y, x}))
            trav(x, y, ei);

    for (int i = 0; i < m; i++) {
        auto [x, y, w] = e[i];
        if (d.count({y, x}) || d.count({x, y})) continue;
        trav(x, y, i);
    }

    debug(d);

    assert(d.size() == m);

    cout << ans << "\n";
    for (int i = 0; i < m; i++)
        cout << (d.count({e[i][0], e[i][1], i}) ? 1 : 2);
    cout << "\n";
}