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

struct Tree {
    const int n;
    VI tr;

    Tree(int _n) : n(_n), tr(n + 1, 1 << 30) {}

    void update(int i, int val) {
        for(; i <= n; i += i & -i) setmin(tr[i], val);
    }

    int get(int i) {
        int r = 1 << 30;
        for(; i >= 1; i -= i & -i) setmin(r, tr[i]);
        return r;
    }
};

int main() {
    int d, init, n;
    scanf("%d%d%d", &d, &init, &n);
    VPI a(n);
    repn(i, n) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(all(a));
    a.pb(mp(d, 0));

    VI next(n);
    Tree tr(1000000);
    tr.update(1, n);
    irepn(i, n) {
        next[i] = tr.get(a[i].se);
        tr.update(a[i].se, i);
    }

    LL ans = 0, left = init, pos = 0;
    rep(i, 0, n) {
        left -= a[i].fi - pos, pos = a[i].fi;
        if(left < 0) {
            ans = -1;
            break;
        }
        if(i == n) {
            break;
        }
        LL stop = a[next[i]].fi;
        LL need = min(stop - a[i].fi, LL(init));
        if(need > left) {
            ans += a[i].se * (need - left);
            left = need;
        }
    }
    printf("%lld\n", ans);

    return 0;
}