#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

struct node {
    ll sum, min_pref, max_pref;
} t[1 << 18];

int a[1 << 17];

node combine(const node& lhs, const node& rhs) {
    node result;
    result.sum = lhs.sum + rhs.sum;
    result.min_pref = min(lhs.min_pref, lhs.sum + rhs.min_pref);
    result.max_pref = max(lhs.max_pref, lhs.sum + rhs.max_pref);
    return result;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].sum = a[tl];
        t[v].min_pref = min(0, a[tl]);
        t[v].max_pref = max(0, a[tl]);
    } else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

node get(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) >> 1;
    if (r <= tm)
        return get(v * 2, tl, tm, l, r);
    if (l > tm)
        return get(v * 2 + 1, tm + 1, tr, l, r);
    return combine(get(v * 2, tl, tm, l, tm), get(v * 2 + 1, tm + 1, tr, tm + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] -= x;
    }

    build(1, 0, n - 1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        auto el = get(1, 0, n - 1, l, r);
        if (el.sum != 0 || el.max_pref > 0)
            cout << "-1\n";
        else {
            cout << -el.min_pref << '\n';
        }
    }
}