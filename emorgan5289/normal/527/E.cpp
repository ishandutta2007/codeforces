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

const int N = 3e5+5;
vector<array<int, 2>> adj[N], ans;
int c[N], d[N], v[N], ve[N];

void dfs(int i) {
    v[i] = 1;
    for (auto [t, j] : adj[i]) {
        if (ve[t]) continue;
        ve[t] = 1;
        if (v[j]) c[j] ^= 1, ans.pb({i, j});
        else {
            dfs(j);
            if (c[j]) c[j] ^= 1, ans.pb({i, j});
            else c[i] ^= 1, ans.pb({j, i});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int t = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        d[x] ^= 1, d[y] ^= 1;
        adj[x].pb({t, y}), adj[y].pb({t++, x});
    }
    int x = -1;
    for (int i = 0; i < n; i++)
        if (d[i]) {
            if (x == -1) x = i;
            else {
                adj[x].pb({t, i}), adj[i].pb({t++, x});
                x = -1, m++;
            }
        }
    if (m&1) adj[0].pb({t++, 0});
    dfs(0);
    cout << ans.size() << "\n";
    for (auto& [i, j] : ans)
        cout << i+1 << " " << j+1 << "\n";
}