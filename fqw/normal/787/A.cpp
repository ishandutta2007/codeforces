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

// Finds x and y: a x + b y = gcd(a, b).  Returns gcd(a, b).
//
// Must: |a| + |b| > 0.
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

LL solve() {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b == d) return b;
    LL x, y, g = ext_gcd(a, c, &x, &y);
    // ax + cy = g
    if((d - b) % g != 0) return -1;
    LL t = (d - b) / g;
    x *= t, y *= t, y = -y;
    // ax - cy = d-b
    // ax + b = cy + d, but maybe not minimal
    LL dx = c / g, dy = a / g;
    const auto go = [&](LL d) { x += dx * d, y += dy * d; };
    if(x < 0) go((-x - 1) / dx + 1);
    if(y < 0) go((-y - 1) / dy + 1);
    go(-min(x / dx, y / dy));
    return a * x + b;
}

int main() {
    cout << solve() << endl;
    return 0;
}