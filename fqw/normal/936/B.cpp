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
#define len(a) static_cast<int>((a).size())
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
int read_int() { int x; scanf("%d", &x); return x; }
LL read_ll() { LL x; scanf("%lld", &x); return x; }
string read_string() { string s; cin >> s; return s; }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
#define IN read_int()

#endif
// clang-format on
// }}}

bool in_cycle(const VVI& es, int start) {
    const int n = len(es);
    VI dfn(n), low(n), vis(n);
    VB in(n, false);
    int cur = 0;
    const function<void(int)> dfs = [&](int x) {
        vis[x] = -1;
        low[x] = dfn[x] = cur++;
        for (int y : es[x]) {
            if (vis[y] == 0) {
                dfs(y);
                setmin(low[x], low[y]);
            } else if (vis[y] < 0) {
                setmin(low[x], dfn[y]);
            }
            if (in[y]) in[x] = true;
        }
        vis[x] = 1;
        if (low[x] < dfn[x]) in[x] = true;
    };
    dfs(start);
    return in[start];
}

int main() {
    const int n = IN;
    (void)IN;
    VVI es(n), res(n);
    repn(x, n) {
        for (int y0 : read_vi()) {
            const int y = y0 - 1;
            es[x].pb(y), res[y].pb(x);
        }
    }
    const int start = IN - 1;

    VVI pre(n, VI(2, -1));
    queue<PII> que;
    repn(x, n) {
        if (es[x].empty()) {
            pre[x][0] = -2;
            que.push(mp(x, 0));
        }
    }
    while (!que.empty()) {
        const int x = que.front().fi, s = que.front().se;
        que.pop();
        for (int y : res[x]) {
            if (pre[y][s ^ 1] == -1) {
                pre[y][s ^ 1] = x;
                que.push(mp(y, s ^ 1));
            }
        }
    }
    if (pre[start][1] >= 0) {
        printf("Win\n");
        for (int x = start, s = 1; x >= 0; x = pre[x][s], s ^= 1) {
            printf("%d ", x + 1);
        }
        printf("\n");
    } else {
        if (in_cycle(es, start)) {
            printf("Draw\n");
        } else {
            printf("Lose\n");
        }
    }

    return 0;
}