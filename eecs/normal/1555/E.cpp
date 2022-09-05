#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, maxm = 1000010;
int n, m, ans = INT_MAX;
tuple<int, int, int> p[maxn];
struct node { int mn, tag; } t[maxm << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushdown(int k) {
    t[ls].mn += t[k].tag, t[ls].tag += t[k].tag;
    t[rs].mn += t[k].tag, t[rs].tag += t[k].tag, t[k].tag = 0;
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { t[k].mn += v, t[k].tag += v; return; }
    pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

int main() {
    scanf("%d %d", &n, &m), m--;
    for (int i = 1, l, r, w; i <= n; i++) {
        scanf("%d %d %d", &l, &r, &w);
        p[i] = make_tuple(l, r - 1, w);
    }
    sort(p + 1, p + n + 1, [&](tuple<int, int, int> p1, tuple<int, int, int> p2) { return get<2>(p1) < get<2>(p2); });
    for (int i = 1, j = 0; i <= n; i++) {
        if (i > 1) add(1, 1, m, get<0>(p[i - 1]), get<1>(p[i - 1]), -1);
        while (j < n && !t[1].mn) {
            j++, add(1, 1, m, get<0>(p[j]), get<1>(p[j]), 1);
        }
        if (!t[1].mn) break;
        ans = min(ans, get<2>(p[j]) - get<2>(p[i]));
    }
    printf("%d\n", ans);
    return 0;
}