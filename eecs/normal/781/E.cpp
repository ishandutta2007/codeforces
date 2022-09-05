#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int h, w, n, ans, tot, mx = INT_MIN, f[maxn], id[maxn];
tuple<int, int, int, int> p[maxn];
struct node { int l, r; set<int> S; } t[maxn << 2];

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid (l + r >> 1)
void ins(int k, int l, int r, int ql, int qr, int p, bool v) {
    if (l >= ql && r <= qr) { v ? (void)t[k].S.insert(p) : (void)t[k].S.erase(p); return; }
    if (mid >= ql) ins(ls, l, mid, ql, qr, p, v);
    if (mid < qr) ins(rs, mid + 1, r, ql, qr, p, v);
}

void find(int k, int l, int r, int p, int v) {
    auto it = t[k].S.lower_bound(v);
    if (it != t[k].S.begin()) mx = max(mx, *--it);
    if (l == r) return;
    mid >= p ? find(ls, l, mid, p, v) : find(rs, mid + 1, r, p, v);
}

int main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &get<0>(p[i]), &get<1>(p[i]), &get<2>(p[i]), &get<3>(p[i]));
    }
    sort(p + 1, p + n + 1);
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int x, int y) {
        return get<0>(p[x]) + get<3>(p[x]) < get<0>(p[y]) + get<3>(p[y]);
    });
    auto calc = [&](int y, int z) {
        mx = INT_MIN, find(1, 1, w, y, z);
        return mx == INT_MIN ? 1 : f[mx];
    };
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        for (; pos <= n && get<0>(p[i]) > get<0>(p[id[pos]]) + get<3>(p[id[pos]]); pos++) {
            ins(1, 1, w, get<1>(p[id[pos]]), get<2>(p[id[pos]]), id[pos], 0);
        }
        if (get<1>(p[i]) == 1) {
            f[i] = 2 * calc(get<2>(p[i]) + 1, i) % P;
        } else if (get<2>(p[i]) == w) {
            f[i] = 2 * calc(get<1>(p[i]) - 1, i) % P;
        } else {
            f[i] = (calc(get<1>(p[i]) - 1, i) + calc(get<2>(p[i]) + 1, i)) % P;
        }
        ins(1, 1, w, get<1>(p[i]), get<2>(p[i]), i, 1);
    }
    for (int i = 1; i <= w; i++) {
        for (; pos <= n && h + 1 > get<0>(p[id[pos]]) + get<3>(p[id[pos]]); pos++) {
            ins(1, 1, w, get<1>(p[id[pos]]), get<2>(p[id[pos]]), id[pos], 0);
        }
        (ans += calc(i, n + 1)) %= P;
    }
    printf("%d\n", ans);
    return 0;
}