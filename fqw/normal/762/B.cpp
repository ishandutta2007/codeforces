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

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int m;
    scanf("%d", &m);
    VI xs, ys;
    repn(i, m) {
        int val;
        char t[9];
        scanf("%d%s", &val, t);
        if(t[0] == 'U')
            xs.pb(val);
        else
            ys.pb(val);
    }
    sort(all(xs), greater<int>()), sort(all(ys), greater<int>());
    LL ansc = 0, ansv = 0;
    while(a > 0 && !xs.empty()) {
        ansc++, ansv += xs.back();
        --a, xs.pop_back();
    }
    while(b > 0 && !ys.empty()) {
        ansc++, ansv += ys.back();
        --b, ys.pop_back();
    }
    while(c > 0 && (!xs.empty() || !ys.empty())) {
        if(ys.empty() || (!xs.empty() && xs.back() < ys.back())) {
            ansc++, ansv += xs.back();
            xs.pop_back();
        } else {
            ansc++, ansv += ys.back();
            ys.pop_back();
        }
        --c;
    }
    printf("%lld %lld\n", ansc, ansv);

    return 0;
}