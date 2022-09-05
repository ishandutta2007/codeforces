#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 50010, maxV = maxn * 100;
int n, m, tot, ch[maxV][2], tag[maxV];
bool mark[maxV];
ll U, a[maxn], b[maxn];
char op[maxn][10];
vector<pair<int, int>> E[maxn];

void pushdown(int k) {
    if (!ch[k][0]) ch[k][0] = ++tot;
    if (!ch[k][1]) ch[k][1] = ++tot;
    if (tag[k]) tag[ch[k][0]] = tag[ch[k][1]] = tag[k], tag[k] = 0;
}

#define mid ((l + r) >> 1)
void cov(int k, ll l, ll r, ll ql, ll qr, int v) {
    if (l >= ql && r <= qr) { tag[k] = v; return; }
    pushdown(k);
    if (mid >= ql) cov(ch[k][0], l, mid, ql, qr, v);
    if (mid < qr) cov(ch[k][1], mid + 1, r, ql, qr, v);
}

void dfs(int k) {
    if (!ch[k][0] && !ch[k][1]) { mark[k] = 1; return; }
    pushdown(k), dfs(ch[k][0]), dfs(ch[k][1]);
}

void merge(int k1, int k2) {
    if (mark[k1] && mark[k2]) { E[min(tag[k1], tag[k2])].emplace_back(k1, k2); return; }
    if (mark[k1]) merge(k1, ch[k2][0]), merge(k1, ch[k2][1]);
    else if (mark[k2]) merge(ch[k1][0], k2), merge(ch[k1][1], k2);
    else merge(ch[k1][0], ch[k2][0]), merge(ch[k1][1], ch[k2][1]);
}

int get(int k, ll l, ll r, ll p) {
    if (mark[k]) return k;
    return mid >= p ? get(ch[k][0], l, mid, p) : get(ch[k][1], mid + 1, r, p);
}

namespace DSU {
int fa[maxV];
void init() { iota(fa + 1, fa + tot + 1, 1); }

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void unite(int x, int y) { fa[find(x)] = find(y); }
bool test(int x, int y) { return find(x) == find(y); }
}  // namespace DSU

int main() {
    scanf("%d %d", &n, &m), U = (1LL << n) - 1;
    tag[++tot] = m + 1;
    for (int i = 1; i <= m; i++) {
        scanf("%s %lld %lld", op[i], &a[i], &b[i]);
        if (op[i][0] == 'b') cov(1, 0, U, a[i], b[i], i);
    }
    dfs(1);
    for (int i = 1; i <= tot; i++) {
        if (!mark[i]) merge(ch[i][0], ch[i][1]);
    }
    DSU::init();
    for (auto &e : E[m + 1]) {
        DSU::unite(e.first, e.second);
    }
    vector<int> ans;
    for (int i = m; i; i--) {
        if (op[i][0] == 'b') {
            for (auto &e : E[i]) DSU::unite(e.first, e.second);
        } else {
            ans.push_back(DSU::test(get(1, 0, U, a[i]), get(1, 0, U, b[i])));
        }
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d\n", x);
    return 0;
}