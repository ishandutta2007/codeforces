#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, tot, a[maxn], ind[maxn * 25], res[maxn], t[maxn << 2];
vector<int> G[maxn * 25];

void add_edge(int u, int v) {
    if (u) G[u].push_back(v), ind[v]++;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { t[k] = l; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    add_edge(t[ls], t[k] = ++tot), add_edge(t[rs], t[k]);
}

void ban(int k, int l, int r, int p) {
    if (l == r) { t[k] = 0; return; }
    mid >= p ? ban(ls, l, mid, p) : ban(rs, mid + 1, r, p);
    add_edge(t[ls], t[k] = ++tot), add_edge(t[rs], t[k]);
}

void link(int k, int l, int r, int ql, int qr, int id) {
    if (l >= ql && r <= qr) return add_edge(t[k], id);
    if (mid >= ql) link(ls, l, mid, ql, qr, id);
    if (mid < qr) link(rs, mid + 1, r, ql, qr, id);
}

int main() {
    scanf("%d", &n);
    build(1, 1, tot = n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (!~a[i]) {
            if (i > 1) link(1, 1, n, 1, i - 1, i);
            if (i < n) link(1, 1, n, i + 1, n, i);
        } else {
            if (min(i, a[i]) > 1) link(1, 1, n, 1, min(i, a[i]) - 1, i);
            if (i + 1 < a[i]) link(1, 1, n, i + 1, a[i] - 1, i);
            add_edge(i, a[i]), ban(1, 1, n, a[i]);
        }
    }
    queue<int> Q;
    for (int i = 1; i <= tot; i++) {
        if (!ind[i]) Q.push(i);
    }
    int num = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u <= n) res[u] = ++num;
        for (int v : G[u]) {
            if (!--ind[v]) Q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}