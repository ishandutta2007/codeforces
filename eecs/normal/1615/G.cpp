#include <bits/stdc++.h>
using namespace std;

struct general_matching {
    vector<vector<int>> g;
    int n;
    vector<int> mt, used, par;
    vector<int> dsu, tm, Q;
    int T;
    general_matching() : g(), n(0), mt(), used(), par(), dsu(), tm(), T() {}
    general_matching(int _n) {
        n = _n;
        g.clear();
        g.resize(n);
        mt = vector<int>(n, -1);
        used = vector<int>(n, 0);
        par = vector<int>(n, -1);
        dsu = vector<int>(n, -1);
        tm = vector<int>(n, 0);
        T = 1;
    }
    void add_edge(int v, int u) {
        g[v].push_back(u), g[u].push_back(v);
    }
    void clear() { mt = vector<int>(n, -1); }

    int find(int v) { return (dsu[v] == -1 ? v : dsu[v] = find(dsu[v])); }
    void unite(int v, int u) {
        v = find(v), u = find(u);
        if (v == u) return;
        dsu[v] = u;
    }
    int lca(int v, int u) {
        T++;
        while (true) {
            if (v == -1 && u == -1) return -1;
            swap(v, u);
            if (v == -1) continue;
            v = find(v);
            if (tm[v] == T) return v;
            tm[v] = T;
            if (mt[v] != -1) v = par[mt[v]];
            else v = -1;
        }
    }
    void shrink(int v, int p) {
        while (v != p) {
            int u = mt[v];
            int w = par[u];
            if (find(w) != p) par[w] = u;
            if (used[u] == 2) used[u] = 1, Q.push_back(u);
            if (used[w] == 2) used[w] = 1, Q.push_back(w);
            unite(v, u), unite(v, w), v = w;
        }
    }
    void alter_up(int u) {
        while (u != -1) {
            int v = par[u], w = mt[v];
            mt[v] = u, mt[u] = v, u = w;
        }
    }
    int bfs() {
        for (int it = 0; it < (int)Q.size(); it++) {
            int v = Q[it];
            for (int u : g[v]) {
                if (mt[v] == u) continue;
                if (find(v) == find(u)) continue;
                if (used[u] == 2) continue;
                if (used[u] == 1) {
                    int base = lca(v, u);
                    if (base == -1) {
                        int pv = mt[v], pu = mt[u];
                        mt[v] = u, mt[u] = v;
                        alter_up(pv), alter_up(pu);
                        return 1;
                    }
                    if (find(v) != base) par[v] = u;
                    if (find(u) != base) par[u] = v;
                    shrink(v, base);
                    shrink(u, base);
                } else if (mt[u] == -1) {
                    par[u] = v, alter_up(u);
                    return 1;
                } else {
                    par[u] = v, used[u] = 2;
                    u = mt[u], used[u] = 1, Q.push_back(u);
                }
            }
        }
        return 0;
    }
    int try_inc() {
        Q.clear();
        for (int i = 0; i < n; i++) {
            used[i] = 0, par[i] = dsu[i] = -1;
        }
        int RES = 0;
        for (int v = 0; v < n; v++) {
            if (mt[v] != -1) continue;
            bool fnd = false;
            for (int u : g[v]) if (mt[u] == -1) {
                fnd = true, RES++;
                mt[v] = u, mt[u] = v; break;
            }
            if (fnd) continue;
            used[v] = 1, Q.push_back(v);
        }
        return RES + bfs();
    }
    int inc_match() {
        int res = 0;
        while (true) {
            int cur = try_inc();
            if (cur == 0) break;
            res += cur;
        }
        return res;
    }
};

const int maxn = 300010;
int n, a[maxn];
bool occ[maxn], paired[maxn];

int main() {
    scanf("%d", &n), paired[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (!a[i]) continue;
        occ[a[i]] = 1;
        if (i > 1 && a[i - 1] == a[i]) paired[a[i]] = 1;
    }
    general_matching G(2 * n + 1);
    for (int i = 1, j; i <= n; i++) if (!a[i]) {
        for (j = i; j <= n && !a[j]; j++);
        if ((j - i) & 1) {
            if (!paired[a[i - 1]]) G.add_edge(a[i - 1], i + n);
            if (!paired[a[j]]) G.add_edge(a[j], i + n);
        } else if (a[i - 1] ^ a[j]) {
            if (!paired[a[i - 1]] && !paired[a[j]]) G.add_edge(a[i - 1], a[j]);
        }
        i = j - 1;
    }
    G.inc_match();
    auto fill = [&](int l, int r) {
        static int k = 1;
        while (l < r) {
            while (occ[k]) k++;
            a[l] = a[l + 1] = k++, l += 2;
        }
    };
    for (int i = 1, j, k = 1; i <= n; i++) if (!a[i]) {
        for (j = i; j <= n && !a[j]; j++);
        if ((j - i) & 1) {
            if (G.mt[a[i - 1]] == i + n) a[i] = a[i - 1], fill(i + 1, j - 1);
            else if (G.mt[a[j]] == i + n) a[j - 1] = a[j], fill(i, j - 2);
            else fill(i, j - 1);
        } else if (G.mt[a[i - 1]] == a[j]) {
            a[i] = a[i - 1], a[j - 1] = a[j], fill(i + 1, j - 2);
            G.mt[a[i - 1]] = G.mt[a[j]] = -1;
        } else {
            fill(i, j - 1);
        }
        i = j - 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i] ? a[i] : 1);
    }
    return 0;
}