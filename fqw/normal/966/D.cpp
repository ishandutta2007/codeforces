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

VI bfs(const VVI& es, VI& pre, VI& dis, int start, bool ignore0 = false) {
    VI que = {start};
    pre[start] = -2, dis[start] = 0;
    for (int i = 0; i < len(que); ++i) {
        const int x = que[i];
        for (int y : es[x]) {
            if (ignore0 && y == 0) {
                continue;
            }
            if (pre[y] == -1) {
                pre[y] = x, dis[y] = dis[x] + 1, que.pb(y);
            }
        }
    }
    return que;
}

VI get_path(VI p, int x) {
    VI r;
    for (; x >= 0; x = p[x]) r.pb(x);
    return reversed(r);
}

bool has(const VVI& es, int x, int y) {
    auto it = lower_bound(all(es[x]), y);
    return (it != es[x].end() && *it == y);
}

VI solve(const VVI& es) {
    const int n = len(es);
    VI p(n, -1), d(n, -1);
    bfs(es, p, d, 0);
    if (p[n - 1] >= 0 && d[n - 1] <= 4) {
        return get_path(p, n - 1);
    }
    repn(x, n) if (p[x] >= 0) {
        if (!has(es, 0, x) && d[x] <= 2) {
            auto path = get_path(p, x);
            path.pb(0);
            path.pb(n - 1);
            assert(len(path) == 5);
            return path;
        }
    }
    assert(p[n - 1] < 0);
    VI q(n, -1);
    repn(x, n) if (p[x] >= 0 && q[x] == -1) {
        VI comp = bfs(es, q, d, x, true);
        int ex = -1, ey = -1;
        repn(i, len(comp)) {
            replr(j, i + 1, len(comp)) {
                if (!has(es, comp[i], comp[j])) {
                    ex = comp[i], ey = comp[j];
                    break;
                }
            }
            if (ex >= 0) break;
        }
        if (ex >= 0) {
            VI r(n, -1);
            bfs(es, r, d, ex, true);
            auto path = get_path(r, ey);
            path.insert(path.begin(), 0);
            path.pb(ex);
            path.pb(n - 1);
            return path;
        }
    }
    return {};
}

int main() {
    int n = IN;
    VVI es(n);
    for (int m = IN; m--;) {
        int a = IN - 1, b = IN - 1;
        es[a].pb(b), es[b].pb(a);
    }
    repn(x, n) sort(all(es[x]));
    VI ans = solve(es);
    if (ans.empty()) {
        printf("-1\n");
    } else {
        printf("%d\n", len(ans) - 1);
        for (int x : ans) printf("%d ", x + 1);
        printf("\n");
    }
    return 0;
}