#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, L, R, lim, ans1, ans2, rt, sz[maxn], dep[maxn], dist[maxn];
bool flag, solved[maxn];
vector<array<int, 2>> G[maxn];

namespace SEG {
#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
pair<int, int> mx[maxn << 2];

void build(int k, int l, int r) {
    mx[k] = {-1e9, 0};
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void upd(int k, int l, int r, int p, pair<int, int> v) {
    mx[k] = max(mx[k], v);
    if (l < r) mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
}

pair<int, int> query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mx[k];
    pair<int, int> s(-1e9, 0);
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s = max(s, query(rs, mid + 1, r, ql, qr));
    return s;
}
} // namespace SEG

int main() {
    scanf("%d %d %d", &n, &L, &R);
    vector<int> W;
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w), W.push_back(w);
        G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    function<void(int, int, int)> find_rt = [&](int u, int fa, int all) {
        sz[u] = 1;
        int mx = 0;
        for (auto &e : G[u]) if (!solved[e[0]] && e[0] ^ fa) {
            find_rt(e[0], u, all), sz[u] += sz[e[0]];
            mx = max(mx, sz[e[0]]);
        }
        if (max(mx, all - sz[u]) <= all / 2) rt = u;
    };
    function<void(int, int)> solve = [&](int x, int all) {
        if (all <= L) return;
        solved[x] = 1, dep[x] = dist[x] = 0;
        SEG::build(1, 0, all), SEG::upd(1, 0, all, 0, {0, x});
        for (auto &e : G[x]) if (!solved[e[0]]) {
            function<void(int, int, int)> dfs1 = [&](int u, int fa, int w) {
                if (flag) return;
                dep[u] = dep[fa] + 1, dist[u] = dist[fa] + (w >= lim ? 1 : -1);
                if (max(0, L - dep[u]) <= min(all, R - dep[u])) {
                    auto p = SEG::query(1, 0, all, max(0, L - dep[u]), min(all, R - dep[u]));
                    if (dist[u] + p.first >= 0) flag = 1, ans1 = u, ans2 = p.second;
                }
                for (auto &e : G[u]) {
                    if (!solved[e[0]] && e[0] ^ fa) dfs1(e[0], u, e[1]);
                }
            };
            function<void(int, int)> dfs2 = [&](int u, int fa) {
                if (flag) return;
                if (dep[u] <= R) SEG::upd(1, 0, all, dep[u], {dist[u], u});
                sz[u] = 1;
                for (auto &e : G[u]) if (!solved[e[0]] && e[0] ^ fa) {
                    dfs2(e[0], u), sz[u] += sz[e[0]];
                }
            };
            dfs1(e[0], x, e[1]), dfs2(e[0], x);
            if (flag) break;
        }
        if (flag) return;
        for (auto &e : G[x]) if (!solved[e[0]]) {
            find_rt(e[0], x, sz[e[0]]), solve(rt, sz[e[0]]);
        }
    };
    sort(W.begin(), W.end());
    int l = 0, r = W.size() - 1;
    while (l <= r) {
        lim = W[mid], flag = 0;
        memset(solved, 0, sizeof(solved));
        find_rt(1, 0, n), solve(rt, n);
        flag ? l = mid + 1 : r = mid - 1;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}