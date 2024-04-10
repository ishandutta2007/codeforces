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

int solve(VPI a, int m) {
    const int n = sz(a);
    sort(all(a));
    VI mx(n);
    repn(i, n) {
        mx[i] = a[i].se;
        if(i > 0) setmax(mx[i], mx[i - 1]);
    }
    int j = 0;
    int ans = -1;
    replr(i, 1, n) {
        while(j + 1 < i && a[j + 1].fi + a[i].fi <= m) ++j;
        while(j >= 0 && a[j].fi + a[i].fi > m) --j;
        if(j < 0) break;
        setmax(ans, mx[j] + a[i].se);
    }
    return ans;
}

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    VPI as, bs;
    repn(i, n) {
        int v, p;
        char s[9];
        scanf("%d%d%s", &v, &p, s);
        if(s[0] == 'C') {
            as.pb(mp(p, v));
        } else {
            bs.pb(mp(p, v));
        }
    }

    int ans = 0;
    setmax(ans, solve(as, a));
    setmax(ans, solve(bs, b));
    int ma = -1, mb = -1;
    for(const auto& x : as) {
        if(x.fi <= a) setmax(ma, x.se);
    }
    for(const auto& x : bs) {
        if(x.fi <= b) setmax(mb, x.se);
    }
    if(ma >= 0 && mb >= 0) setmax(ans, ma + mb);

    printf("%d\n", ans);
    return 0;
}