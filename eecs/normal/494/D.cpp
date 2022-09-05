#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, q, tim, S1[maxn], S2[maxn], tid[maxn], sz[maxn];
int len[maxn], dep[maxn], fa[maxn][20], w[maxn];
int s1[maxn], s2[maxn], s3[maxn], s4[maxn], s5[maxn];
vector<pair<int, int>> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    function<void(int)> dfs1 = [&](int v) {
        tid[v] = ++tim, sz[v] = 1;
        dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (auto e : G[v]) if (e.first ^ fa[v][0]) {
            int u = e.first;
            fa[u][0] = v, w[u] = e.second;
            len[u] = (len[v] + e.second) % P;
            dfs1(u), sz[v] += sz[u];
            S1[v] = (S1[v] + 1LL * e.second * sz[u] + S1[u]) % P;
            S2[v] = (S2[v] + 1LL * e.second * e.second % P * sz[u] + 2LL * e.second * S1[u] + S2[u]) % P;
        }
    };
    function<void(int)> dfs2 = [&](int v) {
        s1[v] = (s1[v] + 1LL * len[v] * len[v] % P * sz[v] + 2LL * len[v] * (P - S1[v]) + S2[v]) % P;
        s2[v] = (s2[v] + S1[v] - 1LL * len[v] * sz[v] % P + P) % P;
        s3[v] = (s3[v] + sz[v]) % P;
        int o = (len[v] - 2 * w[v] % P + P) % P;
        s4[v] = (s4[v] + 1LL * o * o % P * sz[v] + 2LL * o * (P - S1[v]) + S2[v]) % P;
        s5[v] = (s5[v] + S1[v] - 1LL * o * sz[v] % P + P) % P;
        for (auto e : G[v]) if (e.first ^ fa[v][0]) {
            int u = e.first;
            s1[u] = s1[v], s2[u] = s2[v], s3[u] = s3[v];
            s4[u] = s4[v], s5[u] = s5[v], dfs2(u);
        }
    };
    dfs1(1), dfs2(1);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 17; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 17; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    auto calc = [&](int x, int d) {
        return (1LL * d * d % P * sz[x] + 2LL * d * S1[x] + S2[x]) % P;
    };
    auto query = [&](int u, int v) {
        if (tid[u] >= tid[v] && tid[u] < tid[v] + sz[v]) {
            int ans = 0, cur = 0;
            ans = (1LL * ans + s1[u] - s1[fa[v][0]] + P) % P;
            ans = (ans + 2LL * len[u] * (s2[u] - s2[fa[v][0]] + P)) % P;
            ans = (ans + 1LL * len[u] * len[u] % P * (s3[u] - s3[fa[v][0]] + P)) % P;
            ans = (1LL * ans - s4[u] + s4[v] + P) % P;
            ans = (ans - 2LL * len[u] * (s5[u] - s5[v] + P) % P + P) % P;
            ans = (ans - 1LL * len[u] * len[u] % P * (s3[u] - s3[v] + P) % P + P) % P;
            return ans;
        } else {
            int d = (1LL * len[u] + len[v] - 2 * len[lca(u, v)] % P + P) % P;
            return (int)calc(v, d);
        }
    };
    scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        int foo = query(u, v), bar = query(u, 1);
        printf("%lld\n", (2LL * foo - bar + P) % P);
    }
    return 0;
}