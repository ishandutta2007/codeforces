#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, pii> matrix;

const ll MOD = 1000000007;

#define x first
#define y second

matrix identity, fib;

inline matrix mult(matrix& a, matrix& b) {
    return { { ((ll)a.x.x * (ll)b.x.x + (ll)a.x.y * (ll)b.y.x) % MOD, ((ll)a.x.x * (ll)b.x.y + (ll)a.x.y * (ll)b.y.y) % MOD },
             { ((ll)a.y.x * (ll)b.x.x + (ll)a.y.y * (ll)b.y.x) % MOD, ((ll)a.y.x * (ll)b.x.y + (ll)a.y.y * (ll)b.y.y) % MOD } };
}

inline matrix add(matrix& a, matrix& b) {
    return { { (a.x.x + b.x.x) % MOD, (a.x.y + b.x.y) % MOD }, { (a.y.x + b.y.x) % MOD, (a.y.y + b.y.y) % MOD } };
}

matrix binpow(matrix a, ll deg) {
    if (deg == 0ll) return identity;
    if (deg & 1ll) {
        matrix b = binpow(a, deg ^ 1ll);
        return mult(a, b);
    }
    a = binpow(a, deg >> 1ll);
    return mult(a, a);
}

int n, m, a[100105];
int tp, x, y, z;
char pis[400105];
matrix t[400105], p[400105];

void build(int v, int tl, int tr) {
    pis[v] = false;
    p[v] = identity;
    if (tl == tr) {
        t[v] = binpow(fib, a[tl]);
    } else {
        int tm = (tl + tr) >> 1;
        build(v + v, tl, tm);
        build(v + v + 1, tm + 1, tr);
        t[v] = add(t[v + v], t[v + v + 1]);
    }
}

inline void push(int v, int tl, int tr) {
    if (pis[v]) {
        t[v] = mult(t[v], p[v]);
        if (tl != tr) {
            pis[v + v] = pis[v + v + 1] = 1;
            p[v + v] = mult(p[v + v], p[v]);
            p[v + v + 1] = mult(p[v + v + 1], p[v]);
        }
        pis[v] = 0;
        p[v] = identity;
    }
}

matrix val;

void update(int v, int tl, int tr, int l, int r) {
    if (l > r) return;
    push(v, tl, tr);
    if (tl == l && tr == r) {
        pis[v] = 1;
        p[v] = val;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    update(v + v, tl, tm, l, min(r, tm));
    update(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
    push(v + v, tl, tm);
    push(v + v + 1, tm + 1, tr);
    t[v] = add(t[v + v], t[v + v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    push(v, tl, tr);
    if (tl == l && tr == r) {
        return (t[v].x.x + t[v].x.y) % MOD;
    }
    int tm = (tl + tr) >> 1;
    return (get(v + v, tl, tm, l, min(r, tm)) + get(v + v + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
}

int main()
{
    identity = {{1, 0}, {0, 1}};
    fib = {{0, 1}, {1, 1}};

    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    build(1, 0, n - 1);
    while (m--) {
        cin >> tp >> x >> y;
        --x; --y;
        if (tp == 1) {
            cin >> z;
            val = binpow(fib, z);
            update(1, 0, n - 1, x, y);
        } else {
            cout << get(1, 0, n - 1, x, y) << "\n";
        }
    }

    return 0;
}