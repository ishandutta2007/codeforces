#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const ll inf = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    vt<pii> pos(n);
    for (pii &p : pos) cin >> p.fi >> p.se;
    vt<int> c(n), k(n);
    for (int &x : c) cin >> x;
    for (int &x : k) cin >> x;

    auto calc_dist = [&](int u, int v) {
        return abs(pos[u].fi - pos[v].fi)
            + abs(pos[u].se - pos[v].se);
    };

    ll ans = 0;
    vt<int> pwr;
    vt<pii> wires;
    vt<bool> vis(n);
    vt<pli> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = {c[i], -1};
    }
    for (int _ = 0; _ < n; _++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (!~u || dist[i].fi < dist[u].fi))
                u = i;
        }

        vis[u] = true;
        ans += dist[u].fi;
        if (~dist[u].se) wires.emplace_back(dist[u].se, u);
        else pwr.push_back(u);

        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                ll newd = ll(k[u] + k[v]) * calc_dist(u, v);
                if (newd < dist[v].fi) {
                    dist[v] = {newd, u};
                }
            }
        }
    }

    cout << ans << '\n';
    cout << sz(pwr) << '\n';
    for (int x : pwr) cout << x + 1 << ' ';
    cout << '\n';
    cout << sz(wires) << '\n';
    for (pii p : wires) cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}