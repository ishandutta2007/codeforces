#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, K, q, u[maxn], v[maxn], cur[maxn], id[maxn], c[maxn], lst[maxn];
bool ans[maxn];
vector<int> M[maxn << 1];

struct DSU {
    int fa[maxn], sz[maxn];
    vector<array<int, 2>> st;
    DSU() { iota(fa, fa + maxn, 0), fill(sz, sz + maxn, 1); }

    int find(int x) {
        while (x ^ fa[x]) x = fa[x];
        return x;
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        fa[x] = y, sz[y] += sz[x];
        st.push_back({x, y});
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void undo(int o) {
        while (st.size() > o) {
            fa[st.back()[0]] = st.back()[0];
            sz[st.back()[1]] -= sz[st.back()[0]], st.pop_back();
        }
    }
} T[51];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void ins(int k, int l, int r, int ql, int qr, int v) {
    if (ql > qr) return;
    if (l >= ql && r <= qr) { M[k].push_back(v); return; }
    if (mid >= ql) ins(ls, l, mid, ql, qr, v);
    if (mid < qr) ins(rs, mid + 1, r, ql, qr, v);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &id[i], &c[i]);
        if (lst[id[i]]) ins(1, 1, q, lst[id[i]] + 1, i - 1, lst[id[i]]);
        lst[id[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (lst[i]) ins(1, 1, q, lst[i] + 1, q, lst[i]);
    }
    function<void(int, int, int)> solve = [&](int k, int l, int r) {
        int sz[K + 1];
        for (int i = 1; i <= K; i++) sz[i] = T[i].st.size();
        for (int i : M[k]) {
            T[c[i]].unite(u[id[i]], v[id[i]] + n);
            T[c[i]].unite(u[id[i]] + n, v[id[i]]);
        }
        if (l == r) {
            int o = T[c[l]].st.size();
            T[c[l]].unite(u[id[l]], v[id[l]] + n);
            T[c[l]].unite(u[id[l]] + n, v[id[l]]);
            if (T[c[l]].same(u[id[l]], u[id[l]] + n)) c[l] = cur[id[l]];
            else cur[id[l]] = c[l], ans[l] = 1;
        } else {
            solve(ls, l, mid), solve(rs, mid + 1, r);
        }
        for (int i = 1; i <= K; i++) T[i].undo(sz[i]);
    };
    solve(1, 1, q);
    for (int i = 1; i <= q; i++) {
        puts(ans[i] ? "YES" : "NO");
    }
    return 0;
}