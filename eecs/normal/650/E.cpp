#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, ans, fa[2][maxn], par[maxn];
vector<int> G[2][maxn];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
    scanf("%d", &n);
    for (int c : {0, 1}) {
        for (int _ = 0, u, v; _ < n - 1; _++) {
            scanf("%d %d", &u, &v);
            G[c][u].push_back(v), G[c][v].push_back(u);
        }
        function<void(int)> dfs = [&](int v) {
            for (int u : G[c][v]) if (u ^ fa[c][v]) {
                fa[c][u] = v, dfs(u);
            }
        };
        dfs(1);
    }
    par[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (fa[1][i] == fa[0][i] || fa[0][fa[1][i]] == i) par[i] = fa[1][i];
        else ans++, par[i] = i;
    }
    function<void(int)> dfs = [&](int v) {
        for (int u : G[0][v]) if (u ^ fa[0][v]) {
            dfs(u);
            if (u != fa[1][v] && v != fa[1][u]) {
                printf("%d %d %d %d\n", u, v, find(u), fa[1][find(u)]);
            }
        }
    };
    printf("%d\n", ans), dfs(1);
    return 0;
}