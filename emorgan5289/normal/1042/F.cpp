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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e6+5;
bool v[N];
vector<int> adj[N], grp[N];

void dfs1(int i, int k, int d) {
    if (adj[i].size() == 1) grp[d].pb(i);
    for (auto& j : adj[i])
        if (j != k) dfs1(j, i, d+1);
}

void dfs2(int i, int k, int d) {
    v[i] = 1;
    if (d > 0)
        for (auto& j : adj[i])
            if (j != k) dfs2(j, i, d-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++)
        if (adj[i].size() != 1) {
            dfs1(i, i, 0); break;
        }
    int ans = 0;
    for (int i = n; i >= 0; i--)
        for (auto& x : grp[i])
            if (!v[x]) dfs2(x, x, k), ans++;
    cout << ans << "\n";
}