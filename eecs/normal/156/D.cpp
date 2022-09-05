#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, P, fa[maxn], sz[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d", &n, &m, &P);
    iota(fa + 1, fa + n + 1, 1);
    fill(sz + 1, sz + n + 1, 1);
    int con = n;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u = find(u), v = find(v);
        if (u ^ v) con--, fa[u] = v, sz[v] += sz[u];
    }
    if (con == 1) printf("%d\n", 1 % P), exit(0);
    int ans = qp(n, con - 2);
    for (int i = 1; i <= n; i++) {
        if (i == find(i)) ans = 1LL * ans * sz[i] % P;
    }
    printf("%d\n", ans);
    return 0;
}