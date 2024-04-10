#include <cstdio>
#include <cstring>

using LL = long long;

const int N = 100;
const int M = 250;
const int MOD = (int)1e9 + 7;

int m, b[N];

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

struct Poly
{
    Poly() { memset(coef, 0, sizeof(coef)); }

    Poly& operator += (const Poly& o)
    {
        for (int i = 0; i < M; ++ i) {
            update(coef[i], o[i]);
        }
    }

    int& operator[](int i) { return coef[i]; }
    int operator[](int i) const { return coef[i]; }

    int coef[M];
};

Poly operator * (const Poly& a, const Poly& b_)
{
    static int buf[M + M];
    memset(buf, 0, sizeof(buf));
    for (int i = 0; i < M; ++ i) {
        for (int j = 0; j < M; ++ j) {
            update(buf[i + j], 1LL * a[i] * b_[j] % MOD);
        }
    }
    for (int i = M + M - 1; i >= M; -- i) {
        for (int j = 0; j < m; ++ j) {
            update(buf[i - b[j]], buf[i]);
        }
    }
    Poly c;
    memcpy(c.coef, buf, sizeof(c.coef));
    return c;
}

Poly pow(Poly a, LL n)
{
    Poly result;
    result[0] = 1;
    while (n) {
        if (n & 1) {
            result = result * a;
        }
        a = a * a;
        n >>= 1;
    }
    return result;
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("G.in", "r", stdin);
#endif
    static int a[N], x[M];
    int n;
    LL N_;
    scanf("%d%d%lld", &n, &m, &N_);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d", b + i);
    }
    Poly p;
    p[1] = 1;
    Poly s;
    for (int i = 0; i < n; ++ i) {
        s += pow(p, a[i]);
    }
    auto r = pow(s, N_);
    x[0] = 1;
    for (int i = 1; i < M; ++ i) {
        x[i] = 0;
        for (int j = 0; j < m; ++ j) {
            if (i >= b[j]) {
                update(x[i], x[i - b[j]]);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < M; ++ i) {
        update(result, 1LL * r[i] * x[i] % MOD);
    }
    printf("%d\n", result);
}