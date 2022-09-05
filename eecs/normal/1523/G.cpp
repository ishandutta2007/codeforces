#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, l[maxn], r[maxn], c[maxn], ans[maxn], id[maxn];
int tot, cur, rt[maxn << 2], rt2[maxn << 2];
struct node { int l, r, mn = INT_MAX, mn2 = INT_MAX; } t[maxn * 200];

void chk(int &x, int y) {
    if (x > y) x = y;
}

#define mid (l + r >> 1)
void add(int &k, int l, int r, int ql, int qr, int v) {
    if (!k) k = ++tot;
    if (l >= ql && r <= qr) { chk(t[k].mn2, v); return; }
    chk(t[k].mn, v);
    if (mid >= ql) add(t[k].l, l, mid, ql, qr, v);
    if (mid < qr) add(t[k].r, mid + 1, r, ql, qr, v);
}

void get(int k, int l, int r, int ql, int qr) {
    if (!k) return;
    chk(cur, t[k].mn2);
    if (l >= ql && r <= qr) { chk(cur, t[k].mn); return; }
    if (mid >= ql) get(t[k].l, l, mid, ql, qr);
    if (mid < qr) get(t[k].r, mid + 1, r, ql, qr);
}

#define ls (k << 1)
#define rs (k << 1 | 1)
void ins(int k, int l, int r, int l1, int r1, int l2, int r2, int v) {
    if (l >= l1 && r <= r1) { add(rt2[k], 1, n, l2, r2, v); return; }
    add(rt[k], 1, n, l2, r2, v);
    if (mid >= l1) ins(ls, l, mid, l1, r1, l2, r2, v);
    if (mid < r1) ins(rs, mid + 1, r, l1, r1, l2, r2, v);
}

void query(int k, int l, int r, int l1, int r1, int l2, int r2) {
    get(rt2[k], 1, n, l2, r2);
    if (l >= l1 && r <= r1) { get(rt[k], 1, n, l2, r2); return; }
    if (mid >= l1) query(ls, l, mid, l1, r1, l2, r2);
    if (mid < r1) query(rs, mid + 1, r, l1, r1, l2, r2);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    iota(id + 1, id + m + 1, 1);
    sort(id + 1, id + m + 1, [&](int x, int y) { return r[x] - l[x] > r[y] - l[y]; });
    auto upd = [&](int i) {
        ins(1, 1, n, 1, l[i], r[i], n, i);
    };
    auto find = [&](int l, int r) {
        cur = INT_MAX;
        if (l + 1 <= r - 1) query(1, 1, n, l + 1, r - 1, l + 1, r - 1);
        return make_tuple(cur, l, r);
    };
    for (int i = n, j = 1; i; i--) {
        for (; j <= m && r[id[j]] - l[id[j]] + 1 >= i; j++) upd(id[j]);
        set<tuple<int, int, int>> cand;
        cand.emplace(find(0, n + 1));
        while (get<0>(*cand.begin()) <= m) {
            auto p = *cand.begin(); cand.erase(cand.begin());
            ans[i] += r[get<0>(p)] - l[get<0>(p)] + 1;
            cand.emplace(find(get<1>(p), l[get<0>(p)]));
            cand.emplace(find(r[get<0>(p)], get<2>(p)));
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}