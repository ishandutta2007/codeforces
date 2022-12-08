// 13:35 - 14:07
//       - 14:46 - wa
//       - 14:56 - tle
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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<PDD> VPD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VPI> VVPI;
typedef vector<VPL> VVPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

LL calc_area(vector<pair<PII, PII>> ts, int nx, int ny, int delta,
             bool strict) {
    // cout << nx << " " << ny << " d=" << delta << " strict=" << strict << " "
    //<< ts << endl;
    if(nx == 0 || ny == 0) return 0;
    struct Node {
        int buf = 0, minv = 0;
        PLL minc;
    };
    vector<Node> tr(ny * 4);
    const auto add_pll = [&](PLL& a, PLL b) { a.fi += b.fi, a.se += b.se; };
    const auto update = [&](int x) {
        int l = x * 2 + 1, r = x * 2 + 2;
        if(tr[l].minv == tr[r].minv) {
            tr[x].minv = tr[l].minv;
            tr[x].minc.fi = tr[l].minc.fi + tr[r].minc.fi;
            tr[x].minc.se = tr[l].minc.se + tr[r].minc.se;
        } else {
            if(tr[l].minv < tr[r].minv) {
                tr[x].minv = tr[l].minv;
                tr[x].minc = tr[l].minc;
            } else {
                tr[x].minv = tr[r].minv;
                tr[x].minc = tr[r].minc;
            }
        }
    };
    const auto release = [&](int x) {
        if(tr[x].buf) {
            tr[x * 2 + 1].buf += tr[x].buf;
            tr[x * 2 + 1].minv += tr[x].buf;
            tr[x * 2 + 2].buf += tr[x].buf;
            tr[x * 2 + 2].minv += tr[x].buf;
            tr[x].buf = 0;
        }
    };
    const function<void(int, int, int)> init = [&](int x, int l, int r) {
        if(l + 1 == r) {
            tr[x].minc = mp(1, l);
            return;
        }
        const int m = (l + r) / 2;
        init(x * 2 + 1, l, m);
        init(x * 2 + 2, m, r);
        update(x);
    };
    const function<void(int, int, int, int, int, int)> add = [&](
        int x, int l, int r, int st, int en, int val) {
        if(st <= l && r <= en) {
            tr[x].buf += val;
            tr[x].minv += val;
            return;
        }
        release(x);
        const int m = (l + r) / 2;
        if(st < m) add(x * 2 + 1, l, m, st, en, val);
        if(m < en) add(x * 2 + 2, m, r, st, en, val);
        update(x);
    };
    const function<PLL(int, int, int, int, int)> count_eq0 = [&](
        int x, int l, int r, int st, int en) {
        if(st >= en) return mp(0ll, 0ll);
        if(st <= l && r <= en) {
            return tr[x].minv == 0 ? tr[x].minc : mp(0ll, 0ll);
        }
        release(x);
        const int m = (l + r) / 2;
        PLL ans = {0, 0};
        if(st < m) add_pll(ans, count_eq0(x * 2 + 1, l, m, st, en));
        if(m < en) add_pll(ans, count_eq0(x * 2 + 2, m, r, st, en));
        return ans;
    };

    init(0, 0, ny);
    vector<VPI> actions(nx + 1);
    repn(i, sz(ts)) {
        actions[ts[i].fi.fi].pb(mp(1, i));
        actions[ts[i].se.fi].pb(mp(-1, i));
    }
    LL ans = 0;
    repn(x, nx) {
        for(const auto& a : actions[x]) {
            add(0, 0, ny, ts[a.se].fi.se, ts[a.se].se.se, a.fi);
        }
        int y1 = x + strict, y2 = ny;
        PLL tmp = count_eq0(0, 0, ny, y1, y2);
        // cout << "x=" << x << " eq0=" << tmp << endl;
        ans += tmp.se * 2 + tmp.fi * (delta - 2 * x);
    }
    // cout << "   ans=" << ans << endl;
    // cout << "   vio=" << vio << endl;
    return ans;
}

LL calc(VPI ss, int m) {
    vector<pair<PII, PII>> t[2][2];
    const auto add = [&](int x1, int x2, int y1, int y2, int mx, int my,
                         int mxor) {
        repn(i, 2) repn(j, 2) {
            if((mx & (1 << i)) && (my & (1 << j)) && (mxor & (1 << (i ^ j)))) {
                int u1 = (x1 - i + 1) / 2, v1 = (y1 - j + 1) / 2;
                int u2 = (x2 - i + 1) / 2, v2 = (y2 - j + 1) / 2;
                if(u1 < u2 && v1 < v2) {
                    t[i][j].pb({{u1, v1}, {u2, v2}});
                }
            }
        }
    };
    for(const auto& s : ss) {
        int l = s.fi, r = s.se;
        add(0, l, l, r, 3, 1 << ((l + 1) % 2), 3);
        add(l, r, r, m, 1 << (r % 2), 3, 3);
        add(l, r, l, r, 3, 3, 2);
        if((r - l) % 2 == 0) {
            add(0, l, r, m, 3, 3, 3);
        }
    }
    LL ans = 0;
    repn(i, 2) repn(j, 2) {
        ans += calc_area(t[i][j], (m + 1 - i) / 2, (m + 1 - j) / 2, j - i + 1,
                         i > j);
    }
    return ans;
}

LL calc_empty(VPI ss, int m) {
    sort(all(ss));
    int last = 0;
    LL ans = 0;
    ss.pb(mp(m, m));
    for(const auto& s : ss) {
        if(s.fi > last) {
            LL len = s.fi - last;
            ans += (len + 1) * len * (len + 1) / 2 -
                   len * (len + 1) * (2 * len + 1) / 6;
        }
        setmax(last, s.se);
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    VPI ss = read_vpi(n);
    for(auto& s : ss) s.fi--;

    LL ans = calc(ss, m);
    // printf("%lld\n", ans);
    ans -= calc_empty(ss, m);
    printf("%lld\n", ans);
    return 0;
}