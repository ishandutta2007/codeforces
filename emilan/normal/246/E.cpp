#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    for (auto &[name, p] : a) {
        cin >> name >> p;
        p--;
    }

    int q;
    cin >> q;
    vector<vector<pair<int, int>>> tasks(n);
    for (int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;
        tasks[--u].emplace_back(k, i);
    }

    vector<int> root;
    vector<vector<int>> chi(n);
    for (int u = 0; u < n; u++) {
        auto [_, p] = a[u];
        if (p == -1) root.push_back(u);
        else chi[p].push_back(u);
    }

    vector<int> sub(n), depth(n), tin(n), tout(n), ttick(n);
    int tick = 0;
    vector<vector<int>> depth_nodes(n);
    function<void(int)> dfs_scout = [&](int u) {
        tin[u] = tick;
        ttick[tick++] = u;
        depth_nodes[ depth[u] ].push_back(u);
        for (int &v : chi[u]) {
            depth[v] = depth[u] + 1;
            dfs_scout(v);
            sub[u] += sub[v];
            if (int &w = chi[u][0]; sub[v] > sub[w]) swap(v, w);
        }
        tout[u] = tick;
    };
    for (int s : root) dfs_scout(s);

    vector<int> id(n);
    int seq = 0;
    for (auto &s : depth_nodes) {
        auto f = [&](int u, int v) {
            return a[u].first < a[v].first;
        };
        sort(s.begin(), s.end(), f);

        for (int j = 0; j < int(s.size()); j++) {
            if (j == 0 || a[ s[j - 1] ].first != a[ s[j] ].first) seq++;
            id[ s[j] ] = seq;
        }
    }

    {
        int _seq = 0;
        map<string, int> _mp;
        vector<int> _id(n);
        int _xum = 0;
        for (int u = 0; u < n; u++) {
            auto [name, _] = a[u];
            if (!_mp.count(name)) _mp[name] = _seq++;
            _id[u] = _mp[name];
            _xum ^= _id[u];
        }
        cerr << _xum << endl;
    }

    vector<bool> id_cnt(n);
    vector<int> depth_uniq(n);
    auto add = [&](int u) {
        if (!id_cnt[ id[u] ]) {
            id_cnt[ id[u] ] = true;
            depth_uniq[ depth[u] ]++;
        }
    };
    auto rm = [&](int u) {
        if (id_cnt[ id[u] ]) {
            id_cnt[ id[u] ] = false;
            depth_uniq[ depth[u] ]--;
        }
    };

    vector<int> ans(q);
    function<void(int, bool)> dfs = [&](int u, bool keep) {
        int m = chi[u].size();
        for (int i = m - 1; i > 0; i--) dfs(chi[u][i], false);
        if (m > 0) dfs(chi[u][0], true);
        add(u);
        for (int i = m - 1; i > 0; i--) {
            int v = chi[u][i];
            for (int t = tin[v]; t < tout[v]; t++) {
                add(ttick[t]);
            }
        }

        for (auto [k, i] : tasks[u]) if (depth[u] + k < n) {
            ans[i] = depth_uniq[depth[u] + k];
        }

        if (!keep) {
            for (int t = tin[u]; t < tout[u]; t++) {
                rm(ttick[t]);
            }
        }
    };
    for (int s : root) dfs(s, false);

    for (int x : ans) cout << x << "\n";
}