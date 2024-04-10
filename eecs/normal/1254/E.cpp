#include <bits/stdc++.h>
using namespace std;

const int maxn = 1500010, P = 1000000007;
int n, ans = 1, fact[maxn], fa[maxn], dep[maxn], ord[maxn], coef[maxn], bel[maxn];
vector<int> G[maxn];

int find(int x) {
    return x == bel[x] ? x : bel[x] = find(bel[x]);
}

void unite(int x, int y) {
    bel[find(x)] = find(y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    iota(bel + 1, bel + 3 * n + 1, 1);
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v]] + 1, coef[v] = G[v].size();
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs(u);
        }
    };
    dfs(1);
    auto mark = [&](int &v, int &pv, int type) {
        if ((ord[v] & type) || find(fa[v]) == find(pv)) puts("0"), exit(0);
        ord[v] |= type, coef[v]--, unite(fa[v], pv);
        pv = v, v = fa[v];
    };
    auto solve = [&](int s, int t) {
        int ps = s + n, pt = t + 2 * n;
        while (dep[s] > dep[t]) mark(s, ps, 1);
        while (dep[t] > dep[s]) mark(t, pt, 2);
        while (s ^ t) mark(s, ps, 1), mark(t, pt, 2);
        if (find(ps) == find(pt)) puts("0"), exit(0);
        coef[s]--, unite(ps, pt);
    };
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        if (a) solve(a, i);
    }
    for (int i = 1; i <= n; i++) {
        if (coef[i] >= 0 && find(i + n) == find(i + 2 * n)) puts("0"), exit(0);
        ans = 1LL * ans * fact[max(0, coef[i])] % P;
    }
    printf("%d\n", ans);
    return 0;
}