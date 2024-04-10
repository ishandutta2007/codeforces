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

struct State {
    int l[10], r[10], lc[10], rc[10];
    int inner, cnt, h;

    void init(VI a) {
        h = sz(a);
        int cur = 0;
        repn(i, h) {
            lc[i] = rc[i] = a[i];
            if(i > 0 && a[i] != a[i - 1]) ++cur;
            l[i] = r[i] = cur;
        }
        cnt = cur + 1;
        inner = 0;
    }

    int count() { return inner + cnt; }

    void cat_from(State a, State b) {
        h = a.h;
        repn(i, h) lc[i] = a.lc[i], rc[i] = b.rc[i];
        inner = a.inner + b.inner;
        repn(i, h) b.l[i] += a.cnt, b.r[i] += a.cnt;
        VI map(a.cnt + b.cnt, -1);
        const function<int(int)> get = [&](int i) {
            return map[i] < 0 ? i : map[i] = get(map[i]);
        };
        repn(i, h) if(a.rc[i] == b.lc[i]) {
            int u = get(a.r[i]), v = get(b.l[i]);
            if(u != v) map[u] = v;
        }
        VB used(a.cnt + b.cnt, false);
        repn(i, h) used[get(a.l[i])] = true;
        repn(i, h) used[get(b.r[i])] = true;
        VI new_id(a.cnt + b.cnt);
        cnt = 0;
        repn(i, sz(map)) if(map[i] < 0) {
            if(used[i]) {
                new_id[i] = cnt++;
            } else {
                ++inner;
            }
        }
        repn(i, h) l[i] = new_id[get(a.l[i])];
        repn(i, h) r[i] = new_id[get(b.r[i])];
    }
};
State tr[400010];

void init(int x, int l, int r, const VVI& a) {
    if(l + 1 == r) {
        tr[x].init(a[l]);
        return;
    }
    const int m = (l + r) / 2;
    init(x * 2 + 1, l, m, a);
    init(x * 2 + 2, m, r, a);
    tr[x].cat_from(tr[x * 2 + 1], tr[x * 2 + 2]);
}

State get(int x, int l, int r, int st, int en) {
    if(st <= l && r <= en) {
        return tr[x];
    }
    const int m = (l + r) / 2;
#define L get(x * 2 + 1, l, m, st, en)
#define R get(x * 2 + 2, m, r, st, en)
    if(st < m && m < en) {
        State ans;
        ans.cat_from(L, R);
        return ans;
    } else if(st < m) {
        return L;
    } else {
        return R;
    }
}

int main() {
    int n, height, q;
    scanf("%d%d%d", &height, &n, &q);
    VVI a(n, VI(height));
    repn(j, height) repn(i, n) scanf("%d", &a[i][j]);
    init(0, 0, n, a);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r), --l;
        State s = get(0, 0, n, l, r);
        printf("%d\n", s.count());
    }
    return 0;
}