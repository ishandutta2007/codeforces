#include <algorithm>
#include <cstdio>
#include <vector>
const int N = 1e6 + 10;
using namespace std;
int n, m;
vector<int>g[N];
int a[N], b[N], l[N], r[N], fa[N];
struct node{
    int sum;
    int mx, tag;
}f[N * 4];
void down(int l, int r, int s) {
    if (f[s].tag) {
        if (f[s].sum)f[s].mx += f[s].tag;
        if (l != r)
            f[s<<1].tag += f[s].tag, f[s<<1|1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void combine(int s) {
    f[s].sum = f[s + s].sum + f[s+s+1].sum;
    f[s].mx = max(f[s+s].mx, f[s+s+1].mx);
}
void ins(int l, int r, int s, int ll, bool sig) {
    down(l, r, s);
    if (r < ll || l > ll) return;
    if (l == r) {
        if (sig) f[s].sum = 1, f[s].mx = 0;
        else
            f[s].sum = f[s].mx = 0;
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, sig);
    ins((l + r) / 2 + 1, r, s + s + 1, ll, sig);
    combine(s);
}
void add(int l, int r, int s, int ll, int rr, int tag) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <=l && r <= rr) {
        f[s].tag += tag;
        down(l, r, s);
        return;
    }
    add(l, (l + r) / 2, s <<1, ll, rr, tag);
    add((l + r) /2  + 1, r, s + s + 1, ll, rr, tag);
    combine(s);
}
void dfs(int x) {
    static int tot = 0;
    l[x] = ++tot;
    for (auto u:g[x])
        if (u != fa[x]) {
            fa[u] = x;
            dfs(u);
        }
    r[x] = tot;
}
void ins(int x, int y) {
    while (x) {
        b[x] = y;
        x -= x & -x;
    }
}
int get(int x) {
    int v = 1e9;
    while (x <= n) {
        v = min(v, b[x]);
        x += x & -x;
    }
    return v;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
        b[i] = 1e9;
    for (int i = n; i >= 1; i --) {
        int v = get(a[i]);
        if (v != 1e9)
            g[v].push_back(i);
        ins(a[i] - 1, i);
    }
    for (int i = n; i >= 1; i --)
        if (!l[i])
            dfs(i);
    for (int i = 1; i <= m; i ++) {
        add(1, n, 1, l[i], r[i], 1);
        ins(1, n, 1, l[i], 1);
    }
    for (int i = 1; i + m - 1 <= n; i ++) {
        printf("%d ", f[1].mx + 1);
        ins(1, n ,1, l[i], 0);
        add(1, n, 1, l[i + m], r[i + m], 1);
        ins(1, n, 1, l[i + m], 1);
    }
    return 0;
}