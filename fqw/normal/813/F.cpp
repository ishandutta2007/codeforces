// 18:36 -
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

struct Solver {
    struct Link {
        int size = 1;
        int f = -1, c = 0;
    };
    vector<Link> f;
    vector<pair<int, Link>> reverts;
    bool ok = true;

    Solver(int n, VPI es) : f(n) {
        // cout << "solver " << es << endl;
        for(const auto& e : es) {
            if(!merge(e.fi, e.se)) {
                ok = false;
                return;
            }
        }
        reverts.clear();
    }

    bool query(VPI es) {
        // cout << "  " << es << endl;
        if(!ok) return false;
        bool ans = true;
        for(const auto& e : es) {
            if(!merge(e.fi, e.se)) {
                ans = false;
                break;
            }
        }
        while(!reverts.empty()) {
            f[reverts.back().fi] = reverts.back().se;
            reverts.pop_back();
        }
        return ans;
    }

    Link get(int x) {
        if(f[x].f < 0) return {0, x, 0};
        Link p = get(f[x].f);
        p.c ^= f[x].c;
        return p;
    }

    bool merge(int a, int b) {
        Link p = get(a), q = get(b);
        if(p.f == q.f) {
            if(p.c == q.c) return false;
            return true;
        }
        a = p.f, b = q.f;
        if(f[a].size < f[b].size) swap(a, b);
        reverts.pb({a, f[a]});
        reverts.pb({b, f[b]});
        f[a].size = b;
        f[b].f = a, f[b].c = p.c ^ q.c ^ 1;
        return true;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    VPI qs = read_vpi();
    for(auto& e : qs) {
        --e.fi, --e.se;
        if(e.fi > e.se) swap(e.fi, e.se);
    }
    VI qop;
    {
        set<PII> s;
        for(const auto& q : qs) {
            if(s.count(q)) {
                qop.pb(-1);
                s.erase(q);
            } else {
                qop.pb(1);
                s.insert(q);
            }
        }
    }

    const int K = 500;
    set<PII> cur;
    for(int begin = 0; begin < sz(qs); begin += K) {
        const int end = min(sz(qs), begin + K);
        set<PII> tmp;
        replr(i, begin, end) {
            if(cur.count(qs[i])) {
                tmp.insert(qs[i]);
            }
        }
        for(const auto& e : tmp) {
            cur.erase(e);
        }

        Solver solver(n, VPI(all(cur)));
        replr(i, begin, end) {
            if(qop[i] > 0) {
                tmp.insert(qs[i]);
            } else {
                tmp.erase(qs[i]);
            }
            bool ans = solver.query(VPI(all(tmp)));
            printf("%s\n", ans ? "YES" : "NO");
        }
        cur.insert(all(tmp));
    }
    return 0;
}