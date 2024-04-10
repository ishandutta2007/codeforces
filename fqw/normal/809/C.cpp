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

const LL MOD = LL(1e9) + 7;
const int N = 22;

int board[N][N];

// (cnt, sum)
PLL cal(int n, int m, int k) {
    VI a, b, c;
    repn(i, 30) {
        a.pb((n & (1 << i)) > 0);
        b.pb((m & (1 << i)) > 0);
        c.pb((k & (1 << i)) > 0);
    }
    while(sz(a) > 0 && a.back() == 0 && b.back() == 0 && c.back() == 0) {
        a.pop_back();
        b.pop_back();
        c.pop_back();
    }
    const auto add = [](PLL& x, PLL y, LL add) {
        (x.fi += y.fi) %= MOD;
        (x.se += y.se + y.fi * add) %= MOD;
    };
    static PLL f[33][2][2][2];
    fillchar(f, 0);
    f[sz(a)][0][0][0] = {1, 0};
    irepn(i, sz(a)) repn(ba, 2) repn(bb, 2) repn(bc, 2) {
        if(f[i + 1][ba][bb][bc] == mp(0ll, 0ll)) continue;
        int la = (ba ? 1 : a[i]);
        int lb = (bb ? 1 : b[i]);
        int lc = (bc ? 1 : c[i]);
        rep(x, 0, la) rep(y, 0, lb) if((x ^ y) <= lc) {
            add(f[i][ba || (x < la)][bb || (y < lb)][bc || ((x ^ y) < lc)],
                f[i + 1][ba][bb][bc], (x ^ y) << i);
        }
    }
    PLL ans = {0, 0};
    repn(ba, 2) repn(bb, 2) repn(bc, 2) add(ans, f[0][ba][bb][bc], 0);
    // printf("cal %d %d %d = %lld,%lld\n", n, m, k, ans.fi, ans.se);
    return ans;
}

LL solve(int n, int m, int k) {
    LL ans = 0;
    map<pair<PII, int>, PLL> cache;
    repn(x0, 8) repn(y0, 8) {
        const int d = board[x0][y0];
        if(k < d || n < x0 || m < y0) continue;
        auto index = mp(mp((n - x0) / 8, (m - y0) / 8), (k - d) / 8);
        PLL r;
        if(cache.count(index)) {
            r = cache[index];
        } else {
            r = cache[index] = cal((n - x0) / 8, (m - y0) / 8, (k - d) / 8);
        }
        (ans += 8 * r.se + r.fi * d) %= MOD;
    }
    return ans;
}

LL vio(int x1, int y1, int x2, int y2, int k) {
    LL ans = 0;
    rep(x, x1, x2) rep(y, y1, y2) if(board[x][y] <= k)(ans += board[x][y]) %=
        MOD;
    return ans;
}

int main() {
    repn(i, N) repn(j, N) {
        unordered_set<int> used;
        repn(k, i) used.insert(board[k][j]);
        repn(k, j) used.insert(board[i][k]);
        int cur = 1;
        while(used.count(cur)) ++cur;
        board[i][j] = cur;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int x1, y1, x2, y2, k;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        --x1, --y1, --x2, --y2;
        LL ans = 0;
        ans = solve(x2, y2, k) - solve(x1 - 1, y2, k) - solve(x2, y1 - 1, k) +
              solve(x1 - 1, y1 - 1, k);
        ans = (ans % MOD + MOD) % MOD;
        printf("%d\n", int(ans));
        // printf("%d\n", int(vio(x1, y1, x2, y2, k)));
    }
    return 0;
}