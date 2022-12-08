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
    VPI a;
    int n, m;
    scanf("%d%d", &n, &m);
    repn(i, n) {
        int x;
        scanf("%d", &x);
        a.pb(mp(x, -1));
    }
    repn(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.pb(mp(x, y));
    }
    sort(all(a));

    constexpr int D = 5000;
    static LL f[2][D * 2 + 1];
    int o1 = 0, o2 = 1;
    fillchar(f[o1], 50), f[o1][D] = 0;
    const LL inf = f[o1][0];
    repn(i, sz(a)) {
        const LL dis = (i == 0 ? 0 : a[i].fi - a[i - 1].fi);
        const int c = a[i].se;
        if(c < 0) {
            f[o2][0] = inf;
            rep(d, -D, D - 1) {
                f[o2][D + d + 1] = min(f[o1][D + d] + dis * abs(d), inf);
            }
        } else {
            static PLL s[D * 2 + 2];
            int l = 0, r = 0;
            irep(d, D, -D) {
                if(l < r && s[l].se > d) l++;
                LL cur = f[o1][D + d] + dis * abs(d);
                while(l < r && s[r - 1].fi >= cur) r--;
                s[r++] = mp(cur, d - c);
                f[o2][D + d] = min(s[l].fi, inf);
            }
        }
        swap(o1, o2);
    }
    LL ans = f[o1][D];
    if(ans >= inf) ans = -1;
    printf("%lld\n", ans);
    return 0;
}