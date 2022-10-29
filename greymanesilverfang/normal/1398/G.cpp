#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>
#define vec std::vector
#define cp std::complex<double>
const int MAX = 5e5;
vec<int> dv[MAX+1];

void precalc(int l, int r) {
    for (int i = l; i <= r; ++i)
        for (int j = i; j <= MAX; j += i)
            dv[j].push_back(i);
}

vec<cp> fft(const vec<cp>& x) {
    vec<cp> res(x.size());
    for (int i = 0; i < x.size(); ++i) {
        int tmp = i, id = 0;
        for (int i = 1; i < x.size(); i *= 2) {
            id = id * 2 + tmp % 2;
            tmp /= 2;
        }
        res[id] = x[i];
    }
    const double PI = acos(-1);
    for (int i = 1; i < res.size(); i *= 2)
        for (int j = 0; j < res.size(); j += i * 2) {
            double n = 0;
            for (int k = j; k < j + i; ++k) {
                res[k + i] = res[k] - res[k + i] * cp(cos(n), sin(n));
                res[k] = res[k] * 2.0 - res[k + i];
                n += PI / i;
            }
        }
    return res;
}

vec<cp> fftInv(const vec<cp>& x) {
    vec<cp> res = x;
    std::reverse(res.begin() + 1, res.end());
    res = fft(res);
    for (int i = 0; i < x.size(); ++i)
        res[i] /= res.size();
    return res;
}

vec<int> mul(const vec<int>& a, const vec<int>& b) {
    if (a.empty() || b.empty())
        return vec<int>();
    int len = a.size() + b.size() - 1;
    vec<int> res(len);
    len = 1 << 32 - __builtin_clz(len - 1);
    vec<cp> x(len), y(len), z(len);
    for (int i = 0; i < a.size(); ++i)
        x[i] = a[i];
    x = fft(x);
    for (int i = 0; i < b.size(); ++i)
        y[i] = b[i];
    y = fft(y);
    for (int i = 0; i < z.size(); ++i)
        z[i] = x[i] * y[i];
    z = fftInv(z);
    for (int i = 0; i < res.size(); ++i)
        res[i] = (int)round(z[i].real());
    return res;
}

int main() {
    int n, x, y; scanf("%d%d%d", &n, &x, &y);
    precalc(y + 1, x + y);
    vec<int> a(x + 1), b(x + 1);
    for (int i = 0; i <= n; ++i) {
        int z; scanf("%d", &z);
        ++a[z], ++b[x - z];
    }
    vec<int> diff = mul(a, b);
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        int l; scanf("%d", &l);
        int res = -1;
        for (int d : dv[l / 2])
            if (diff[d - y + x] != 0)
                res = d * 2;
        printf("%d ", res);
    }
    printf("\n");
}