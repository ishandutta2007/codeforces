#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// {{{
// clang-format off
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define popcount __builtin_popcount
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

typedef complex<double> Complex;
struct F {
    typedef complex<double> value_t;
    static value_t root_of_unity(int n, bool is_inv = false) {
        static constexpr double PI = 3.14159265358979323846264;
        const double ang = PI * 2.0 / n;
        return value_t(cos(ang), is_inv ? sin(ang) : -sin(ang));
    }
    static value_t add(const value_t& a, const value_t& b) { return a + b; }
    static value_t sub(const value_t& a, const value_t& b) { return a - b; }
    static value_t mul(const value_t& a, const value_t& b) { return a * b; }
    static value_t div(const value_t& a, const value_t& b) { return a / b; }
};
template <class Field, class RandomIt>
void fft(RandomIt a, RandomIt a_end, bool is_inv = false) {
    typedef typename Field::value_t value_t;
    const int n = int(a_end - a);
    static vector<value_t> b;
    if(sz(b) < n) b.resize(n);

    for(int t = n / 2; t >= 1; t /= 2) {
        value_t w = Field::root_of_unity(n / t, is_inv);
        value_t p = 1;
        for(int j = 0; j < n / 2; j += t, p = Field::mul(p, w)) {
            for(int i = 0; i < t; ++i) {
                value_t u = a[i + j * 2];
                value_t v = Field::mul(p, a[i + t + j * 2]);
                b[i + j] = Field::add(u, v);
                b[i + j + n / 2] = Field::sub(u, v);
            }
        }
        copy(b.begin(), b.begin() + n, a);
    }
    if(is_inv) {
        repn(i, n) a[i] = Field::div(a[i], n);
    }
}

class OnlineConvolution {
public:
    template <class Iter>
    OnlineConvolution(Iter a, Iter a_end)
        : n(int(a_end - a)), prep(n), r(n * 2) {
        assert((n & (n - 1)) == 0);
        for(int i = 0, j = 1; i < n; i = j, j <<= 1) {
            prep[i].resize((j - i) * 2);
            copy(a + i, a + j, prep[i].begin());
            if(sz(prep[i]) > S) fft<F>(all(prep[i]));
        }
    }

    double add(double bi) {
        b.pb(bi);
        while(sz(r) < sz(b) + n) r.resize(sz(r) * 2);
        for(int i = 0, j = 1; i < n; i = j, j <<= 1) {
            const int len = j - i;
            if(len > sz(b)) break;
            if(sz(b) % len == 0) {
                convolute(i, b.end() - len, b.end(),
                          r.begin() + i + sz(b) - len);
            }
        }
        return r[sz(b) - 1];
    }

private:
    template <class Iter, class OutIter>
    void convolute(int i, Iter arr, Iter arr_end, OutIter out) {
        const int len = int(arr_end - arr);
        if(sz(prep[i]) > S) {
            vector<F::value_t> tmp(sz(prep[i]));
            copy(arr, arr_end, tmp.begin());
            fft<F>(all(tmp));
            repn(k, sz(tmp)) tmp[k] *= prep[i][k];
            fft<F>(all(tmp), true);
            repn(k, sz(tmp)) out[k] += real(tmp[k]);
        } else {
            repn(k, len) repn(j, sz(prep[i]) - k) {
                out[j + k] += real(prep[i][j]) * arr[k];
            }
        }
    }

    static constexpr int S = 128;
    const int n;
    vector<vector<F::value_t>> prep;
    vector<double> b, r;
};

int main() {
    int n, m, t, fine;
    scanf("%d%d%d%d", &n, &m, &t, &fine);
    int len = 1;
    while(t > len) len *= 2;

    VI a(m), b(m), c(m);
    vector<VD> p(m), s(m);
    vector<VD> g(n, VD(n, 1e50));
    repn(i, m) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        --a[i], --b[i];
        p[i].resize(len);
        repn(j, t) {
            scanf("%lf", &p[i][j]);
            p[i][j] /= 100000;
        }
        s[i].resize(len + 1);
        irepn(j, len) s[i][j] = s[i][j + 1] + p[i][j];
        setmin(g[a[i]][b[i]], (double)c[i]);
    }
    repn(i, n) g[i][i] = 0;
    repn(k, n) repn(i, n) repn(j, n) setmin(g[i][j], g[i][k] + g[k][j]);

    vector<OnlineConvolution*> oc(m);
    repn(i, m) oc[i] = new OnlineConvolution(all(p[i]));
    vector<VD> f(n, VD(t + 1));
    repn(x, n) rep(cur, 0, t) f[x][cur] = (x == n - 1 ? 0 : fine + g[x][n - 1]);
    rep(cur, 1, t) {
        repn(i, m) {
            double v = oc[i]->add(f[b[i]][cur - 1]);
            v += s[i][cur] * (g[b[i]][n - 1] + fine);
            setmin(f[a[i]][cur], v + c[i]);
        }
    }
    printf("%.9lf\n", f[0][t]);
    return 0;
}