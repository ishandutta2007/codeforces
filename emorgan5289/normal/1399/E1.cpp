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

vector<vector<tuple<ll, ll, int>>> adj;
vector<tuple<ll, ll, ll>> a;
vector<ll> fr;
multiset<pair<ll, int>, greater<>> p[2];

void dfs(int i, int k) {
    if (adj[i].size()+(i == 0) == 1) fr[i] = 1; 
    for (auto& [w, c, j] : adj[i])
        if (j != k) {
            dfs(j, i);
            a.pb({w, c, fr[j]});
            fr[i] += fr[j];
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        adj.assign(n, {});
        fr.assign(n, 0);
        a.clear();
        p[0].clear(), p[1].clear();
        for (int i = 0; i < n-1; i++) {
            ll u, v, w, c; cin >> u >> v >> w; u--, v--; c = 1;
            adj[u].pb({w, c, v}), adj[v].pb({w, c, u});
        }
        ll g = 0, ans = 0;
        dfs(0, 0);
        for (int i = 0; i < a.size(); i++) {
            auto& [w, c, f] = a[i];
            g += w*f;
            p[c-1].insert({(w-(w/2))*f, i});
            if (c == 1)
                p[0].insert({((w/2)-(w/2/2))*f, i});
        }
        while (g > s) {
            int i;
            if (!p[0].empty() && g-p[0].begin()->first <= s)
                i = p[0].begin()->second;
            else {
                ll c1 = p[0].empty() ? -inf : (p[0].begin()->first + (++p[0].begin())->first);
                ll c2 = p[1].empty() ? -inf : p[1].begin()->first;
                if (c1 >= c2) i = p[0].begin()->second;
                else i = p[1].begin()->second; 
            }
            auto& [w, c, f] = a[i];
            p[c-1].erase(p[c-1].begin());
            g -= (w-(w/2))*f;
            w /= 2;
            ans += c;
            if (c == 1)
                p[0].insert({((w/2)-(w/2/2))*f, i});
            else
                p[1].insert({(w-(w/2))*f, i});
        }
        cout << ans << "\n";
    }
}