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

const LL MOD = LL(1e9) + 7;
LL pow2[1101000], pow10[11];
void init() {
    pow2[0] = 1;
    rep(i, 1, 1100000) pow2[i] = pow2[i - 1] * 2 % MOD;
    pow10[0] = 1;
    rep(i, 1, 10) pow10[i] = pow10[i - 1] * 10;
}

int main() {
    init();
    const int N = 1000000, K = 6;

    VL c(N), s(N), t(N);
    int n;
    scanf("%d", &n);
    repn(i, n) {
        int x;
        scanf("%d", &x);
        c[x]++;
        (s[x] += x) %= MOD;
        (t[x] += x * LL(x)) %= MOD;
    }
    repn(i, K) {
        irepn(x, N) if(x / pow10[i] % 10 < 9) {
            (c[x] += c[x + pow10[i]]) %= MOD;
            (s[x] += s[x + pow10[i]]) %= MOD;
            (t[x] += t[x + pow10[i]]) %= MOD;
        }
    }

    VL g(N);
    repn(x, N) {
        if(c[x] >= 1) {
            (g[x] += t[x] * pow2[c[x] - 1]) %= MOD;
        }
        if(c[x] >= 2) {
            (g[x] += (s[x] * s[x] % MOD - t[x]) * pow2[c[x] - 2]) %= MOD;
        }
    }
    repn(i, K) {
        repn(x, N) if(x / pow10[i] % 10 < 9) {
            (g[x] -= g[x + pow10[i]]) %= MOD;
        }
    }
    LL ans = 0;
    repn(x, N) {
        g[x] = (g[x] % MOD + MOD) % MOD;
        ans ^= x * g[x];
    }
    cout << ans << endl;

    return 0;
}