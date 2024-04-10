#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, c[maxn], fa[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        int cur = 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            while (cur == c[v] || cur == c[fa[v]]) cur++;
            c[u] = cur++;
        }
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs(u);
        }
    };
    dfs(c[1] = 1), printf("%d\n", *max_element(c + 1, c + n + 1));
    for (int i = 1; i <= n; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}