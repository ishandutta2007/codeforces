#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int MAXV = 101;

int a[MAXN];
int tree[MAXN << 2][MAXV];

void build(int v, int tl, int tr) {
    for (int i = 0; i < MAXV; ++i) {
        tree[v][i] = i;
    }   
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
}

void push(int v) {
    for (int i = 0; i < MAXV; ++i) {
        tree[v * 2 + 1][i] = tree[v][tree[v * 2 + 1][i]];
        tree[v * 2 + 2][i] = tree[v][tree[v * 2 + 2][i]];
    }   
    for (int i = 0; i < MAXV; ++i) {
        tree[v][i] = i;
    }
}

void upd(int v, int tl, int tr, int l, int r, int x, int y) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        for (int i = 0; i < MAXV; ++i) {
            if (tree[v][i] == x) tree[v][i] = y;
        }
        return;
    }   
    int tm = (tl + tr) / 2;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x, y);
    upd(v * 2 + 2, tm + 1, tr, l, r, x, y);
}   

void print(int v, int tl, int tr) {
    if (tl == tr) {
        cout << tree[v][a[tl]] << ' ';
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    print(v * 2 + 1, tl, tm);
    print(v * 2 + 2, tm + 1, tr);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    build(0, 0, n - 1);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        --l; --r;
        upd(0, 0, n - 1, l, r, x, y);
    }   

    print(0, 0, n - 1);
    cout << '\n';

    return 0;
}