#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int n, p[maxn], f[maxn], g[maxn], h[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]), G[p[i]].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        if (G[v].empty()) { h[v] = 1; return; }
        f[v] = 1;
        for (int u : G[v]) {
            dfs(u);
            int a = f[v], b = g[v], c = h[v];
            f[v] = 1LL * a * (f[u] + h[u]) % P;
            g[v] = (1LL * b * (f[u] + h[u]) + 1LL * a * (g[u] + h[u])) % P;
            h[v] = (1LL * c * (f[u] + g[u] + 2LL * h[u]) + 1LL * b * (g[u] + h[u])) % P;
        }
    };
    dfs(1), printf("%d\n", (f[1] + h[1]) % P);
    return 0;
}