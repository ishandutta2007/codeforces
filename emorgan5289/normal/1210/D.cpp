#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
vector<int> adj[N];
ll in[N], out[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    ll ans = 0;
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v) swap(u, v);
        adj[u].pb(v);
        out[v]++, in[u]++;
    }
    for (int i = 0; i < n; i++)
        ans += in[i]*out[i];
    cout << ans << "\n";
    int q; cin >> q;
    while (q--) {
        int i; cin >> i; i--;
        for (auto& j : adj[i]) {
            adj[j].pb(i);
            ans -= in[j]*out[j];
            in[j]++, out[j]--;
            ans += in[j]*out[j];
        }
        ans -= in[i]*out[i];
        out[i] += adj[i].size(), in[i] = 0;
        adj[i].clear();
        cout << ans << "\n";
    }
}