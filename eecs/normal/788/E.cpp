#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010, P = 1000000007;
int n, m, a[maxn], L[maxn], R[maxn], c[maxn], ans[maxn];
int foo[maxn], bar[maxn], pre[maxn], suf[maxn];
vector<int> V, pos[maxn];
vector<tuple<int, int, int>> Q[maxn];
struct node { int sa, sb, sc, _sa, _sb, sum, tag1, tag2; } t[maxn << 2];

inline void red(int &x) {
    x += x >> 31 & P;
}

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void maintain(int k) {
    red(t[k].sa = t[ls].sa + t[rs].sa - P);
    red(t[k].sb = t[ls].sb + t[rs].sb - P);
    t[k].sc = t[ls].sc + t[rs].sc;
    red(t[k].sum = t[ls].sum + t[rs].sum - P);
}

void push1(int k, int v) {
    red(t[k].sa += 1LL * v * t[k].sc % P - P);
    red(t[k]._sa += v - P);
    red(t[k].sum += 1LL * v * t[k].sb % P - P);
    red(t[k].tag1 += v - P);
}

void push2(int k, int v) {
    red(t[k].sb += 1LL * v * t[k].sc % P - P);
    red(t[k]._sb += v - P);
    red(t[k].sum += 1LL * v * t[k].sa % P - P);
    red(t[k].tag2 += v - P);
}

void pushdown(int k) {
    if (t[k].tag1) push1(ls, t[k].tag1), push1(rs, t[k].tag1), t[k].tag1 = 0;
    if (t[k].tag2) push2(ls, t[k].tag2), push2(rs, t[k].tag2), t[k].tag2 = 0;
}

void build(int k, int l, int r) {
    t[k].tag1 = t[k].tag2 = 0;
    if (l == r) {
        t[k].sa = t[k]._sa = pre[l], t[k].sb = t[k]._sb = suf[r], t[k].sc = 1;
        t[k].sum = 1LL * pre[l] * suf[r] % P; return;
    }
    build(ls, l, mid), build(rs, mid + 1, r), maintain(k);
}

void upd1(int k, int l, int r, int p, int v) {
    if (l == r) {
        t[k].sa = v * t[k]._sa, t[k].sb = v * t[k]._sb, t[k].sc = v;
        t[k].sum = 1LL * v * t[k]._sa * t[k]._sb % P; return;
    }
    pushdown(k);
    mid >= p ? upd1(ls, l, mid, p, v) : upd1(rs, mid + 1, r, p, v);
    maintain(k);
}

void upd2(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { push1(k, v); return; }
    pushdown(k);
    if (mid >= ql) upd2(ls, l, mid, ql, qr, v);
    if (mid < qr) upd2(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

void upd3(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { push2(k, v); return; }
    pushdown(k);
    if (mid >= ql) upd3(ls, l, mid, ql, qr, v);
    if (mid < qr) upd3(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
        pos[a[i]].push_back(i);
        L[i] = sum(a[i]), add(a[i], 1);
    }
    memset(c, 0, sizeof(c));
    for (int i = n; i; i--) {
        R[i] = sum(a[i]), add(a[i], 1);
    }
    scanf("%d", &m);
    for (int i = 1, op, x; i <= m; i++) {
        scanf("%d %d", &op, &x);
        Q[a[x]].emplace_back(x, op, i);
    }
    for (int i = 1; i <= n; i++) if (!pos[i].empty()) {
        for (int j = 0; j < pos[i].size(); j++) {
            foo[j] = L[pos[i][j]], bar[j] = R[pos[i][j]];
        }
        for (int j = 1; j < pos[i].size(); j++) {
            pre[j] = (pre[j - 1] + foo[j - 1]) % P;
        }
        suf[pos[i].size() - 1] = 0;
        for (int j = (int)pos[i].size() - 2; ~j; j--) {
            suf[j] = (suf[j + 1] + bar[j + 1]) % P;
        }
        build(1, 0, pos[i].size() - 1);
        red(ans[0] += t[1].sum - P);
        for (auto p : Q[i]) {
            int x = get<0>(p), lst = t[1].sum, coef = get<1>(p) == 1 ? P - 1 : 1;
            x = lower_bound(pos[i].begin(), pos[i].end(), x) - pos[i].begin();
            upd1(1, 0, pos[i].size() - 1, x, get<1>(p) == 1 ? 0 : 1);
            upd2(1, 0, pos[i].size() - 1, x, pos[i].size() - 1, 1LL * foo[x] * coef % P);
            upd3(1, 0, pos[i].size() - 1, 0, x, 1LL * bar[x] * coef % P);
            red(ans[get<2>(p)] += t[1].sum - lst);
        }
    }
    for (int i = 1; i <= m; i++) {
        red(ans[i] += ans[i - 1] - P);
        printf("%d\n", ans[i]);
    }
    return 0;
}