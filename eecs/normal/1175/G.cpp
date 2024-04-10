#include <bits/stdc++.h>
using namespace std;

const int maxn = 20010;
int n, K, cur, a[maxn], lb[maxn], rb[maxn], f[110][maxn], pos[maxn << 2];
vector<int> V[maxn << 2];
vector<array<int, 2>> tr[maxn << 2];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { V[k] = {l}; return; }
    build(ls, l, mid), build(rs, mid + 1, r), V[k] = V[ls];
    copy(V[rs].begin(), V[rs].end(), back_inserter(V[k]));
    auto chk = [&](int i, int j, int k) {
        return 1LL * (f[cur][j] - f[cur][i]) * (k - j) >= 1LL * (f[cur][k] - f[cur][j]) * (j - i);
    };
    vector<int> st;
    for (int x : V[k]) {
        while (st.size() > 1 && chk(st[st.size() - 2], st.back(), x)) st.pop_back();
        st.push_back(x);
    }
    V[k] = st;
}

int query(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) {
        auto eval = [&](int i) { return V[k][i] * v + f[cur][V[k][i]]; };
        while (pos[k] + 1 < V[k].size() && eval(pos[k]) > eval(pos[k] + 1)) pos[k]++;
        return eval(pos[k]);
    }
    int mn = INT_MAX;
    if (mid >= ql) mn = query(ls, l, mid, ql, qr, v);
    if (mid < qr) mn = min(mn, query(rs, mid + 1, r, ql, qr, v));
    return mn;
}

void ins(int k, int l, int r, int ql, int qr, array<int, 2> v) {
    if (l >= ql && r <= qr) { tr[k].push_back(v); return; }
    if (mid >= ql) ins(ls, l, mid, ql, qr, v);
    if (mid < qr) ins(rs, mid + 1, r, ql, qr, v);
}

struct line {
    int k, b;
    line(int _k = 0, int _b = 1e9) : k(_k), b(_b) {}
    int operator () (int x) { return k * x + b; }
} lct[maxn << 2];
vector<pair<int, line>> id;

void ins(int k, int l, int r, line v) {
    id.emplace_back(k, lct[k]);
    if (v(mid) < lct[k](mid)) swap(v, lct[k]);
    if (l == r) return;
    v.k > lct[k].k ? ins(ls, l, mid, v) : ins(rs, mid + 1, r, v);
}

int query(int k, int l, int r, int p) {
    if (l == r) return lct[k](p);
    return min(lct[k](p), mid >= p ? query(ls, l, mid, p) : query(rs, mid + 1, r, p));
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> st = {0};
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && a[st.back()] <= a[i]) st.pop_back();
        lb[i] = st.back() + 1, st.push_back(i);
    }
    st = {n + 1};
    for (int i = n; i; i--) {
        while (st.size() > 1 && a[st.back()] < a[i]) st.pop_back();
        rb[i] = st.back() - 1, st.push_back(i);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0, x = 0; i <= n; i++) {
        x = max(x, a[i]), f[1][i] = i * x;
    }
    vector<int> ord(n - 1);
    iota(ord.begin(), ord.end(), 2);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    function<void(int, int, int)> solve = [&](int k, int l, int r) {
        int o = id.size();
        for (auto &v : tr[k]) {
            ins(1, 1, n, line(v[0], v[1]));
        }
        if (l == r) {
            f[cur + 1][l] = query(1, 1, n, l);
        } else {
            solve(ls, l, mid), solve(rs, mid + 1, r);
        }
        while (id.size() > o) {
            lct[id.back().first] = id.back().second, id.pop_back();
        }
    };
    for (cur = 1; cur < K; cur++) {
        build(1, 1, n - 1);
        memset(pos, 0, sizeof(pos));
        fill(tr, tr + (n << 2), vector<array<int, 2>>());
        for (int i : ord) {
            int v = query(1, 1, n - 1, lb[i] - 1, i - 1, -a[i]);
            ins(1, 1, n, i, rb[i], {a[i], v});
        }
        solve(1, 1, n);
    }
    printf("%d\n", f[K][n]);
    return 0;
}