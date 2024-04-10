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
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v);
template <class T> ostream& operator<<(ostream& os, const vector<T>& v);
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

void finalize(VVI es) {
    const int n = sz(es);
    VI ans(n, -1), size(n), ms(n), xs;
    const function<void(int, int)> dfs = [&](int x, int fa) {
        size[x] = 1, ms[x] = 0;
        xs.pb(x);
        for(int y : es[x]) {
            if(ans[y] < 0 && y != fa) {
                dfs(y, x);
                size[x] += size[y];
                setmax(ms[x], size[y]);
            }
        }
    };
    const function<void(int, int)> go = [&](int seed, int dep) {
        xs.clear();
        dfs(seed, -1);
        int mx = seed, r = 1 << 30;
        for(int x : xs) {
            int tmp = max(ms[x], size[seed] - size[x]);
            if(setmin(r, tmp)) mx = x;
        }
        ans[mx] = dep;
        for(int y : es[mx]) {
            if(ans[y] < 0) go(y, dep + 1);
        }
    };
    go(0, 1);
    repn(i, n) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    VVI ds(n);
    repn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        if(a > b) swap(a, b);
        ds[a].pb(b);
    }
    repn(i, n) sort(all(ds[i]));

    vector<pair<VI, VI>> regions;
    const function<void(int, int)> extract = [&](int l, int r) {
        VI cur;
        VPI todos;
        while(l < r) {
            cur.pb(l);
            if(ds[l].empty()) {
                ++l;
            } else {
                int p = ds[l].back();
                todos.pb({l, p});
                ds[l].pop_back();
                l = p;
            }
        }
        cur.pb(r);
        VI key = cur;
        sort(all(key), greater<int>());
        regions.pb({key, cur});
        for(const auto& p : todos) {
            extract(p.fi, p.se);
        }
    };
    extract(0, n - 1);
    const int num = sz(regions);
    sort(all(regions));

    VVI es(num);
    map<PII, int> used;
    repn(i, num) {
        repn(k, sz(regions[i].se)) {
            int a = regions[i].se[k],
                b = regions[i].se[(k + 1) % sz(regions[i].se)];
            if(a > b) swap(a, b);
            if(used.count({a, b})) {
                int j = used[mp(a, b)];
                es[i].pb(j), es[j].pb(i);
            } else {
                used[mp(a, b)] = i;
            }
        }
    }

    finalize(es);

    return 0;
}