#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, odd, fa[maxn], sz[maxn], ans[maxn];
vector<int> foo[maxn << 2];
vector<pair<int, int>> st;
struct edge {
    int u, v, w, t;
    bool operator < (const edge &o) const { return w > o.w; }
} e[maxn];
priority_queue<edge> Q;

int find(int x) {
    return x == fa[x] ? x : find(fa[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    odd -= (sz[x] & 1) + (sz[y] & 1);
    fa[x] = y, sz[y] += sz[x];
    odd += sz[y] & 1, st.emplace_back(x, y);
}

void undo() {
    int u = st.back().first, v = st.back().second;
    odd -= sz[v] & 1;
    fa[u] = u, sz[v] -= sz[u];
    odd += (sz[u] & 1) + (sz[v] & 1), st.pop_back();
}

void ins(int k, int l, int r, int ql, int qr, int p) {
    if (l >= ql && r <= qr) { foo[k].push_back(p); return; }
    int mid = (l + r) >> 1;
    if (mid >= ql) ins(k << 1, l, mid, ql, qr, p);
    if (mid < qr) ins(k << 1 | 1, mid + 1, r, ql, qr, p);
}

int main() {
    scanf("%d %d", &n, &m), odd = n;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        e[i].t = i, Q.push(e[i]);
    }
    iota(fa + 1, fa + n + 1, 1);
    fill(sz + 1, sz + n + 1, 1);
    function<void(int, int, int, int)> solve = [&](int k, int l, int r, int mx) {
        int lst = st.size();
        for (int p : foo[k]) {
            unite(e[p].u, e[p].v), mx = max(mx, e[p].w);
        }
        if (l == r) {
            vector<edge> bar;
            while (odd && !Q.empty()) {
                auto p = Q.top(); Q.pop();
                if (p.t > l) continue;
                unite(p.u, p.v), mx = max(mx, p.w), bar.push_back(p);
            }
            if (odd) {
                ans[l] = -1;
            } else {
                for (auto p : bar) if (p.t < l) {
                    ins(1, 1, m, p.t, l - 1, p.t);
                }
                ans[l] = mx;
            }
        } else {
            int mid = (l + r) >> 1;
            solve(k << 1 | 1, mid + 1, r, mx);
            solve(k << 1, l, mid, mx);
        }
        while (st.size() > lst) undo();
    };
    solve(1, 1, m, 0);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}