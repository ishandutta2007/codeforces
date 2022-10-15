#include <cstdio>

const int mod = (int)1e9 + 7;

inline int min(int a, int b) { return (a < b) ? a : b; }
inline int max(int a, int b) { return (a > b) ? a : b; }

struct matrix
{
    int a, b,
        c, d;
};

const matrix zero_matrix =
    {
        a: 0, b: 0,
        c: 0, d: 0
    };

const matrix single_matrix =
    {
        a: 1, b: 0,
        c: 0, d: 1
    };

const matrix fib_matrix =
    {
        a: 1, b: 1,
        c: 1, d: 0
    };

inline matrix operator+(const matrix& a, const matrix& b)
{
    matrix c;
    c.a = (a.a + b.a) % mod;
    c.b = (a.b + b.b) % mod;
    c.c = (a.c + b.c) % mod;
    c.d = (a.d + b.d) % mod;
    return c;
}

inline matrix operator*(const matrix& a, const matrix& b)
{
    matrix c;
    c.a = (1LL*a.a*b.a + 1LL*a.b*b.c) % mod;
    c.b = (1LL*a.a*b.b + 1LL*a.b*b.d) % mod;
    c.c = (1LL*a.c*b.a + 1LL*a.d*b.c) % mod;
    c.d = (1LL*a.c*b.b + 1LL*a.d*b.d) % mod;
    return c;
}

inline matrix& operator+=(matrix& a, const matrix& b) { return a = a + b; }
inline matrix& operator*=(matrix& a, const matrix& b) { return a = a * b; }

inline matrix bin_pow(matrix a, int pow)
{
    matrix res = single_matrix;
    while (pow)
    {
        if (pow & 1) res *= a;
        a *= a;
        pow >>= 1;
    }
    return res;
}

const int maxN = 100000;
const int maxSegTree = 4 * maxN;

matrix arr[maxN];
matrix push[maxSegTree];
matrix tree[maxSegTree];

void build(int x, int l, int r)
{
    if (l == r)
    {
        tree[x] = arr[l];
        push[x] = single_matrix;
        return;
    }
    int m = (l + r) / 2;
    build(x*2, l, m);
    build(x*2+1, m+1, r);
    tree[x] = tree[x*2] + tree[x*2+1];
    push[x] = single_matrix;
}

inline void add_push(int x, const matrix& m)
{
    push[x] *= m;
    tree[x] *= m;
}

void pushing(int x)
{
    add_push(x*2,   push[x]);
    add_push(x*2+1, push[x]);
    push[x] = single_matrix;
}

void update(int x, int l, int r, int ql, int qr, const matrix& val)
{
    if (ql > qr) return;
    if (l == ql && r == qr)
    {
        add_push(x, val);
        return;
    }
    pushing(x);
    int m = (l + r) / 2;
    update(x*2, l, m, ql, min(qr, m), val);
    update(x*2+1, m+1, r, max(ql, m+1), qr, val);
    tree[x] = tree[x*2] + tree[x*2+1];
}

matrix sum(int x, int l, int r, int ql, int qr)
{
    if (ql > qr) return zero_matrix;
    if (l == ql && r == qr) return tree[x];
    pushing(x);
    int m = (l + r) / 2;
    return sum(x*2, l, m, ql, min(qr, m)) +
           sum(x*2+1, m+1, r, max(ql, m+1), qr);
}

signed main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int a; scanf("%d", &a);
        arr[i] = bin_pow(fib_matrix, a);
    }
    build(1, 0, n-1);
    for (int i = 0; i < m; i++)
    {
        int a; scanf("%d", &a);
        if (a == 1)
        {
            int l, r, x; scanf("%d%d%d", &l, &r, &x); l--, r--;
            update(1, 0, n-1, l, r, bin_pow(fib_matrix, x));
        }
        else
        {
            int l, r; scanf("%d%d", &l, &r); l--, r--;
            printf("%d\n", sum(1, 0, n-1, l, r).b);
        }
    }
    return 0;
}