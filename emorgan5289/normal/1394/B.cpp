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

const int N = 2e5+5, K = 15;
vector<pair<ll, int>> adj[N];
vector<pair<int, int>> g[N], tmp;
vector<int> stk;
bool v[K][K][K][K];
ll n, m, k, ans = 0;

void dfs(int s) {
    if (s == k+1) {
        bool u = 0;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                u = u || v[i+1][stk[i]][j+1][stk[j]];
        if (!u) ans++;
    } else
        for (int i = 1; i <= s; i++)
            stk.pb(i), dfs(s+1), stk.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        adj[x].pb({w, y});
    }
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]));
        int s = adj[i].size();
        for (int j = 0; j < s; j++)
            g[adj[i][j].second].pb({s, j+1});
    }
    for (int i = 0; i < n; i++) {
        sort(all(g[i])), tmp.clear();
        for (int j = 0; j < g[i].size(); j++)
            if (j < 2 || g[i][j] != g[i][j-2])
                tmp.pb(g[i][j]);
        for (int x = 0; x < tmp.size(); x++)
            for (int y = 0; y < tmp.size(); y++) {
                if (x == y) continue;
                v[tmp[x].first][tmp[x].second][tmp[y].first][tmp[y].second] = 1;
            }
    }
    dfs(1);
    cout << ans << "\n";
}