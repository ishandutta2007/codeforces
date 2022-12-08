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
#ifndef H_ALGO_HEADER
#define H_ALGO_HEADER

#define all(a) (a).begin(), (a).end()
template <class T> int len(const T& a) { return static_cast<int>(a.size()); }
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
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, len(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
int read_int() { int x; scanf("%d", &x); return x; }
LL read_ll() { LL x; scanf("%lld", &x); return x; }
string read_string() { string s; cin >> s; return s; }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
#define IN read_int()

template <class T> T sorted(T x) { sort(x.begin(), x.end()); return x; }
template <class T> T reversed(T x) { reverse(x.begin(), x.end()); return x; }

template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }

#endif
// clang-format on
// }}}

struct Pairs {
    const int n;
    VVI tr;

    void build(int x, int l, int r, VPI ps) {
        for (const auto& p : ps) {
            assert(l <= p.fi && p.fi < r);
            tr[x].pb(p.se);
        }
        sort(all(tr[x]));
        if (l + 1 == r) return;
        const int m = (l + r) / 2;
        auto it = partition(all(ps), [m](const PII& p) { return p.fi < m; });
        build(x * 2 + 1, l, m, VPI(ps.begin(), it));
        build(x * 2 + 2, m, r, VPI(it, ps.end()));
    }

    Pairs(int n, VPI ps) : n(n), tr(n * 4) {
        for (auto& p : ps)
            if (p.fi > p.se) swap(p.fi, p.se);
        build(0, 0, n, ps);
    }

    bool find(int x, int l, int r, int st, int en, int st2, int en2) {
        if (st <= l && r <= en) {
            auto it = lower_bound(all(tr[x]), st2);
            if (it != tr[x].end() && *it < en2) return true;
            return false;
        }
        const int m = (l + r) / 2;
        if (st < m && find(x * 2 + 1, l, m, st, en, st2, en2)) return true;
        if (m < en && find(x * 2 + 2, m, r, st, en, st2, en2)) return true;
        return false;
    }

    bool find(int l1, int r1, int l2, int r2) {
        if (l1 > l2) swap(l1, l2), swap(r1, r2);
        return find(0, 0, n, l1, r1, l2, r2);
    }
};

const int N = 200000;
const int LOG = 22;

int up[N][LOG], dep[N], st[N], en[N], jump[N][LOG];
VI es[N];
int n;

void init() {
    fillchar(up, -1);
    int cur = 0;
    const function<void(int, int, int)> dfs = [&](int x, int fa, int d) {
        st[x] = cur++;
        dep[x] = d, up[x][0] = fa;
        for (int i = 0; up[x][i] >= 0; ++i) {
            up[x][i + 1] = up[up[x][i]][i];
        }
        for (int y : es[x]) {
            if (y != fa) dfs(y, x, d + 1);
        }
        en[x] = cur;
    };
    dfs(0, -1, 0);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    repn(i, LOG) {
        if ((dep[x] - dep[y]) & (1 << i)) x = up[x][i];
    }
    irepn(i, LOG) {
        if (up[x][i] != up[y][i]) {
            x = up[x][i], y = up[y][i];
        }
    }
    if (x != y) x = up[x][0];
    return x;
}

void init_jump() {
    const function<void(int, int)> dfs = [&](int x, int fa) {
        for (int y : es[x]) {
            if (y != fa) {
                dfs(y, x);
                if (dep[jump[y][0]] < dep[jump[x][0]]) jump[x][0] = jump[y][0];
            }
        }
    };
    dfs(0, -1);
    const function<void(int, int)> dfs2 = [&](int x, int fa) {
        repn(i, LOG - 1) jump[x][i + 1] = jump[jump[x][i]][i];
        for (int y : es[x]) {
            if (y != fa) {
                dfs2(y, x);
            }
        }
    };
    dfs2(0, -1);
}

int main() {
    n = IN;
    rep(i, 1, n - 1) {
        const int j = IN - 1;
        es[i].pb(j), es[j].pb(i);
    }
    init();

    repn(x, n) repn(i, LOG) jump[x][i] = x;
    VPI ps;
    for (const auto& route : read_vpi()) {
        const int x = route.fi - 1, y = route.se - 1, z = lca(x, y);
        if (dep[z] < dep[jump[x][0]]) jump[x][0] = z;
        if (dep[z] < dep[jump[y][0]]) jump[y][0] = z;
        ps.pb(mp(st[x], st[y]));
    }
    Pairs pairs(n, ps);
    init_jump();

    for (const auto& q : read_vpi()) {
        int x = q.fi - 1, y = q.se - 1, z = lca(x, y);
        if (dep[jump[x][LOG - 1]] > dep[z] || dep[jump[y][LOG - 1]] > dep[z]) {
            printf("-1\n");
            continue;
        }
        int ans = 0;
        irepn(i, LOG) {
            if (dep[jump[x][i]] > dep[z]) x = jump[x][i], ans += 1 << i;
        }
        irepn(i, LOG) {
            if (dep[jump[y][i]] > dep[z]) y = jump[y][i], ans += 1 << i;
        }
        assert(dep[jump[x][0]] <= dep[z]);
        assert(dep[jump[y][0]] <= dep[z]);
        if (x != y) {
            if (x == z || y == z || pairs.find(st[x], en[x], st[y], en[y])) {
                ans += 1;
            } else {
                ans += 2;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}