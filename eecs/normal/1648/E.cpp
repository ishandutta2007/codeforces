#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, u[maxn], v[maxn], w[maxn], bel[maxn * 2];
int tim, tid[maxn * 2], id[maxn], val[maxn * 2];
int stot, L[maxn * 2], R[maxn * 2], rt[maxn];
int dep[maxn * 2], fa[maxn * 2][20], mxe[maxn * 2][20];
vector<array<int, 3>> E, _E;
vector<int> ver, G[maxn * 2];
vector<array<int, 2>> H[maxn], ban[maxn * 2];
set<int> S[maxn * 2];
struct node { int l, r, s; } t[maxn * 20];

int find(int x) {
    return x == bel[x] ? x : bel[x] = find(bel[x]);
}

#define mid ((l + r) >> 1)
void ins(int &k, int l, int r, int p) {
    t[k = ++stot] = (node){0, 0, 1};
    if (l == r) return;
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

int find(int k, int l, int r, int p) {
    if (t[k].s == r - l + 1) return -1;
    if (l == r) return l;
    int x = -1;
    if (mid >= p) x = find(t[k].l, l, mid, p);
    if (!~x) x = find(t[k].r, mid + 1, r, p);
    return x;
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    t[k1].l = merge(t[k1].l, t[k2].l);
    t[k1].r = merge(t[k1].r, t[k2].r);
    t[k1].s = t[t[k1].l].s + t[t[k1].r].s;
    return k1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        E.clear(), _E.clear();
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
            E.push_back({w[i], u[i], v[i]});
        }
        iota(bel + 1, bel + n + 1, 1);
        sort(E.begin(), E.end());
        for (auto &e : E) if (find(e[1]) ^ find(e[2])) {
            _E.push_back(e), bel[find(e[1])] = find(e[2]);
        }
        swap(E, _E);
        iota(bel + 1, bel + 2 * n, 1);
        for (int i = 1; i < 2 * n; i++) {
            G[i].clear();
        }
        ver.clear();
        int tot = n;
        for (auto &e : E) {
            int u = find(e[1]), v = find(e[2]);
            bel[u] = bel[v] = ++tot, ver.push_back(tot);
            val[tot] = e[0], G[tot].push_back(u), G[tot].push_back(v);
        }
        assert(tot == find(1));
        function<void(int)> init = [&](int u) {
            dep[u] = dep[fa[u][0]] + 1;
            for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
            L[u] = tim + 1;
            if (G[u].empty()) tid[u] = ++tim, id[tim] = u;
            for (int v : G[u]) fa[v][0] = u, init(v);
            R[u] = tim;
        };
        tim = stot = 0, fa[tot][0] = 0;
        init(tot), assert(tim == n);
        for (int i = 1; i <= n; i++) {
            ins(rt[i], 1, n, i);
        }
        for (int i = 1; i <= tot; i++) {
            ban[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int x = u[i], y = v[i];
            if (dep[x] < dep[y]) swap(x, y);
            for (int j = 19; ~j; j--) {
                if (dep[fa[x][j]] >= dep[y]) x = fa[x][j];
            }
            if (x == y) { ban[x].push_back({u[i], v[i]}); continue; }
            for (int j = 19; ~j; j--) {
                if (fa[x][j] ^ fa[y][j]) x = fa[x][j], y = fa[y][j];
            }
            ban[fa[x][0]].push_back({u[i], v[i]});
        }
        sort(ver.begin(), ver.end(), [&](int x, int y) { return val[x] < val[y]; });
        iota(bel + 1, bel + n + 1, 1);
        for (int i = 1; i <= n; i++) {
            H[i].clear();
        }
        for (int x : ver) {
            assert(G[x].size() == 2);
            for (auto &p : ban[x]) {
                S[tid[p[0]]].insert(tid[p[1]]), S[tid[p[1]]].insert(tid[p[0]]);
            }
            if (R[G[x][0]] - L[G[x][0]] > R[G[x][1]] - L[G[x][1]]) swap(G[x][0], G[x][1]);
            for (int i = L[G[x][0]]; i <= R[G[x][0]]; i++) {
                int l = L[G[x][1]], r = R[G[x][1]];
                while (l <= r) {
                    int y = find(rt[find(i)], 1, n, l);
                    if (!~y || y > r) break;
                    if (S[i].count(y)) { l = y + 1; continue; }
                    H[id[i]].push_back({id[y], val[x]});
                    H[id[y]].push_back({id[i], val[x]});
                    rt[find(y)] = merge(rt[find(y)], rt[find(i)]);
                    bel[find(i)] = find(y);
                }
            }
            for (auto &p : ban[x]) {
                S[tid[p[0]]].erase(tid[p[1]]), S[tid[p[1]]].erase(tid[p[0]]);
            }
        }
        function<void(int)> rdfs = [&](int u) {
            dep[u] = dep[fa[u][0]] + 1;
            for (int i = 1; i < 20; i++) {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
                mxe[u][i] = max(mxe[u][i - 1], mxe[fa[u][i - 1]][i - 1]);
            }
            for (auto &e : H[u]) if (e[0] ^ fa[u][0]) {
                fa[e[0]][0] = u, mxe[e[0]][0] = e[1], rdfs(e[0]);
            }
        };
        fa[1][0] = mxe[1][0] = 0, rdfs(1);
        for (int i = 1; i <= m; i++) {
            int x = u[i], y = v[i], ans = 0;
            if (dep[x] < dep[y]) swap(x, y);
            for (int j = 19; ~j; j--) {
                if (dep[fa[x][j]] >= dep[y]) ans = max(ans, mxe[x][j]), x = fa[x][j];
            }
            if (x == y) { printf("%d%c", ans, " \n"[i == m]); continue; }
            for (int j = 19; ~j; j--) if (fa[x][j] ^ fa[y][j]) {
                ans = max({ans, mxe[x][j], mxe[y][j]});
                x = fa[x][j], y = fa[y][j];
            }
            ban[fa[x][0]].push_back({u[i], v[i]});
            ans = max({ans, mxe[x][0], mxe[y][0]});
            printf("%d%c", ans, " \n"[i == m]);
        }
    }
    return 0;
}