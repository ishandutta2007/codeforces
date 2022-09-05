#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, tot = 1, lst = 1, num, rt[maxn], f[maxn], g[maxn];
int fa[maxn], len[maxn], ch[maxn][26], pos[maxn];
char s[maxn];
vector<int> G[maxn];
struct node { int l, r; } t[maxn << 5];

void extend(int c) {
    int p = lst, np = lst = ++tot;
    len[np] = pos[np] = len[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) { fa[np] = 1; return; }
    int q = ch[p][c];
    if (len[q] == len[p] + 1) {
        fa[np] = q;
    } else {
        int nq = ++tot; len[nq] = len[p] + 1;
        memcpy(ch[nq], ch[q], sizeof(ch[q])), pos[nq] = pos[q];
        fa[nq] = fa[q], fa[q] = fa[np] = nq;
        for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
    }
}

#define mid (l + r >> 1)
void ins(int &k, int l, int r, int p) {
    k = ++num;
    if (l == r) return;
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    int k = ++num;
    t[k].l = merge(t[k1].l, t[k2].l), t[k].r = merge(t[k1].r, t[k2].r);
    return k;
}

bool test(int k, int l, int r, int ql, int qr) {
    if (!k || l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return 1;
    return test(t[k].l, l, mid, ql, qr) | test(t[k].r, mid + 1, r, ql, qr);
}

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        extend(s[i] - 'a'), ins(rt[lst], 1, n, pos[lst]);
    }
    for (int i = 2; i <= tot; i++) {
        G[fa[i]].push_back(i);
    }
    function<void(int)> dfs1 = [&](int v) {
        for (int u : G[v]) {
            dfs1(u), rt[v] = merge(rt[v], rt[u]);
        }
    };
    function<void(int)> dfs2 = [&](int v) {
        for (int u : G[v]) {
            if (v > 1 && test(rt[g[v]], 1, n, pos[u] - len[u] + len[g[v]], pos[u] - 1)) f[u] = f[v] + 1, g[u] = u;
            else f[u] = f[v], g[u] = v == 1 ? u : g[v];
            dfs2(u);
        }
    };
    dfs1(1), dfs2(1);
    printf("%d\n", *max_element(f, f + tot + 1) + 1);
    return 0;
}