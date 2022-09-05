#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, ans, a[maxn], b[maxn], f[maxn], mn[maxn << 2], tag[maxn << 2];
map<int, int> mp;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int v) {
    mn[k] = tag[k] = v;
}

void pushdown(int k) {
    if (~tag[k]) apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = -1;
}

void modify(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) return apply(k, v);
    pushdown(k);
    if (mid >= ql) modify(ls, l, mid, ql, qr, v);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr, v);
    mn[k] = min(mn[ls], mn[rs]);
}

int find(int k, int l, int r, int v) {
    if (l == r) return mn[k] >= v ? l : l + 1;
    pushdown(k);
    if (mn[rs] >= v) return find(ls, l, mid, v);
    return find(rs, mid + 1, r, v);
}

int get(int k, int l, int r, int p) {
    if (l == r) return mn[k];
    pushdown(k);
    return mid >= p ? get(ls, l, mid, p) : get(rs, mid + 1, r, p);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> V(a + 1, a + n + 1);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
    }
    int m = max_element(a + 1, a + n + 1) - a;
    int fir = 0, sec = 0;
    bool flag1 = 1, flag2 = 1;
    memset(b, -1, sizeof(b));
    for (int i = 1; i <= m; i++) {
        if (a[i] > fir) fir = a[i];
        else if (a[i] > sec) sec = a[i];
        if (a[i] < sec) { flag1 = 0; break; }
        b[i] = a[i] == fir ? sec : fir;
    }
    int lmn = sec;
    fir = sec = 0;
    for (int i = n; i >= m; i--) {
        if (a[i] > fir) fir = a[i];
        else if (a[i] > sec) sec = a[i];
        if (a[i] < sec) { flag2 = 0; break; }
        b[i] = a[i] == fir ? sec : fir;
    }
    int rmn = sec;
    if (flag2) {
        memset(mn, 0x3f, sizeof(mn));
        memset(tag, -1, sizeof(tag));
        modify(1, 1, n + 1, 1, a[m], rmn);
        for (int i = m - 1; i; i--) {
            if (~b[i] && get(1, 1, n + 1, b[i] + 1) < a[i]) ans++;
            int o = get(1, 1, n + 1, a[i] + 1);
            int pos = find(1, 1, n + 1, a[i]);
            if (pos > 1) modify(1, 1, n + 1, 1, pos - 1, a[i]);
            modify(1, 1, n + 1, pos, n + 1, 0x3f3f3f3f);
            pos = find(1, 1, n + 1, o);
            if (pos <= a[i]) modify(1, 1, n + 1, pos, a[i], o);
        }
    }
    if (flag1) {
        memset(mn, 0x3f, sizeof(mn));
        memset(tag, -1, sizeof(tag));
        modify(1, 1, n + 1, 1, a[m], lmn);
        for (int i = m + 1; i <= n; i++) {
            if (~b[i] && get(1, 1, n + 1, b[i] + 1) < a[i]) ans++;
            int o = get(1, 1, n + 1, a[i] + 1);
            int pos = find(1, 1, n + 1, a[i]);
            if (pos > 1) modify(1, 1, n + 1, 1, pos - 1, a[i]);
            modify(1, 1, n + 1, pos, n + 1, 0x3f3f3f3f);
            pos = find(1, 1, n + 1, o);
            if (pos <= a[i]) modify(1, 1, n + 1, pos, a[i], o);
        }
    }
    printf("%d\n", ans);
    return 0;
}