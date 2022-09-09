#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k, s = 0;
        cin >> n >> k;
        vector<vector<int>> G(n);
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
            s ^= x;
        }
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            u -= 1;
            v -= 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (s == 0) {
            cout << "YES\n";
            continue;
        }
        if (k == 2) {
            cout << "NO\n";
            continue;
        }
        map<int, int> mp;
        vector<int> sum(n), size(n);
        function<void(int, int)> dfs = [&](int u, int par) {
            sum[u] = a[u];
            for (int v : G[u]) if (v != par) {
                dfs(v, u);
                size[u] += size[v];
                sum[u] ^= sum[v];
            }
            size[u] += sum[u] == s;
            mp[sum[u]] += 1;
        };
        dfs(0, -1);
        int ok = 0;
        map<int, int> sk;
        function<void(int, int)> dfs2 = [&](int u, int par) {
            if (sum[u] == s and sk[0]) ok = 1;
            if (sum[u] == s and size[u] + sk[s] < mp[s]) ok = 1;
            sk[sum[u]] += 1;
            for (int v : G[u]) if (v != par)
                dfs2(v, u);
            sk[sum[u]] -= 1;
        };
        dfs2(0, -1);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}