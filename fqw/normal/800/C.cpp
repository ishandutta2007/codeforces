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

int m;

LL ext_gcd(LL a, LL b, LL* x, LL* y) {
    if(b == 0) {
        *x = 1, *y = 0;
        return a;
    }
    LL nx, ny;
    LL d = ext_gcd(b, a % b, &nx, &ny);
    *x = ny, *y = nx - (a / b) * ny;
    return d;
}

LL divide(LL x, LL y) {
    //printf("div %lld %lld\n", x, y);
    LL p, q, g = ext_gcd(y, m, &p, &q);
    p = (p % m + m) % m;
    assert(x % g == 0);
    p = p * (x / g) % m;
    assert(y * p % m == x % m);
    return p;
}

int main() {
    int n;
    scanf("%d%d", &n, &m);
    vector<bool> ok(m + 1, true);
    repn(i, n) {
        int x;
        scanf("%d", &x);
        if(x == 0) x = m;
        ok[x] = false;
    }

    vector<int> factors;
    vector<VL> ints(m + 1);
    {
        int x = m;
        for(int y = 1; y * y <= x; ++y) {
            if(x % y == 0) {
                factors.pb(y);
                if(y * y < x) factors.pb(x / y);
            }
        }
        sort(all(factors));
        rep(i, 1, m) if(ok[i]) ints[gcd(i, m)].pb(i);
    }
    vector<int> f(sz(factors)), pre(sz(factors));
    repn(i, sz(factors)) {
        f[i] = 0, pre[i] = -1;
        repn(j, i) if(factors[i] % factors[j] == 0) {
            if(setmax(f[i], f[j])) pre[i] = j;
        }
        f[i] += sz(ints[factors[i]]);
    }
    VL seq;
    for(int i = sz(factors) - 1; i >= 0; i = pre[i]) {
        seq.insert(seq.end(), all(ints[factors[i]]));
    }
    reverse(all(seq));
    //cout << seq << endl;
    VL ans;
    LL cur = 1;
    for(LL x : seq) {
        LL tmp = divide(x, cur);
        assert(tmp * cur % m == x % m);
        ans.pb(tmp);
        cur = x;
    }
    printf("%d\n", sz(ans));
    for(LL x : ans) printf("%d ", int(x));
    printf("\n");

    return 0;
}