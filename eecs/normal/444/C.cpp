#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m;
set<tuple<int, int, int>> S;

namespace SEG {
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

typedef long long ll;
ll sum[maxn << 2], tag[maxn << 2];

void pushdown(int k, int l, int r) {
    sum[ls] += tag[k] * (mid - l + 1), tag[ls] += tag[k];
    sum[rs] += tag[k] * (r - mid), tag[rs] += tag[k], tag[k] = 0;
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { sum[k] += 1LL * v * (r - l + 1), tag[k] += v; return; }
    if (tag[k]) pushdown(k, l, r);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    sum[k] = sum[ls] + sum[rs];
}

ll query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[k];
    if (tag[k]) pushdown(k, l, r);
    ll s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}
}  // namespace SEG

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        S.emplace(i, i, i);
    }
    auto cov = [&](int l, int r, int v) {
        vector<tuple<int, int, int>> V;
        while (1) {
            auto it = S.lower_bound(make_tuple(l, 0, 0));
            if (it != S.begin() && get<1>(*prev(it)) >= l) it--;
            if (it == S.end() || get<0>(*it) > r) break;
            int lb = max(get<0>(*it), l), rb = min(get<1>(*it), r);
            SEG::add(1, 1, n, lb, rb, abs(v - get<2>(*it)));
            if (get<0>(*it) < lb) V.emplace_back(get<0>(*it), lb - 1, get<2>(*it));
            if (get<1>(*it) > rb) V.emplace_back(rb + 1, get<1>(*it), get<2>(*it));
            S.erase(it);
        }
        S.emplace(l, r, v);
        for (auto p : V) S.insert(p);
    };
    while (m--) {
        int op, l, r, x;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) scanf("%d", &x), cov(l, r, x);
        else printf("%lld\n", SEG::query(1, 1, n, l, r));
    }
    return 0;
}