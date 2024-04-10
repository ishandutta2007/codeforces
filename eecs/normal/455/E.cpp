#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, a[maxn], s[maxn], b[maxn];
vector<array<int, 2>> st[maxn << 2];

long long cross(array<int, 2> x, array<int, 2> y, array<int, 2> z) {
    return 1LL * (y[0] - x[0]) * (z[1] - y[1]) - 1LL * (z[0] - y[0]) * (y[1] - x[1]);
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { st[k] = {{a[l], b[l]}}; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    merge(st[ls].begin(), st[ls].end(), st[rs].begin(), st[rs].end(), back_inserter(st[k]), greater<>());
    vector<array<int, 2>> V;
    for (auto &p : st[k]) {
        while (V.size() > 1 && cross(V[V.size() - 2], V.back(), p) >= 0) V.pop_back();
        V.push_back(p);
    }
    swap(st[k], V);
}

int query(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) {
        auto eval = [&](int i) { return v * st[k][i][0] + st[k][i][1]; };
        int l = 0, r = st[k].size() - 1;
        while (l < r) {
            eval(mid) < eval(mid + 1) ? r = mid : l = mid + 1;
        }
        return eval(l);
    }
    int s = INT_MAX;
    if (mid >= ql) s = query(ls, l, mid, ql, qr, v);
    if (mid < qr) s = min(s, query(rs, mid + 1, r, ql, qr, v));
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
        b[i] = i * a[i] - s[i - 1];
    }
    build(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y), x--;
        printf("%d\n", query(1, 1, n, y - x, y, x - y) + s[y]);
    }
    return 0;
}