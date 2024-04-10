#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, m, u[maxn], v[maxn], f[maxn];
int dfn[maxn], fa[maxn], id[maxn], ban[maxn], coef[maxn];
vector<array<int, 2>> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        G[u[i]].push_back({v[i], i}), G[v[i]].push_back({u[i], i});
    }
    auto solve = [&](vector<int> cyc) {
        rotate(cyc.begin(), min_element(cyc.begin(), cyc.end()), cyc.end());
        int p = max_element(cyc.begin(), cyc.end()) - cyc.begin();
        bool flag = 1;
        for (int i = 0; i < p; i++) {
            if (cyc[i] > cyc[i + 1]) { flag = 0; break; }
        }
        for (int i = p; i + 1 < cyc.size(); i++) {
            if (cyc[i] < cyc[i + 1]) { flag = 0; break; }
        }
        if (flag) ban[cyc[p]] = cyc[0];
    };
    function<void(int)> dfs = [&](int u) {
        static int tim = 0;
        dfn[u] = ++tim;
        for (auto &e : G[u]) {
            if (!dfn[e[0]]) {
                fa[e[0]] = u, id[e[0]] = e[1], dfs(e[0]);
            } else if (e[1] ^ id[u] && dfn[e[0]] < dfn[u]) {
                vector<int> cyc;
                for (int i = u; i ^ e[0]; i = fa[i]) {
                    cyc.push_back(id[i]);
                }
                cyc.push_back(e[1]), solve(cyc);
            }
        }
    };
    dfs(1), fill(f + 1, f + n + 1, 1);
    for (int i = m; i; i--) {
        f[u[i]] = f[v[i]] = f[u[i]] + f[v[i]] - coef[i];
        coef[ban[i]] = f[u[i]];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", f[i] - 1);
    }
    return 0;
}