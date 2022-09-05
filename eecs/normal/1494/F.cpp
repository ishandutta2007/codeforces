#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int n, m, cur[maxn], vis[maxn];
vector<pair<int, int>> G[maxn];
vector<int> ans;

void dfs(int v) {
    while (cur[v] < G[v].size()) {
        auto e = G[v][cur[v]++];
        if (!vis[e.second]) vis[e.second] = 1, dfs(e.first);
    }
    ans.push_back(v);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v, i), G[v].emplace_back(u, i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() & 1) cnt++;
    }
    auto get = [&](int c) {
        vector<int> V;
        for (auto e : G[c]) if (vis[e.second]) {
            V.push_back(e.first);
        }
        memset(cur, 0, sizeof(cur));
        ans.clear(), dfs(c);
        if (ans.size() - 1 != m - V.size()) return;
        ans.push_back(-1);
        for (int v : V) {
            ans.push_back(v), ans.push_back(c);
        }
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        putchar('\n'), exit(0);
    };
    for (int c = 1; c <= n; c++) {
        int nc = cnt - (G[c].size() & 1);
        memset(vis, 0, sizeof(vis));
        for (auto e : G[c]) {
            if (G[e.first].size() & 1) nc--, vis[e.second] = 1;
        }
        if (nc > 1) continue;
        get(c);
        if (nc == 1) continue;
        for (auto e : G[c]) if (G[e.first].size() & 1) {
            memset(vis, 0, sizeof(vis));
            for (auto _e : G[c]) if (e != _e) {
                if (G[_e.first].size() & 1) vis[_e.second] = 1;
            }
            get(c);
        }
    }
    puts("0");
    return 0;
}