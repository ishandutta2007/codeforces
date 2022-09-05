#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, tot, fa[maxn], ans[maxn], rt[maxn], d[maxn], e[maxn], dep[maxn];
struct node { int ch[2], d, v = -1e9; } t[maxn * 25];

void chk(int &x, int y) {
    if (x < y) x = y;
}

void ins(int k, int p, int v) {
    for (int i = 21; ~i; i--) {
        t[k].ch[0] = ++tot, k = t[k].ch[0];
    }
    chk(t[k].v, v);
}

void dfs(int k1, int k2, int i, int d, int &ans, int diff) {
    if (!k1 || !k2) return;
    if (!~i) { chk(ans, t[k1].v + t[k2].v + diff); return; }
    d ^= t[k1].d ^ t[k2].d;
    dfs(t[k1].ch[0], t[k2].ch[d >> i & 1], i - 1, d, ans, diff);
    dfs(t[k1].ch[1], t[k2].ch[!(d >> i & 1)], i - 1, d, ans, diff);
}

int merge(int k1, int k2, int i, int d, int &ans, int diff) {
    if (!k1 && !k2) return 0;
    if (!k2) return k1;
    if (!k1) { t[k2].d ^= d; return k2; }
    if (!~i) {
        chk(ans, t[k1].v + t[k2].v + diff), chk(t[k1].v, t[k2].v);
        return k1;
    }
    d ^= t[k1].d ^ t[k2].d;
    dfs(t[k1].ch[1], t[k2].ch[d >> i & 1], i - 1, d, ans, diff);
    dfs(t[k1].ch[0], t[k2].ch[!(d >> i & 1)], i - 1, d, ans, diff);
    t[k1].ch[0] = merge(t[k1].ch[0], t[k2].ch[d >> i & 1], i - 1, d, ans, diff);
    t[k1].ch[1] = merge(t[k1].ch[1], t[k2].ch[!(d >> i & 1)], i - 1, d, ans, diff);
    return k1;
}

int main() {
    scanf("%d", &n);
    // mt19937 rnd(time(0)); n = 500000;
    for (int i = 2; i <= n; i++) {
        char c[2]; scanf("%d %s", &fa[i], c);
        // fa[i] = rnd() % (i - 1) + 1, c[0] = rnd() % ('v' - 'a' + 1) + 'a';
        e[i] = 1 << (c[0] - 'a'), dep[i] = dep[fa[i]] + 1;
    }
    iota(rt + 1, rt + n + 1, 1), tot = n;
    for (int i = 1; i <= n; i++) {
        ins(rt[i], 0, dep[i]);
    }
    for (int i = n; i > 1; i--) {
        ans[fa[i]] = max(ans[fa[i]], ans[i]);
        t[rt[i]].d ^= e[i];
        rt[fa[i]] = merge(rt[fa[i]], rt[i], 21, 0, ans[fa[i]], -2 * dep[fa[i]]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}