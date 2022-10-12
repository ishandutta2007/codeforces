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

const int N = 2e5+5;
vector<array<int, 2>> adj[N];
bool v[N], s[N];
int d[N];

int dfs1(int i, int k) {
    if (s[i]) return i;
    s[i] = 1;
    for (auto& [e, j] : adj[i])
        if (j != k && !v[e]) {
            int x = dfs1(j, i);
            if (x != -1) {
                d[i]--, d[j]++;
                cout << i+1 << " " << j+1 << "\n";
                v[e] = 1;
                if (x != i) {
                    s[i] = 0;
                    return x;
                }
            }
        }
    s[i] = 0;
    return -1;
}

void dfs2(int i) {
    for (auto& [e, j] : adj[i])
        if (!v[e]) {
            if (d[i] >= 0) {
                d[i]--, d[j]++;
                cout << i+1 << " " << j+1 << "\n";
            } else {
                d[i]++, d[j]--;
                cout << j+1 << " " << i+1 << "\n";
            }
            v[e] = 1;
            dfs2(j);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++)
            adj[i].clear();
        fill(v, v+m, 0);
        fill(d, d+n, 0);
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb({i, y}), adj[y].pb({i, x});
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (adj[i].size()%2 == 0) ans++;
        cout << ans << "\n";
        for (int i = 0; i < n; i++)
            dfs1(i, i), dfs2(i);
        int x = 0;
        for (int i = 0; i < n; i++)
            if (d[i] == 0) x++;
        assert(x == ans);
    }
}