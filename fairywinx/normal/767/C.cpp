#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<int> &t, int sum, pair<int, int> &ans, vector<int> &sz, vector<int> &find, int root) {
    sz[v] = t[v];
    int tmp = -1;
    for (int i : g[v]) {
        dfs(i, g, t, sum, ans, sz, find, root);
        sz[v] += sz[i];
        if (tmp != -1 && find[i] != -1) {
            ans = {tmp, find[i]};
            return;
        }
        if (find[i] != -1) {
            tmp = find[i];
        }
    }
    for (int i : g[v]) {
        if (sz[v] == 2 * sum / 3 && find[i] != -1 && v != root) {
            ans = {v, find[i]};
        }
    }
    if (tmp != -1) {
        find[v] = tmp;
    }
    if (sz[v] == sum / 3) {
        find[v] = v;
    }
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> t(n);
    int sum = 0;
    int v = -1;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        t[i - 1] = b;
        sum += b;
        if (a == 0) {
            v = i - 1;
        } else {
            g[a - 1].emplace_back(i - 1);
        }
    }
    if (sum % 3 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> find(n, -1);
    vector<int> sz(n);
    pair<int, int> ans = {-1, -1};
    dfs(v, g, t, sum, ans, sz, find, v);
    if (ans.first == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
}