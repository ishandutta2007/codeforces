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

const int N = 1e5+5;
vector<int> adj[N];
map<int, int> m[N];
vector<pair<int, int>> ans;

void dfs1(int i, int k, int t) {
    int x = t-1, d = -1;
    for (auto& j : adj[i]) {
        if (j == k) continue;
        if (x < 1) d = 1, x = t+1;
        m[i][x-1] = j, m[j][x-1] = i;
        dfs1(j, i, x), x += d;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs1(0, 0, 0);
    int v = 0, t = 0;
    while (v != 0 || m[v].count(t)) {
        ans.pb({v, t});
        if (m[v].count(t)) v = m[v][t], t++;
        else t = m[v].begin()->first;
    }
    ans.pb({v, t});
    cout << ans.size() << "\n";
    for (auto& [v, t] : ans)
        cout << v+1 << " " << t << "\n";
}