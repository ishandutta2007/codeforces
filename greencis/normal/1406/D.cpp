#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;

int a[100100];
ll t[1 << 18];
ll p[1 << 18];

inline void push(int v, int tl, int tr) {
    if (p[v]) {
        if (tl == tr)
            t[v] += p[v];
        else {
            p[v << 1] += p[v];
            p[(v << 1) ^ 1] += p[v];
        }
        p[v] = 0;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) ^ 1, tm + 1, tr);
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return;
    if (tl == l && tr == r)
        p[v] += x;
    else {
        int tm = (tl + tr) >> 1;
        update(v << 1, tl, tm, l, min(r, tm), x);
        update((v << 1) ^ 1, tm + 1, tr, max(l, tm + 1), r, x);
    }
}

ll get(int v, int tl, int tr, int idx) {
    while (tl != tr) {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        v <<= 1;
        if (idx <= tm)
            tr = tm;
        else {
            v ^= 1;
            tl = tm + 1;
        }
    }
    push(v, tl, tr);
    return t[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    ll suminc = 0;
    for (int i = 0; i + 1 < n; ++i) {
        suminc += max(a[i + 1] - a[i], 0);
    }

    cout << ((a[0] + suminc + 1) >> 1) << '\n';
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        if (l > 0) {
            ll x = get(1, 0, n - 1, l - 1);
            ll y = get(1, 0, n - 1, l);
            if (x < y)
                suminc -= y - x;
        }
        if (r < n - 1) {
            ll x = get(1, 0, n - 1, r);
            ll y = get(1, 0, n - 1, r + 1);
            if (x < y)
                suminc -= y - x;
        }
        update(1, 0, n - 1, l, r, x);
        if (l > 0) {
            ll x = get(1, 0, n - 1, l - 1);
            ll y = get(1, 0, n - 1, l);
            if (x < y)
                suminc += y - x;
        }
        if (r < n - 1) {
            ll x = get(1, 0, n - 1, r);
            ll y = get(1, 0, n - 1, r + 1);
            if (x < y)
                suminc += y - x;
        }
        ll cur = get(1, 0, n - 1, 0) + suminc;
        cout << ((cur + 1) >> 1) << '\n';
    }
}