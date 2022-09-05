#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, parity[maxn];
vector<int> G[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    auto dfs = [&](auto self, int u, int fa) -> int {
        array<int, 2> cnt{};
        for (int v : G[u]) if (v ^ fa) {
            if (self(self, v, u)) return 1;
            cnt[parity[v]]++;
        }
        if (u > 1) parity[u] = cnt[0] >= cnt[1], cnt[parity[u]]++;
        if (cnt[1] < cnt[0] || cnt[1] > cnt[0] + 1) return 1;
        return 0;
    };
    auto print = [&](auto self, int u, int fa) -> void {
        vector<int> ver[2];
        for (int v : G[u]) {
            if (v == fa) ver[parity[u]].push_back(u);
            else ver[parity[v]].push_back(v);
        }
        for (int i = 0, k = G[u].size() % 2; i < G[u].size(); i++, k ^= 1) {
            int v = ver[k].back();
            ver[k].pop_back();
            if (u == v) cout << u << " " << fa << "\n";
            else self(self, v, u);
        }
    };
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            G[u].push_back(v), G[v].push_back(u);
        }
        if (dfs(dfs, 1, 0)) { cout << "NO\n"; continue; }
        cout << "YES\n", print(print, 1, 0);
    }
    return 0;
}