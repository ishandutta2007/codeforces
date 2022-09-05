#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, tim = -1, lnk[maxn], tid[maxn], ed[maxn];
char s[maxn];
vector<int> G[maxn];

int id(int x, int y) {
    if (x && x <= n && y && y <= m) return (x - 1) * m + y + 2;
    return ((x + y) & 1) + 1;
}

namespace SEG {
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
int mn[maxn << 1], tag[maxn << 1], cnt[maxn << 1];

void maintain(int k) {
    mn[k] = min(mn[ls], mn[rs]);
    cnt[k] = (mn[ls] == mn[k]) * cnt[ls] + (mn[rs] == mn[k]) * cnt[rs];
}

void pushdown(int k) {
    mn[ls] += tag[k], tag[ls] += tag[k];
    mn[rs] += tag[k], tag[rs] += tag[k], tag[k] = 0;
}

void build(int k, int l, int r) {
    cnt[k] = r - l + 1;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { mn[k] += v, tag[k] += v; return; }
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}
}  // namespace SEG

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            auto add = [&](int x, int y) { G[x].push_back(y); };
            if (s[j] == 'U') add(id(i + 2, j), id(i, j)), lnk[id(i, j)] = id(i + 1, j);
            if (s[j] == 'D') add(id(i - 2, j), id(i, j)), lnk[id(i, j)] = id(i - 1, j);
            if (s[j] == 'L') add(id(i, j + 2), id(i, j)), lnk[id(i, j)] = id(i, j + 1);
            if (s[j] == 'R') add(id(i, j - 2), id(i, j)), lnk[id(i, j)] = id(i, j - 1);
        }
    }
    SEG::build(1, 1, n * m / 2);
    function<void(int)> dfs1 = [&](int v) {
        tid[v] = ++tim;
        for (int u : G[v]) dfs1(u);
        ed[v] = tim;
    };
    long long ans = 1LL * n * n * m * m / 4;
    function<void(int)> dfs2 = [&](int v) {
        int t = lnk[v];
        SEG::add(1, 1, n * m / 2, tid[t], ed[t], 1);
        if (!SEG::mn[1]) ans -= SEG::cnt[1];
        for (int u : G[v]) dfs2(u);
        SEG::add(1, 1, n * m / 2, tid[t], ed[t], -1);
    };
    dfs1(2);
    for (int v : G[1]) dfs2(v);
    printf("%lld\n", ans);
    return 0;
}