#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, n, m, a[maxn], b[maxn], c[maxn * 2], cnt[maxn * 2];
int mn[maxn << 2], tag[maxn << 2], ans[maxn * 2];
vector<int> pos[maxn * 2];

void add(int p, int v) {
    cnt[p] += v;
    for (; p <= n + m; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int v) {
    mn[k] += v, tag[k] += v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void build(int k, int l, int r) {
    mn[k] = tag[k] = 0;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { apply(k, v); return; }
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    mn[k] = min(mn[ls], mn[rs]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector<int> V;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), V.push_back(a[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]), V.push_back(b[i]);
        }
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        fill(c + 1, c + n + m + 1, 0);
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
            res += i - 1 - sum(a[i]), add(a[i], 1);
        }
        for (int i = 1; i <= m; i++) {
            b[i] = lower_bound(V.begin(), V.end(), b[i]) - V.begin() + 1;
        }
        build(1, 0, n);
        for (int i = 1; i <= n + m; i++) {
            pos[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            add(1, 0, n, i, n, 1), pos[a[i]].push_back(i);
        }
        for (int i = 1; i <= n + m; i++) {
            for (int j : pos[i - 1]) add(1, 0, n, 0, j - 1, 1);
            for (int j : pos[i]) add(1, 0, n, j, n, -1);
            ans[i] = mn[1];
        }
        for (int i = 1; i <= m; i++) {
            res += ans[b[i]];
        }
        printf("%lld\n", res);
    }
    return 0;
}