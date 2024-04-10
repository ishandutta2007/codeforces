#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5 * 1e5 + 1;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int t[4 * N];

void build(int l, int r, int v, vector <int> &a) {
    if (l == r) t[v] = a[l];
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v, a);
        build(m + 1, r, 2 * v + 1, a);
        t[v] = gcd(t[2 * v], t[2 * v + 1]);
    }
}

int query(int l, int r, int v, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) >> 1;
    return gcd(query(l, m, 2 * v, ql, qr), query(m + 1, r, 2 * v + 1, ql, qr));
}

void change(int ind, int val, int l, int r, int v) {
    if (ind < l || r < ind) return;
    if (l == r) {
        t[v] = val;
    }
    else {
        int m = (l + r) >> 1;
        change(ind, val, l, m, 2 * v);
        change(ind, val, m + 1, r, 2 * v + 1);
        t[v] = gcd(t[2 * v], t[2 * v + 1]);
    }
}


int get_first(int l, int r, int v, int ql, int qr, int x) {
    if (r < ql || qr < l || t[v] % x == 0) return -1;
    if (l == r) {
        return l;
    }
    else {
        int m = (l + r) >> 1;
        int a = get_first(l, m, 2 * v, ql, qr, x);
        if (a != -1) return a;
        return get_first(m + 1, r, 2 * v + 1, ql, qr, x);
    }
}

int get_last(int l, int r, int v, int ql, int qr, int x) {
    if (r < ql || qr < l || t[v] % x == 0) return -1;
    if (l == r) {
        return l;
    }
    else {
        int m = (l + r) >> 1;
        int a = get_last(m + 1, r, 2 * v + 1, ql, qr, x);
        if (a != -1) return a;
        return get_last(l, m, 2 * v, ql, qr, x);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    build(0, n - 1, 1, a);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            --l, --r;
            if (query(0, n - 1, 1, l, r) == x) {
                puts("YES");
            }
            else {
                int first = get_first(0, n - 1, 1, l, r, x);
                int last = get_last(0, n - 1, 1, l, r, x);
                if (first == last) {
                    puts("YES");
                }
                else {
                    puts("NO");
                }
            }
        }
        else {
            int ind, y;
            scanf("%d %d", &ind, &y);
            --ind;
            change(ind, y, 0, n - 1, 1);
        }
    }
}