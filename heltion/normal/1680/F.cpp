#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (auto& [u, v] : edges) {
            cin >> u >> v;
            u -= 1;
            v -= 1;
        }
        int ans = -1;
        vector<pair<int, int>> p(n, {-1, 0});
        function<pair<int, int>(int)> fp = [&](int u) -> pair<int, int> {
            if (p[u].first < 0) return {u, 0};
            auto fpu = fp(p[u].first);
            return {fpu.first, fpu.second ^ p[u].second};
        };
        function<void(int, int)> DFS = [&](int L, int R) {
            if (ans != -1) return;
            if (L == R) {
                ans = L;
                return;
            }
            int M = (L + R) / 2;
            {
                int ok = 1;
                stack<pair<pair<int, int>*, pair<int, int>>> s;
                for (int i = M + 1; i <= R and ok; i += 1) {
                    auto [u, v] = edges[i];
                    auto fpu = fp(u);
                    auto fpv = fp(v);
                    if (fpu.first == fpv.first) {
                        if (fpu.second == fpv.second) ok = 0;
                    }
                    else {
                        if (p[fpu.first].first < p[fpv.first].first)
                            swap(fpu, fpv);
                        s.emplace(&p[fpv.first], p[fpv.first]);
                        p[fpv.first].first += p[fpu.first].first;
                        s.emplace(&p[fpu.first], p[fpu.first]);
                        p[fpu.first] = {fpv.first, fpu.second ^ fpv.second ^ 1};
                    }
                }
                if (ok) DFS(L, M);
                for (; not s.empty(); s.pop()) {
                    auto [x, y] = s.top();
                    *x = y;
                }
            }
            {
                int ok = 1;
                stack<pair<pair<int, int>*, pair<int, int>>> s;
                for (int i = L; i <= M and ok; i += 1) {
                    auto [u, v] = edges[i];
                    auto fpu = fp(u);
                    auto fpv = fp(v);
                    if (fpu.first == fpv.first) {
                        if (fpu.second == fpv.second) ok = 0;
                    }
                    else {
                        if (p[fpu.first].first < p[fpv.first].first)
                            swap(fpu, fpv);
                        s.emplace(&p[fpv.first], p[fpv.first]);
                        p[fpv.first].first += p[fpu.first].first;
                        s.emplace(&p[fpu.first], p[fpu.first]);
                        p[fpu.first] = {fpv.first, fpu.second ^ fpv.second ^ 1};
                    }
                }
                if (ok) DFS(M + 1, R);
                for (; not s.empty(); s.pop()) {
                    auto [x, y] = s.top();
                    *x = y;
                }
            }
        };
        DFS(0, m - 1);
        if (ans == -1)
            cout << "NO\n";
        else {
            cout << "YES\n";
            vector<vector<int>> G(n);
            for (int i = 0; i < m; i += 1)
                if (i != ans) {
                    auto [u, v] = edges[i];
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            vector<int> res(n, -1);
            function<void(int)> DFS = [&](int u) {
                for (int v : G[u])
                    if (res[v] != -1)
                        assert(res[v] != res[u]);
                    else {
                        res[v] = res[u] ^ 1;
                        DFS(v);
                    }
            };
            auto [i, j] = edges[ans];
            if (res[i] == -1) {
                res[i] = 1;
                DFS(i);
            }
            if (res[j] == -1) {
                res[j] = 1;
                DFS(j);
            }
            for (int i = 0; i < m; i += 1) {
                auto [u, v] = edges[i];
                assert(res[u] or res[v]);
                if (i != ans) assert(not res[u] or not res[v]);
            }
            for (int x : res)
                cout << x;
            cout << "\n";
        }
    }
}