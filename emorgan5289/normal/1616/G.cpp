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

vector<bool> reachable(vector<vector<int>> adj, int i) {
    vector<bool> v(adj.size()+1);
    vector<int> stk({i}); v[i] = 1;
    while (!stk.empty()) {
        i = stk.back(); stk.pop_back();
        for (int j : adj[i])
            if (!v[j]) v[j] = 1, stk.pb(j);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<vector<ll>> adj(n+2);
        while (m--) {
            ll x, y; cin >> x >> y;
            debug(n, x, y);
            adj[x].pb(y);
        }
        for (int i = 1; i <= n; i++) {
            adj[0].pb(i);
            adj[i].pb(n+1);
        }
        n += 2;
        vector<ll> fwd_len(n);
        for (int i = n-2; i >= 0; i--)
            if (find(all(adj[i]), i+1) != adj[i].end())
                fwd_len[i] = fwd_len[i+1]+1;
        if (fwd_len[0] == n-1) {
            cout << (n-2)*(n-3)/2 << "\n";
            continue;
        }

        vector<vector<int>> fwd(2*n), rev(2*n);
        for (int i = 0; i < n; i++)
            for (int j : adj[i])
                if (j <= i+fwd_len[i+1]+2 && j != i+1) {
                    fwd[2*i].pb(2*(j-1)+1);
                    fwd[2*i+1].pb(2*(j-1));
                    rev[2*(j-1)+1].pb(2*i);
                    rev[2*(j-1)].pb(2*i+1);
                }

        int l = -1, r = -1;
        for (int i = 0; i < n-1; i++)
            if (fwd_len[i] == 0) {
                r = i;
                if (l == -1) l = i;
            }
        debug(l, r);

        auto l0 = reachable(rev, 2*l);
        auto r0 = reachable(fwd, 2*r);
        auto c0 = reachable(fwd, 2*l);

        ll ans = 0;

        ll x0 = 0, x1 = 0, x2 = 0, x3 = 0;
        ll y0 = 0, y1 = 0, y2 = 0, y3 = 0;
        for (int i = 0; i < n; i++) {
            if (l0[2*i]) x0++;
            if (l0[2*i+1]) x1++;
            if (l0[2*i] || l0[2*i+1]) x2++;
            if (l0[2*i] && l0[2*i+1]) x3++;
            if (r0[2*i]) y0++;
            if (r0[2*i+1]) y1++;
            if (r0[2*i] || r0[2*i+1]) y2++;
            if (r0[2*i] && r0[2*i+1]) y3++;
        }
        debug(x0, x1, x2);
        debug(y0, y1, y2);

        if (c0[2*r] && c0[2*r+1]) {
            ans = x2*y2;
        } else if (c0[2*r]) {
            ans = x0*y0+x1*y1-x3*y3;
        } else if (c0[2*r+1]) {
            ans = x0*y1+x1*y0-x3*y3;
        }

        if (l == r) ans--;

        cout << ans << "\n";
    }
}