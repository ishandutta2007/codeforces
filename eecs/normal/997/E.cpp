#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 120010;
int n, q, a[maxn];
int val[maxn << 2], tag[maxn << 2], tim[maxn << 2], cnt[maxn << 2];
ll ans[maxn], sum[maxn << 2];
vector<pair<int, int>> Q[maxn];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void maintain(int k) {
    val[k] = min(val[ls], val[rs]), sum[k] = sum[ls] + sum[rs];
    cnt[k] = cnt[ls] * (val[k] == val[ls]) + cnt[rs] * (val[k] == val[rs]);
}

void apply(int k, int v) {
    val[k] += v, tag[k] += v;
}

void _apply(int k, int v) {
    sum[k] += 1LL * v * cnt[k], tim[k] += v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]);
    if (val[k] == val[ls]) _apply(ls, tim[k]);
    if (val[k] == val[rs]) _apply(rs, tim[k]);
    tag[k] = tim[k] = 0;
}

void build(int k, int l, int r) {
    val[k] = 1, cnt[k] = r - l + 1;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void modify(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { apply(k, v); return; }
    pushdown(k);
    if (mid >= ql) modify(ls, l, mid, ql, qr, v);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

ll query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[k];
    pushdown(k);
    ll s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 1, x, y; i <= q; i++) {
        scanf("%d %d", &x, &y), Q[y].emplace_back(x, i);
    }
    build(1, 1, n);
    vector<int> mn, mx;
    for (int i = 1; i <= n; i++) {
        modify(1, 1, n, 1, i, -1);
        while (!mn.empty() && a[mn.back()] > a[i]) {
            int lst = (mn.size() == 1 ? 0 : mn[mn.size() - 2]) + 1;
            modify(1, 1, n, lst, mn.back(), a[mn.back()] - a[i]), mn.pop_back();
        }
        mn.push_back(i);
        while (!mx.empty() && a[mx.back()] < a[i]) {
            int lst = (mx.size() == 1 ? 0 : mx[mx.size() - 2]) + 1;
            modify(1, 1, n, lst, mx.back(), a[i] - a[mx.back()]), mx.pop_back();
        }
        mx.push_back(i), _apply(1, 1);
        for (auto p : Q[i]) {
            ans[p.second] = query(1, 1, n, p.first, i);
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}