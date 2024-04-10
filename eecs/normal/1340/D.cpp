#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, d[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int _ = 1, u, v; _ < n; _++) {
        scanf("%d %d", &u, &v), d[u]++, d[v]++;
        G[u].push_back(v), G[v].push_back(u);
    }
    int D = *max_element(d + 1, d + n + 1);
    vector<pair<int, int>> ans;
    function<void(int, int, int)> dfs = [&](int v, int fa, int t) {
        ans.emplace_back(v, t);
        int o = t, foo = 0;
        for (int u : G[v]) if (u ^ fa) {
            if (t == D) ans.emplace_back(v, t = D - d[v]), foo = 1;
            dfs(u, v, ++t), ans.emplace_back(v, t);
        }
        if (v > 1 && !foo) ans.emplace_back(v, o - 1);
    };
    dfs(1, 0, 0);
    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}