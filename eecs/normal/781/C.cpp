#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, K, vis[maxn];
vector<int> V, G[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1, V.push_back(v);
        for (int u : G[v]) if (!vis[u]) {
            dfs(u), V.push_back(v);
        }
    };
    dfs(1);
    int len = (2 * n + K - 1) / K;
    for (int i = 0; i < K; i++) {
        int l = i * len, r = min((int)V.size(), l + len) - 1;
        if (l > r) {
            puts("1 1");
        } else {
            printf("%d", r - l + 1);
            for (int j = l; j <= r; j++) printf(" %d", V[j]);
            putchar('\n');
        }
    }
    return 0;
}