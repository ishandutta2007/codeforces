#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans[200010], anst[200010];
struct query {
    int opt, l, r, x;
} q[200010];
vector < int > mdf[200010];
int _max[800010], lst[200010];
void build(int x, int l, int r) {
    if (l == r) {
        _max[x] = anst[l];
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    _max[x] = max(_max[x << 1], _max[x << 1 | 1]);
}
int query(int x, int l, int r, int L, int R) {
    if (l > R || L > r) return 0;
    if (L <= l && r <= R) return _max[x];
    int mid = l + r >> 1;
    return max(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
}
int main() {
    scanf("%d%d", &n, &m);
    memset(ans, -1, sizeof ans);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &q[i].opt);
        if (q[i].opt == 0) {
            scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].x);
            if (q[i].x == 0) {
                mdf[q[i].l].push_back(i);
                mdf[q[i].r + 1].push_back(-i);
            }
        }
        else scanf("%d", &q[i].x);
    }
    set < int > cur;
    for (int i = 1; i <= n; i++) {
        for (auto j : mdf[i]) if (j > 0) cur.insert(j); else cur.erase(-j);
        if (cur.size()) {
            ans[i] = 0;
            anst[i] = *cur.begin();
            lst[i] = lst[i - 1];
        }
        else lst[i] = i;
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        if (q[i].opt == 0 && q[i].x == 1) {
            int pos = lst[q[i].r];
            if (lst[pos - 1] >= q[i].l) continue;
            int t = max(query(1, 1, n, q[i].l, q[i].r), i);
            if (ans[pos] == -1) ans[pos] = 1, anst[pos] = t;
            else anst[pos] = min(anst[pos], t);
        }
    }
    for (int i = 1; i <= n; i++) cerr << anst[i] << " \n"[i == n];
    for (int i = 1; i <= m; i++) if (q[i].opt == 1) {
        if (ans[q[i].x] == -1 || i < anst[q[i].x]) puts("N/A");
        else puts(ans[q[i].x] ? "YES" : "NO");
    }
}