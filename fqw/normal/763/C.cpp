#include <algorithm>
#include <cassert>
#include <cmath>
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
// clang-format on
// }}}

LL mod;

LL inv(LL x) {
    LL y = mod - 2, r = 1;
    for(; y >= 1; y >>= 1, x = x * x % mod) {
        if(y & 1) r = r * x % mod;
    }
    return r;
}

int main() {
    int n;
    scanf("%lld%d", &mod, &n);
    VL a(n);
    repn(i, n) scanf("%lld", &a[i]);
    if(n == mod) {
        printf("1 1\n");
        return 0;
    }
    LL s = 0, t = 0;
    for(LL x : a) {
        (s += x) %= mod;
        (t += x * x) %= mod;
    }
    LL u = 0, v = 0;
    for(LL i = 0; i < n; ++i) {
        (u += i * i) %= mod;
        (v += 2 * i) %= mod;
    }
    sort(all(a));

    for(LL x : a) {
        LL d = (s - n * x) % mod * inv(n * LL(n - 1) / 2 % mod) % mod;
        if(d < 0) d += mod;
        if((u * d % mod * d + v * d % mod * x + x * x % mod * n) % mod != t)
            continue;
        VL b;
        LL cur = x;
        repn(i, n) { b.pb(cur), cur = (cur + d) % mod; }
        sort(all(b));
        if(a == b) {
            printf("%lld %lld\n", x, d);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}