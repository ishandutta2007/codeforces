#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int maxn = 100010;
int n, K, ans;
ll x[maxn], g[maxn], A[maxn], B[maxn];
struct node { ll tag, ans, ob, mxb; } t[maxn << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushdown(int k) {
    t[ls].tag += t[k].tag, t[ls].ans += t[k].tag, t[ls].mxb += t[k].tag;
    t[rs].tag += t[k].tag, t[rs].ans += t[k].tag, t[rs].mxb += t[k].tag;
    t[k].tag = 0;
}

ll calc(int k, int l, int r, ll mx) {
    if (l == r) return mx - t[k].ob;
    if (t[k].tag) pushdown(k);
    if (t[ls].mxb > mx) return min(t[k].ans, calc(ls, l, mid, mx));
    return min(mx - t[ls].ob, calc(rs, mid + 1, r, mx));
}

inline void maintain(int k, int l, int r) {
    t[k].mxb = max(t[ls].mxb, t[rs].mxb);
    t[k].ans = calc(rs, mid + 1, r, t[ls].mxb);
}

void build(int k, int l, int r) {
    if (l == r) { t[k].mxb = t[k].ob = B[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].ob = max(t[ls].ob, t[rs].ob);
    maintain(k, l, r);
}

void add(int k, int l, int r, int ql, int qr, ll v) {
    if (l >= ql && r <= qr) { t[k].tag += v, t[k].ans += v, t[k].mxb += v; return; }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    maintain(k, l, r);
}

int locate(int k, int l, int r, ll v) {
    if (l == r) return t[k].ob >= v ? l : -1;
    if (t[k].tag) pushdown(k);
    if (t[rs].ob >= v) return locate(rs, mid + 1, r, v);
    return locate(ls, l, mid, v);
}

int find(int k, int l, int r, ll mx) {
    if (l == r) return mx - t[k].ob <= K ? l : -1;
    if (t[k].tag) pushdown(k);
    if (t[ls].mxb < mx) {
        int t = find(rs, mid + 1, r, mx);
        return ~t ? t : locate(ls, l, mid, mx - K);
    }
    return t[k].ans <= K ? find(rs, mid + 1, r, t[ls].mxb) : find(ls, l, mid, mx);
}

int query(int l, int r) {
    if (l > 1) add(1, 1, n, 1, l - 1, -INF);
    add(1, 1, n, r, n, INF);
    int v = find(1, 1, n, -INF);
    if (l > 1) add(1, 1, n, 1, l - 1, INF);
    add(1, 1, n, r, n, -INF);
    return v;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &x[i + 1]), x[i + 1] += x[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &g[i]), g[i] += g[i - 1];
        A[i] = g[i - 1] - x[i], B[i] = g[i] - x[i];
    }
    build(1, 1, n);
    vector<int> st;
    for (int i = n; i; i--) {
        while (!st.empty() && A[st.back()] >= A[i]) {
            if (st.size() > 1) add(1, 1, n, st[st.size() - 2] - 1, n, A[st[st.size() - 2]] - A[st.back()]);
            st.pop_back();
        }
        if (!st.empty()) add(1, 1, n, st.back() - 1, n, A[i] - A[st.back()]);
        st.push_back(i);
        int l = 0, r = st.size() - 1, rb = st.size();
        while (l <= r) {
            A[i] - A[st[mid]] > K ? l = (rb = mid) + 1 : r = mid - 1;
        }
        rb = (rb == st.size() ? n + 1 : st[rb]) - 1;
        ans = max(ans, query(i, rb) - i + 1);
    }
    printf("%d\n", ans);
    return 0;
}