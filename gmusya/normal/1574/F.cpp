#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        a[i].resize(size);
        for (int j = 0; j < size; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> g(k + 1), _g(k + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < a[i].size(); ++j) {
            g[a[i][j]].push_back(a[i][j + 1]);
            _g[a[i][j + 1]].push_back(a[i][j]);
        }
    }
    vector<bool> banned(k + 1);
    for (int i = 1; i <= k; ++i) {
        sort(g[i].begin(), g[i].end());
        sort(_g[i].begin(), _g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        _g[i].resize(unique(_g[i].begin(), _g[i].end()) - _g[i].begin());
        if (g[i].size() >= 2 || _g[i].size() >= 2) {
            banned[i] = true;
        }
    }
    vector<bool> used(k + 1);
    function<void(int, vector<int>&, vector<vector<int>>&)> DFS = [&](int v, vector<int>& order, vector<vector<int>>& g) {
        used[v] = true;
        for (int u : g[v]) {
            if (!used[u]) {
                DFS(u, order, g);
            }
            if (banned[u]) {
                banned[v] = true;
            }
        }
        order.push_back(v);
    };
    vector<int> order;
    for (int v = 1; v <= k; ++v) {
        if (!used[v]) {
            DFS(v, order, g);
        }
    }
    vector<int> comp(k + 1);
    vector<vector<int>> comps;
    int cnt = 0;
    used.assign(k + 1, false);
    for (int i = 0; i < k; ++i) {
        int v = order[k - i - 1];
        if (!used[v]) {
            comps.emplace_back();
            DFS(v, comps.back(), _g);
            for (int u : comps.back()) {
                comp[u] = cnt;
            }
            ++cnt;
            if (comps.back().size() >= 2) {
                for (int u : comps.back()) {
                    banned[u] = true;
                }
            }
        }
    }
    used.assign(k + 1, false);
    function<void(int, vector<vector<int>>&)> FindBanned = [&](int v, vector<vector<int>>& g) {
        used[v] = true;
        for (int u : g[v]) {
            if (banned[u] || banned[v]) {
                banned[u] = banned[v] = true;
            }
            if (!used[u]) {
                FindBanned(u, g);
            }
            if (banned[u] || banned[v]) {
                banned[u] = banned[v] = true;
            }
        }
    };
    for (int v = 1; v <= k; ++v) {
        if (!used[v]) {
            FindBanned(v, g);
        }
    }
    vector<int> dp(k + 1);
    for (int v : order) {
        if (g[v].size() == 1) {
            dp[v] = dp[g[v][0]] + 1;
        } else {
            dp[v] = 1;
        }
        if (banned[v]) {
            dp[v] = -1;
        }
    }
    map<int, int> words;
    for (int v : order) {
        if (_g[v].empty() && !banned[v]) {
            ++words[dp[v]];
        }
    }
    vector<ll> ans(m + 1);
    ans[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (auto& now : words) {
            if (i - now.first >= 0) {
                ans[i] = (ans[i] + ans[i - now.first] * now.second) % MOD;
            }
        }
    }
    cout << ans[m];
    return 0;
}