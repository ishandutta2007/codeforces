#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500010;
int n, q;
ll ans = LLONG_MIN, f[maxn], a[3][maxn], b[maxn];
ll mx[maxn << 2], mx2[maxn << 2], tag[maxn << 2];
vector<array<int, 2>> M[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, ll v) {
    mx[k] += v, tag[k] += v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void maintain(int k) {
    mx[k] = max(mx[ls], mx[rs]), mx2[k] = max(mx2[ls], mx2[rs]);
}

void build(int k, int l, int r) {
    if (l == r) { mx[k] = mx2[k] = a[0][l + 1] - a[1][l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    maintain(k);
}

void upd(int k, int l, int r, int p, ll v) {
    if (l == r) { if (mx2[k] < v) mx[k] = v + tag[k], mx2[k] = v; return; }
    if (tag[k]) pushdown(k);
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    maintain(k);
}

void add(int k, int l, int r, int ql, int qr, ll v) {
    if (l >= ql && r <= qr) return apply(k, v);
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

ll q1(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mx2[k];
    if (tag[k]) pushdown(k);
    ll s = LLONG_MIN;
    if (mid >= ql) s = q1(ls, l, mid, ql, qr);
    if (mid < qr) s = max(s, q1(rs, mid + 1, r, ql, qr));
    return s;
}

ll q2(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mx[k];
    if (tag[k]) pushdown(k);
    ll s = LLONG_MIN;
    if (mid >= ql) s = q2(ls, l, mid, ql, qr);
    if (mid < qr) s = max(s, q2(rs, mid + 1, r, ql, qr));
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]), a[i][j] += a[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        f[i] = a[0][i + 1];
    }
    build(1, 0, n - 1);
    while (q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        M[r].push_back({l, k});
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[1][i] - a[2][i - 1];
    }
    vector<int> st = {0};
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && b[st.back()] < b[i]) {
            add(1, 0, n - 1, st[st.size() - 2], st.back() - 1, -b[st.back()]);
            st.pop_back();
        }
        add(1, 0, n - 1, st.back(), i - 1, b[i]);
        st.push_back(i);
        for (auto &p : M[i]) {
            ll val = q1(1, 0, n - 1, p[0] - 1, i - 1) + a[1][i] - p[1];
            if (i < n) upd(1, 0, n - 1, i, val - a[1][i]);
            ans = max(ans, q2(1, 0, n - 1, p[0] - 1, i - 1) + a[2][n] - p[1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}