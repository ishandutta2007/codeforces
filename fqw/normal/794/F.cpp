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

struct Node {
    int buf[10];
    LL cnt[10];
};
Node tr[400040];

void update(int x) {
    repn(i, 10) tr[x].cnt[i] = tr[x * 2 + 1].cnt[i] + tr[x * 2 + 2].cnt[i];
}

void release(int x) {
    for(int y : {x * 2 + 1, x * 2 + 2}) {
        int tb[10];
        LL tc[10];
        fillchar(tc, 0);
        repn(i, 10) {
            tb[i] = tr[x].buf[tr[y].buf[i]];
            tc[tr[x].buf[i]] += tr[y].cnt[i];
        }
        memmove(tr[y].buf, tb, sizeof(tb));
        memmove(tr[y].cnt, tc, sizeof(tc));
    }
    repn(i, 10) tr[x].buf[i] = i;
}

void init(int x, int l, int r, const VL& a) {
    repn(i, 10) tr[x].buf[i] = i;
    if(l + 1 == r) {
        fillchar(tr[x].cnt, 0);
        for(LL b = 1; b <= a[l]; b *= 10) {
            tr[x].cnt[a[l] / b % 10] += b;
        }
        return;
    }
    const int m = (l + r) / 2;
    init(x * 2 + 1, l, m, a);
    init(x * 2 + 2, m, r, a);
    update(x);
}

void change(int x, int l, int r, int st, int en, int p, int q) {
    if(st <= l && r <= en) {
        repn(i, 10) if(tr[x].buf[i] == p) tr[x].buf[i] = q;
        tr[x].cnt[q] += tr[x].cnt[p], tr[x].cnt[p] = 0;
        return;
    }
    release(x);
    const int m = (l + r) / 2;
    if(st < m) change(x * 2 + 1, l, m, st, en, p, q);
    if(m < en) change(x * 2 + 2, m, r, st, en, p, q);
    update(x);
}

void query(int x, int l, int r, int st, int en, LL ans[]) {
    if(st <= l && r <= en) {
        repn(i, 10) ans[i] += tr[x].cnt[i];
        return;
    }
    release(x);
    const int m = (l + r) / 2;
    if(st < m) query(x * 2 + 1, l, m, st, en, ans);
    if(m < en) query(x * 2 + 2, m, r, st, en, ans);
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    VL a = read_vl(n);
    init(0, 0, n, a);
    while(q--) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int l, r, x, y;
            scanf("%d%d%d%d", &l, &r, &x, &y), --l;
            if(x != y) change(0, 0, n, l, r, x, y);
        } else {
            int l, r;
            scanf("%d%d", &l, &r), --l;
            LL cnt[10];
            fillchar(cnt, 0);
            query(0, 0, n, l, r, cnt);
            LL ans = 0;
            repn(i, 10) ans += i * cnt[i];
            printf("%lld\n", ans);
        }
    }
    return 0;
}