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

bool operator<(PLL a, PLL b) {
    LL t = a.fi * b.se - b.fi * a.se;
    return t < 0;
}

int main() {
    int n;
    scanf("%d", &n);
    LL x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);

    PLL l = mp(0, 1), r = mp(1 << 30, 1);
    repn(i, n) {
        LL x, y, vx, vy;
        scanf("%lld%lld%lld%lld", &x, &y, &vx, &vy);
        repn(_, 2) {
            swap(x1, y1), swap(x2, y2), swap(x, y), swap(vx, vy);
            if(vx > 0) {
                setmax(l, mp(x1 - x, vx));
                setmin(r, mp(x2 - x, vx));
            } else if(vx < 0) {
                setmax(l, mp(x - x2, -vx));
                setmin(r, mp(x - x1, -vx));
            } else {
                if(x <= x1 || x >= x2) {
                    r = mp(-1, 1);
                }
            }
        }
    }
    if(l < r) {
        printf("%.15lf\n", double(l.fi) / double(l.se));
    } else {
        printf("-1\n");
    }
    return 0;
}