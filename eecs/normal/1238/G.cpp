#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int T, n, m, cur, C;
array<int, 3> a[maxn];

namespace SEG {
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)
int mx[maxn << 2], tag[maxn << 2];

void build(int k, int l, int r) {
    mx[k] = tag[k] = 0;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void apply(int k, int v) {
    mx[k] += v, tag[k] += v;
}
void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void upd(int k, int l, int r, int p, int v) {
    if (l == r) { mx[k] = v; return; }
    if (tag[k]) pushdown(k);
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    mx[k] = max(mx[ls], mx[rs]);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) return apply(k, v);
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    mx[k] = max(mx[ls], mx[rs]);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mx[k];
    if (tag[k]) pushdown(k);
    int s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s = max(s, query(rs, mid + 1, r, ql, qr));
    return s;
}
} // namespace SEG

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &C, &cur);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        }
        sort(a + 1, a + n + 1), cur -= (n ? a[1][0] : m);
        if (cur < 0) { puts("-1"); continue; }
        long long ans = 0;
        bool flag = 1;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> Q;
        SEG::build(1, 1, n);
        for (int i = 1; i <= n && flag; i++) {
            SEG::upd(1, 1, n, i, cur);
            int j = min((i < n ? a[i + 1][0] : m), a[i][0] + cur);
            cur -= j - a[i][0];
            Q.push({a[i][2], a[i][1], i});
            int rem = (i < n ? a[i + 1][0] : m) - j;
            while (rem) {
                if (Q.empty()) { flag = 0; break; }
                auto p = Q.top(); Q.pop();
                int j = p[2], x = SEG::query(1, 1, n, j, n);
                if (x == C) continue;
                int t = min({C - x, p[1], rem});
                ans += 1LL * t * p[0];
                SEG::add(1, 1, n, j, i, t), rem -= t;
                if (p[1] -= t) Q.push(p);
            }
        }
        printf("%lld\n", flag ? ans : -1);
    }
    return 0;
}