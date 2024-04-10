#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline void Add(int &x, int y) {
    if ((x += y) >= mod) x -= mod;
}
int n, t[400010];
int a[200010], b[200010], need[400010];
int tag[400010 * 4];
inline void down(int x) {
    Add(tag[x << 1], tag[x]);
    Add(tag[x << 1 | 1], tag[x]);
    tag[x] = 0;
}
inline void add(int x, int l, int r, int L, int R, int v) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) return Add(tag[x], v);
    int mid = l + r >> 1;
    down(x);
    add(x << 1, l, mid, L, R, v);
    add(x << 1 | 1, mid + 1, r, L, R, v);
}
inline int query(int x, int l, int r, int k) {
    if (l == r) return tag[x];
    int mid = l + r >> 1;
    down(x);
    if (k <= mid) return query(x << 1, l, mid, k);
    else return query(x << 1 | 1, mid + 1, r, k);
}
vector < int > qs[400010];
int ans = 0;
void dfs(int l, int r) {
    if (l > r) return;
    if (need[r] == 0 || t[r] < l) dfs(l, r - 1);
    else {
        qs[r].push_back(l);
        ans++;
        dfs(t[r], r - 1);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
        t[b[i]] = a[i];
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        need[b[x]] = 1;
    }
    n *= 2;
    dfs(1, n);
    for (int i = 1; i <= n; i++) {
        for (auto j : qs[i]) Add(ans, query(1, 1, n, j));
        if (t[i] == 0) continue;
        int cur = 1 + query(1, 1, n, t[i]);
        add(1, 1, n, 1, t[i], cur);
    }
    printf("%d\n", ans);
}