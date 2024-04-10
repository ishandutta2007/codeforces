#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5 + 5, IT_SIZE = 1 << 18, MAX_BITCOUNT = 47, MOD = 1e9 + 7;

int L[IT_SIZE], R[IT_SIZE];
long long a[MAX_N];

struct matrix {long long a, b, c, d;};
matrix ZERO = {0, 0, 0, 0}, base = {1, 0, 0, 1}, m[MAX_BITCOUNT] = {{0, 1, 1, 1}}, A[IT_SIZE], lazy[IT_SIZE];
bool operator != (const matrix &X, const matrix &Y) {return (X.a != Y.a || X.b != Y.b || X.c != Y.c || X.d != Y.d);}

matrix operator + (const matrix &X, const matrix &Y) {
    matrix Z;
    Z.a = (X.a + Y.a) % MOD;
    Z.b = (X.b + Y.b) % MOD;
    Z.c = (X.c + Y.c) % MOD;
    Z.d = (X.d + Y.d) % MOD;
    return Z;
}

matrix operator * (const matrix &X, const matrix &Y) {
    matrix Z;
    Z.a = (X.a * Y.a + X.b * Y.c) % MOD;
    Z.b = (X.a * Y.b + X.b * Y.d) % MOD;
    Z.c = (X.c * Y.a + X.d * Y.c) % MOD;
    Z.d = (X.c * Y.b + X.d * Y.d) % MOD;
    return Z;
}

void InitMatrix() {
    for (int i = 1; i < MAX_BITCOUNT; ++i)
        m[i] = m[i - 1] * m[i - 1];
}

matrix power(const long long &x) {
    matrix ans = base;
    for (int i = 0; i < MAX_BITCOUNT; ++i)
        if (x >> i & 1)
            ans = ans * m[i];
    return ans;
}

void InitSegmentTree(const int &l, const int &r, int idx = 0) {
    L[idx] = l; R[idx] = r;
    if (l == r)
        A[idx] = m[0] * power(a[l]);
    else {
        InitSegmentTree(l, l + r >> 1, idx<<1^1);
        InitSegmentTree((l + r >> 1) + 1, r, idx+1<<1);
        A[idx] = A[idx<<1^1] + A[idx+1<<1];
    }
    lazy[idx] = base;
}

void Propagate(int idx) {
    if (lazy[idx] != base && L[idx] != R[idx]) {
        A[idx<<1^1] = A[idx<<1^1] * lazy[idx];
        lazy[idx<<1^1] = lazy[idx<<1^1] * lazy[idx];
        A[idx+1<<1] = A[idx+1<<1] * lazy[idx];
        lazy[idx+1<<1] = lazy[idx+1<<1] * lazy[idx];
        lazy[idx] = base;
    }
}

void Update(const int &l, const int &r, const matrix &x, int idx = 0) {
    if (L[idx] >  r || R[idx] <  l) return;
    if (L[idx] >= l && R[idx] <= r) {
        A[idx] = A[idx] * x;
        lazy[idx] = lazy[idx] * x;
        return;
    }
    Propagate(idx);
    Update(l, r, x, idx<<1^1);
    Update(l, r, x, idx+1<<1);
    A[idx] = A[idx<<1^1] + A[idx+1<<1];
}

matrix GetVal(const int &l, const int &r, int idx = 0) {
    if (L[idx] >  r || R[idx] <  l) return ZERO;
    if (L[idx] >= l && R[idx] <= r) return A[idx];
    Propagate(idx);
    return (GetVal(l, r, idx<<1^1) + GetVal(l, r, idx+1<<1));
}

int main() {
    InitMatrix();
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);
    InitSegmentTree(1, n);
    while (m--) {
        int c, l, r; scanf("%d%d%d", &c, &l, &r);
        switch (c) {
            case 1: long long x; scanf("%I64d", &x); Update(l, r, power(x)); break;
            case 2: printf("%I64d\n", GetVal(l, r).a); break;
        }
    }
    return 0;
}