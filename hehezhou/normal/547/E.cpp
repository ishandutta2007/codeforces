#include <bits/stdc++.h>
using namespace std;
struct tree {
    int c[400010], n;
    inline void init(int x) {n = x;}
    inline void add(int x, int k) {
        for (; x <= n; x += x & -x) c[x] += k;
    }
    inline int calc(int x) {
        int ans = 0;
        for (; x; x &= x - 1) ans += c[x];
        return ans;
    }
    inline int calc(int l, int r) {return calc(r) - calc(l - 1);}
} c;
int son[400010][26], cnt = 1, parent[400010], len[400010];
int last;
inline int add(int ch) {
    if (son[last][ch] && len[son[last][ch]] == len[last] + 1) return last = son[last][ch];
    int p = last, np = ++cnt;
    len[np] = len[last] + 1;
    for (; p && son[p][ch] == 0; p = parent[p]) son[p][ch] = np;
    if (p == 0) parent[np] = 1;
    else {
        int q = son[p][ch];
        if (len[q] == len[p] + 1) parent[np] = q;
        else {
            int nq = ++cnt;
            memcpy(son[nq], son[q], sizeof son[q]);
            len[nq] = len[p] + 1;
            parent[nq] = parent[q];
            parent[q] = parent[np] = nq;
            for (; son[p][ch] == q; p = parent[p]) son[p][ch] = nq;
        }
    }
    return last = son[last][ch];
}
vector < int > pos[200010];
vector < int > edge[400010];
int dfn[400010], sze[400010];
inline void dfs(int now) {
    static int dfsnow = 0;
    dfn[now] = ++dfsnow;
    sze[now] = 1;
    for (auto i : edge[now]) dfs(i), sze[now] += sze[i];
}
struct query {
    int id, x, r, k;
    friend inline int operator < (const query &a, const query &b) {
        return a.r < b.r;
    }
} q[1000010];
int ans[500010];
int id[500010];
char s[200010];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        last = 1;
        for (int j = 0; j < len; j++) pos[i].push_back(add(s[j] - 'a'));
        id[i] = last;
    }
    for (int i = 2; i <= cnt; i++) edge[parent[i]].push_back(i);
    dfs(1);
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        q[i * 2 - 1] = {i, x, l - 1, -1};
        q[i * 2] = {i, x, r, 1};
    }
    sort(q + 1, q + 1 + m + m);
    c.init(cnt);
    for (int i = 1; i <= m + m; i++) {
        for (int j = q[i - 1].r + 1; j <= q[i].r; j++) {
            for (auto k : pos[j]) c.add(dfn[k], 1);
        }
        ans[q[i].id] += q[i].k * c.calc(dfn[id[q[i].x]], dfn[id[q[i].x]] + sze[id[q[i].x]] - 1);
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}