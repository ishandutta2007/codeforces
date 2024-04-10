#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, K, c[maxn], sz[maxn], fa[maxn];
bool mark[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    fill(sz + 1, sz + n + 1, 1);
    iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        u = find(u), v = find(v);
        if (u == v) continue;
        fa[u] = v, sz[v] += sz[u];
    }
    for (int i = 1; i <= K; i++) {
        mark[find(c[i])] = 1;
    }
    int ans = 0, id = 0, rem = n;
    for (int i = 1; i <= n; i++) if (i == find(i)) {
        if (mark[i] && sz[i] > sz[id]) id = i;
    }
    for (int i = 1; i <= n; i++) if (i == find(i)) {
        if (i == id || !mark[i]) continue;
        ans += sz[i] * (sz[i] - 1) / 2, rem -= sz[i];
    }
    ans += rem * (rem - 1) / 2;
    printf("%d\n", ans - m);
    return 0;
}