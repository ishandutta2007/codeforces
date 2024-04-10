#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, d, mx[maxn << 3], tag[maxn << 3];
pair<int, int> p[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int v) {
    mx[k] += v, tag[k] += v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void build(int k, int l, int r) {
    if (l == r) { mx[k] = d == l ? 0 : -1e9; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    mx[k] = max(mx[ls], mx[rs]);
}

void modify(int k, int l, int r, int p, int v) {
    if (l == r) { mx[k] = max(mx[k], v); return; }
    if (tag[k]) pushdown(k);
    if (mid >= p) modify(ls, l, mid, p, v);
    else modify(rs, mid + 1, r, p, v);
    mx[k] = max(mx[ls], mx[rs]);
}

void add(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { apply(k, 1); return; }
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr);
    if (mid < qr) add(rs, mid + 1, r, ql, qr);
    mx[k] = max(mx[ls], mx[rs]);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mx[k];
    if (tag[k]) pushdown(k);
    int ans = -1e9;
    if (mid >= ql) ans = query(ls, l, mid, ql, qr);
    if (mid < qr) ans = max(ans, query(rs, mid + 1, r, ql, qr));
    return ans;
}

int main() {
    scanf("%d %d", &n, &d);
    vector<int> V = {d};
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        V.push_back(p[i].first), V.push_back(p[i].second);
    }
    sort(p + 1, p + n + 1, [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.first + p1.second < p2.first + p2.second;
    });
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    d = lower_bound(V.begin(), V.end(), d) - V.begin() + 1;
    build(1, 1, V.size());
    for (int i = 1; i <= n; i++) {
        p[i].first = lower_bound(V.begin(), V.end(), p[i].first) - V.begin() + 1;
        p[i].second = lower_bound(V.begin(), V.end(), p[i].second) - V.begin() + 1;
        if (p[i].first > p[i].second) add(1, 1, V.size(), p[i].second + 1, p[i].first);
        modify(1, 1, V.size(), p[i].second, query(1, 1, V.size(), 1, min(p[i].first, p[i].second)) + 1);
    }
    printf("%d\n", mx[1]);
    return 0;
}