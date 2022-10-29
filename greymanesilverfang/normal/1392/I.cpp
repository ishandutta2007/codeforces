#include <cstdio>
#include <complex>
#include <cmath>
#include <algorithm>
#include <vector>
#define vec std::vector
#define ll long long
#define cp std::complex<double>
const int LOG = 18, MAX = 1e5, LIM = MAX*2, LEN = 1<<LOG;
int cnt[MAX];
cp num[LEN/2];

void precalc() {
    const double PI = acos(-1);
    for (int i = 0; i < LEN; i += 2) {
        double x = PI / LEN * i;
        num[i / 2] = cp(cos(x), sin(x));
    }
}

vec<int> join(const vec<int> &a) {
    vec<int> res(a.size() - 1);
    for (int i = 1; i < a.size(); ++i)
        res[i - 1] = std::min(a[i - 1], a[i]);
    return res;
}

vec<cp> sz(const vec<int> &a) {
    vec<cp> res(LEN);
    for (int x : a)
        res[x] += 1.0;
    return res;
}

vec<cp> bitRev(const vec<cp> &a) {
    vec<cp> res(LEN);
    for (int i = 0; i < LEN; ++i) {
        int tmp = i, id = 0;
        for (int i = 0; i < LOG; ++i) {
            id = id * 2 + tmp % 2;
            tmp /= 2;
        }
        res[id] = a[i];
    }
    return res;
}

vec<cp> fft(const vec<cp> &a) {
    vec<cp> res = bitRev(a);
    for (int i = 2; i <= LEN; i *= 2) {
        for (int j = 0; j < LEN; j += i) {
            int x = j, y = j + i / 2, z = 0;
            for (int k = 0; k < i / 2; ++k) {
                res[y] = res[x] - res[y] * num[z];
                res[x] = res[x] * 2.0 - res[y];
                ++x, ++y, z += LEN / i;
            }
        }
    }
    return res;
}

vec<cp> conj(const vec<cp> &a) {
    vec<cp> res(LEN);
    for (int i = 0; i < LEN; ++i)
        res[i] = std::conj(a[i]);
    return res;
}

vec<cp> fftInv(const vec<cp> &a) {
    vec<cp> res = conj(fft(conj(a)));
    for (int i = 0; i < LEN; ++i)
        res[i] /= LEN;
    return res;
}

vec<cp> mul(const vec<cp> &a, const vec<cp> &b) {
    vec<cp> res(LEN);
    for (int i = 0; i < LEN; ++i)
        res[i] = a[i] * b[i];
    return fftInv(res);
}

vec<ll> calc(const vec<cp> &a, const vec<cp> &b) {
    vec<cp> c = mul(a, b);
    vec<ll> res(LIM);
    for (int i = 0; i < LIM; ++i)
        res[i] = (ll)round(c[i].real());
    return res;
}

vec<ll> solve(const vec<int> &a, const vec<int> &b) {
    vec<int> c = join(a), d = join(b);
    vec<cp> m = fft(sz(a)), n = fft(sz(b)), p = fft(sz(c)), q = fft(sz(d));
    vec<ll> w = calc(m, n), x = calc(m, q), y = calc(p, n), z = calc(p, q);
    vec<ll> res(LIM);
    for (int i = 0; i < LIM; ++i)
        res[i] = w[i] - x[i] - y[i] + z[i];
    for (int i = 1; i < LIM; ++i)
        res[i] += res[i - 1];
    return res;
}

int main() {
    precalc();
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    vec<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        a[i] = x - 1;
        b[i] = MAX - x;
    }
    for (int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        c[i] = x - 1;
        d[i] = MAX - x;
    }
    vec<ll> e = solve(a, c), f = solve(b, d);
    for (int i = 0; i < q; ++i) {
        int x; scanf("%d", &x);
        printf("%lld\n", f[LIM - x] - (x < 3 ? 0 : e[x - 3]));
    }
}