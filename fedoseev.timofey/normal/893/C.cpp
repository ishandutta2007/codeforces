#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector <vector <int>> g;
vector <bool> used;

vector <int> cmp;

void dfs(int u) {
    used[u] = 1;
    cmp.push_back(u);
    for (auto v : g[u]) {
        if (used[v]) continue;
        dfs(v);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    vector <int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
            long long mn = 1e10;
            for (auto e : cmp) {
                mn = min(mn, 1LL * c[e]);
            }
            ans += mn;
            cmp.clear();
        }
    }
    cout << ans << endl;
}