#include <algorithm>
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
LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a*a%m) { if(b & 1) r = r*a%m; } return r; }
// clang-format on
// }}}

const int MOD = 998244353;
const int GN = MOD - 1;
const int G = 3;

void fft(int* a, int n, bool is_inv) {
    static VI b;
    if(sz(b) < n) b.resize(n);

    for(int t = n / 2; t >= 1; t /= 2) {
        LL w = powmod(G, GN / n * t, MOD), p = 1;
        if(is_inv) w = powmod(w, MOD - 2, MOD);
        for(int j = 0; j < n / 2; j += t, (p *= w) %= MOD)
            for(int i = 0; i < t; ++i) {
                LL u = a[i + j * 2];
                LL v = p * a[i + t + j * 2] % MOD;
                b[i + j] = int(u + v) % MOD;
                b[i + j + n / 2] = int(u + MOD - v) % MOD;
            }
        memcpy(a, &b[0], sizeof(int) * n);
    }
    if(is_inv) {
        LL inv = powmod(n, MOD - 2, MOD);
        repn(i, n) a[i] = int(a[i] * inv % MOD);
    }
}

struct Poly {
    vector<int> a;
    Poly operator*(const Poly& b) const {
        assert(sz(a) == sz(b.a));
        Poly r;
        r.a.resize(sz(a));
        repn(i, sz(a)) r.a[i] = ((LL)a[i] * b.a[i]) % MOD;
        return r;
    }
    void operator+=(const Poly& b) {
        if(sz(a) < sz(b.a)) a.resize(sz(b.a));
        repn(i, sz(b.a))(a[i] += b.a[i]) %= MOD;
    }
};

struct Mat {
    Poly a[2][2];
    Mat operator*(const Mat& b) const {
        Mat r;
        repn(i, 2) repn(j, 2) repn(k, 2) { r.a[i][j] += a[i][k] * b.a[k][j]; }
        r.transform(true);
        repn(i, 2) repn(j, 2) {
            fill(r.a[i][j].a.begin() + sz(r.a[i][j].a) / 2, r.a[i][j].a.end(),
                 0);
        }
        r.transform(false);
        return r;
    }
    void transform(bool is_inv) {
        repn(i, 2) repn(j, 2) fft(&a[i][j].a[0], sz(a[i][j].a), is_inv);
    }
};

int main() {

    /*
    VI a = {1, 1, 1, 0, 0, 0, 0, 0};
    fft(&a[0], 4, false);
    cout << a << endl;
    repn(i, sz(a)) a[i] = LL(a[i]) * a[i] % MOD;
    fft(&a[0], 4, true);
    cout << a << endl;
    */

    int n, k;
    cin >> n >> k;

    int len = 2;
    while(len < k * 2) len *= 2;
    Mat m;
    repn(i, 2) repn(j, 2) m.a[i][j].a.resize(len);
    m.a[0][0].a[0] = m.a[0][0].a[1] = 1;
    m.a[0][1].a[1] = 1;
    m.a[1][0].a[0] = 1;
    Mat r;
    repn(i, 2) repn(j, 2) r.a[i][j].a.resize(len);
    r.a[0][0].a[0] = 1;
    r.a[1][1].a[0] = 1;
    m.transform(false);
    r.transform(false);
    for(; n > 0; n >>= 1, m = m * m) {
        if(n & 1) r = r * m;
    }
    r.transform(true);

    rep(i, 1, k) {
        LL cur = 0;
        cur += r.a[1][0].a[i] + r.a[1][0].a[i - 1];
        cur += r.a[1][1].a[i];
        printf("%d ", int(cur % MOD));
    }
    printf("\n");

    return 0;
}