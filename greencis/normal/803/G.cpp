#include <bits/stdc++.h>
using namespace std;

int n, k, a[100105], h[100105];
int table[20][100105];
int m, tp, x, y, z;

void build_sparse_table() {
    for (int i = 0; i < n; ++i)
        table[0][i] = a[i];
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 0; j < n; ++j)
            table[i][j] = min(table[i - 1][j], j + (1 << (i - 1)) < n ? table[i - 1][j + (1 << (i - 1))] : INT_MAX);
    int curh = 0;
    for (int i = 1; i < 100105; ++i) {
        while ((1 << curh) <= i)
            ++curh;
        h[i] = curh - 1;
    }
}

inline int get_sparse_table(int l, int r) {
    int len = r - l + 1;
    return min(table[h[len]][l], table[h[len]][r - (1 << h[len]) + 1]);
}

inline int get_old(int l, int r) {
    if (r - l + 1 >= n)
        return get_sparse_table(0, n - 1);
    l %= n;
    r %= n;
    if (l <= r)
        return get_sparse_table(l, r);
    return min(get_sparse_table(l, n - 1), get_sparse_table(0, r));
}

struct node {
    node *L, *R;
    int mn, p;
} *t = NULL;

inline void check(node *& t, int tl, int tr) {
    if (!t) {
        t = new node();
        t->L = t->R = NULL;
        t->mn = get_old(tl, tr);
        t->p = INT_MAX;
    }
}

inline void push(node *& t, int tl, int tr) {
    check(t, tl, tr);
    if (t->p != INT_MAX) {
        t->mn = t->p;
        if (tl < tr) {
            int tm = (tl + tr) >> 1;
            check(t->L, tl, tm);
            check(t->R, tm + 1, tr);
            t->L->p = t->p;
            t->R->p = t->p;
        }
        t->p = INT_MAX;
    }
}

void update(node *& t, int tl, int tr, int l, int r, int val) {
    if (l > r)
        return;
    push(t, tl, tr);
    if (tl == l && tr == r) {
        t->p = val;
        push(t, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    update(t->L, tl, tm, l, min(r, tm), val);
    update(t->R, tm + 1, tr, max(l, tm + 1), r, val);
    push(t->L, tl, tm);
    push(t->R, tm + 1, tr);
    t->mn = min(t->L->mn, t->R->mn);
}

int get(node *& t, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    push(t, tl, tr);
    if (tl == l && tr == r)
        return t->mn;
    int tm = (tl + tr) >> 1;
    return min(get(t->L, tl, tm, l, min(r, tm)), get(t->R, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build_sparse_table();

    cin >> m;
    while (m--) {
        cin >> tp >> x >> y;
        if (tp == 1) {
            cin >> z;
            update(t, 0, n * k - 1, x - 1, y - 1, z);
        } else
            cout << get(t, 0, n * k - 1, x - 1, y - 1) << "\n";
    }

    return 0;
}