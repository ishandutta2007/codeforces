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
#define fin cin
#else
#include "../../debug.cpp"
#endif

vector<vector<pair<ll, int>>> adj;
vector<ll> dpg, dpn;
int n, k;

void dfs(int i, int p) {
    vector<ll> v;
    for (auto& [w, j] : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        dpn[i] += dpg[j];
        dpg[i] += dpg[j];
        v.pb(w+dpn[j]-dpg[j]);
    }
    sort(all(v), greater<ll>());
    debug(i, v);
    for (int j = 0; j < min(k, (int)v.size()); j++) {
        dpg[i] += max(0ll, v[j]);
        if (j != k-1) dpn[i] += max(0ll, v[j]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        fin >> n >> k;
        adj.assign(n, {});
        dpg.assign(n, 0); dpn.assign(n, 0);
        for (ll i = 0; i < n-1; i++) {
            ll a, b, c; fin >> a >> b >> c;
            adj[a-1].pb({c, b-1});
            adj[b-1].pb({c, a-1});
        }
        dfs(0, 0);
        debug(dpg, dpn);
        cout << dpg[0] << "\n";
    }
}