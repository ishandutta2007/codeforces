#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n, m, a, b, c; cin >> n >> m >> a >> b >> c;
        a--, b--, c--;
        vector<ll> p(m); for (auto& x : p) cin >> x;
        sort(all(p));
        vector<vector<ll>> adj(n);
        for (ll i = 0; i < m; i++) {
            if (i > 0) p[i] += p[i-1];
            ll u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v); adj[v].pb(u);
        }
        vector<ll> da(n, inf), db(n, inf), dc(n, inf);
        deque<ll> stack = {a};
        vector<ll> vis(n, 0);
        vis[a] = 1;
        da[a] = 0;
        while (!stack.empty()) {
            ll i = stack.back(); stack.pop_back();
            for (ll j : adj[i])
                if (!vis[j]) {
                    da[j] = da[i]+1;
                    stack.push_front(j);
                    vis[j] = 1;
                }
        }

        stack = {b};
        vis.assign(n, 0);
        vis[b] = 1;
        db[b] = 0;
        while (!stack.empty()) {
            ll i = stack.back(); stack.pop_back();
            for (ll j : adj[i])
                if (!vis[j]) {
                    db[j] = db[i]+1;
                    stack.push_front(j);
                    vis[j] = 1;
                }
        }

        stack = {c};
        vis.assign(n, 0);
        vis[c] = 1;
        dc[c] = 0;
        while (!stack.empty()) {
            ll i = stack.back(); stack.pop_back();
            for (ll j : adj[i])
                if (!vis[j]) {
                    dc[j] = dc[i]+1;
                    stack.push_front(j);
                    vis[j] = 1;
                }
        }

        debug(da, db, dc);
        debug(p);

        ll out = inf_ll;
        for (ll i = 0; i < n; i++) {
            if (da[i]+db[i]+dc[i] > m) continue;
            ll xa = (da[i]+db[i]+dc[i] == 0 ? 0 : p[da[i]+db[i]+dc[i]-1]);
            ll xb = (db[i] == 0 ? 0 : p[db[i]-1]);
            debug(i, xa, xb);
            out = min(out, xa+xb);
        }
        cout << out << "\n";
    }
}