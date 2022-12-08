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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    VVI es(n);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    VB has_team(n, false);
    for(int i : read_vi(k * 2)) {
        has_team[i - 1] = true;
    }

    VI size(n), my(n);
    const function<void(int, int)> dfs = [&](int x, int fa) {
        size[x] = has_team[x];
        my[x] = -1;
        for(int y : es[x]) {
            if(y != fa) {
                dfs(y, x);
                size[x] += size[y];
                if(my[x] < 0 || size[y] > size[my[x]]) {
                    my[x] = y;
                }
            }
        }
    };
    dfs(0, -1);
    int root = 0;
    while(my[root] >= 0 && size[my[root]] > k) {
        root = my[root];
    }

    printf("1\n%d\n", root + 1);
    VVI xs(n);
    const function<void(int, int, VI*)> extract = [&](int x, int fa, VI* res) {
        if(has_team[x]) res->pb(x);
        for(int y : es[x]) {
            if(y != fa) extract(y, x, res);
        }
    };
    if(has_team[root]) xs[root].pb(root);
    for(int x : es[root]) extract(x, root, &xs[x]);
    multiset<PII> m;
    repn(x, n) m.insert(mp(sz(xs[x]), x));
    while(m.rbegin()->fi > 0) {
        int i = (--m.end())->se;
        m.erase(--m.end());
        int j = (--m.end())->se;
        m.erase(--m.end());
        printf("%d %d %d\n", xs[i].back() + 1, xs[j].back() + 1, root + 1);
        xs[i].pop_back();
        xs[j].pop_back();
        m.insert(mp(sz(xs[i]), i));
        m.insert(mp(sz(xs[j]), j));
    }
    return 0;
}