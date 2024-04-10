#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<vector<pair<ll, ll>>> adj;
vector<ll> s;
ll k;

ll dfs1(int i, int p) {
    ll out = 0; s[i] = 1;
    for (auto& [w, j] : adj[i]) {
        if (j == p) continue;
        out += dfs1(j, i);
        s[i] += s[j];
        if (s[j]&1) out += w;
    }
    return out;
}

ll dfs2(int i, int p) {
    ll out = 0;
    for (auto& [w, j] : adj[i]) {
        if (j == p) continue;
        out += dfs2(j, i) + min(s[j], 2*k-s[j])*w;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> k;
        adj.assign(2*k, {});
        s.resize(2*k);
        for (int i = 0; i < 2*k-1; i++) {
            ll u, v, w; cin >> u >> v >> w; u--, v--;
            adj[u].pb({w, v}), adj[v].pb({w, u});
        }
        cout << dfs1(0, 0) << " " << dfs2(0, 0) << "\n";
    }
}