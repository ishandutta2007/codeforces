#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, W, fa[maxn], w[maxn], b[maxn], f[maxn], g[maxn];
vector<int> V[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &W);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    iota(fa + 1, fa + n + 1, 1);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        fa[find(u)] = find(v);
    }
    for (int i = 1; i <= n; i++) {
        V[find(i)].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!V[i].empty()) {
        memcpy(g, f, sizeof(g));
        int sw = 0, sb = 0;
        for (int j : V[i]) {
            sw += w[j], sb += b[j];
            for (int k = 0; k + w[j] <= W; k++) {
                g[k + w[j]] = max(g[k + w[j]], f[k] + b[j]);
            }
        }
        for (int k = 0; k + sw <= W; k++) {
            g[k + sw] = max(g[k + sw], f[k] + sb);
        }
        swap(f, g);
    }
    printf("%d\n", f[W]);
    return 0;
}