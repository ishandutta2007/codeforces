#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, d[maxn], cur[maxn], vis[maxn];
vector<pair<int, int>> G[maxn];
vector<int> ans;

int main() {
    scanf("%d %d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        if (~d[i]) sum += d[i];
    }
    if (sum & 1) {
        bool flag = 0;
        for (int i = 1; i <= n; i++) if (!~d[i]) {
            if (!flag) d[i] = 1, flag = 1;
            else d[i] = 0;
        }
        if (!flag) puts("-1"), exit(0);
    }
    for (int i = 1; i <= n; i++) {
        if (!~d[i]) d[i] = 0;
    }
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v, i), G[v].emplace_back(u, i);
    }
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        for (auto e : G[v]) if (!vis[e.first]) {
            dfs(e.first);
            if (d[e.first] ^ cur[e.first]) {
                ans.push_back(e.second);
                cur[v] ^= 1, cur[e.first] ^= 1;
            }
        }
    };
    dfs(1);
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
    return 0;
}