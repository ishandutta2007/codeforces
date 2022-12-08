// 13:30
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

typedef unsigned long long ULL;

ULL sum(ULL i, ULL j) { return (i + j) * (j - i + 1) / 2; }

ULL cnt(ULL i, ULL j) { return j - i + 1; }

int main() {
    //*
    const int n = IN, m = IN;
    const ULL A = IN, B = IN, C = IN;
    VVI es(n);
    repn(_, m) {
        const int i = IN, j = IN;
        es[i].pb(j), es[j].pb(i);
    }
    /*/
    const int n = 500, m = 1000;
    const ULL A = rand() % 100, B = rand() % 100, C = rand() % 100;
    VVI es(n);
    repn(_, m) {
        const int i = rand() % n, j = rand() % n;
        if (find(all(es[i]), j) == es[i].end()) {
            es[i].pb(j), es[j].pb(i);
        }
    }
    //*/
    repn(i, n) sort(all(es[i]));

    const auto solve1 = [&] {
        ULL ans = 0;
        repn(i, n) {
            ans += ULL(n - 1 - i) * ULL(n - 2 - i) / 2 * A * ULL(i);
            ans += ULL(n - 1 - i) * ULL(i) * B * ULL(i);
            ans += ULL(i) * ULL(i - 1) / 2 * C * ULL(i);
        }
        return ans;
    };
    const auto solve2 = [&] {
        ULL ans = 0;
        repn(i, n) {
            ULL s = 0, c = 0;
            for (int j : es[i]) {
                if (j > i) {
                    ans += (A * i + B * j) * cnt(j + 1, n - 1);
                    ans += C * sum(j + 1, n - 1);
                    ans += (A * ULL(i) + C * ULL(j)) * (cnt(i + 1, j - 1) - c);
                    ans += B * (sum(i + 1, j - 1) - s);
                    s += j, c += 1;
                }
            }
        }
        return ans;
    };
    const auto solve3 = [&] {
        ULL ans = 0;
        repn(i, n) {
            ULL s = 0, c = 0;
            for (int j : es[i]) {
                if (j < i) {
                    ans += (B * j + C * i) * (cnt(0, j - 1) - c);
                    ans += A * (sum(0, j - 1) - s);
                    s += j, c += 1;
                }
            }
        }
        return ans;
    };
    const auto solve4 = [&] {
        ULL ans = 0;
        repn(i, n) {
            ULL s1 = 0, c1 = 0, s2 = 0, c2 = 0;
            for (int j : es[i]) {
                if (j < i) {
                    s1 += j, c1 += 1;
                } else {
                    s2 += j, c2 += 1;
                }
            }
            ans += A * s1 * c2 + B * i * c1 * c2 + C * s2 * c1;
        }
        return ans;
    };
    const auto solve5 = [&] {
        ULL ans = 0;
        repn(i, n) for (int j : es[i]) {
            if (j > i) {
                const auto *v1 = &es[i], *v2 = &es[j];
                if (len(*v1) > len(*v2)) swap(v1, v2);
                for (int k : *v1) {
                    if (k > j) {
                        auto it = lower_bound(all(*v2), k);
                        if (it != v2->end() && *it == k) {
                            ans += A * i + B * j + C * k;
                        }
                    }
                }
            }
        }
        return ans;
    };
    /*
    const auto vio1 = [&] {
        ULL ans = 0;
        repn(i, n) replr(j, i + 1, n) replr(k, j + 1, n) {
            ans += A * i + B * j + C * k;
        }
        return ans;
    };
    const auto vio2 = [&] {
        VVB b(n, VB(n, false));
        repn(i, n) for (int j : es[i]) b[i][j] = true;
        ULL ans = 0;
        repn(i, n) replr(j, i + 1, n) replr(k, j + 1, n) {
            if (b[i][j] || b[i][k]) ans += A * i + B * j + C * k;
        }
        return ans;
    };
    const auto vio3 = [&] {
        VVB b(n, VB(n, false));
        repn(i, n) for (int j : es[i]) b[i][j] = true;
        ULL ans = 0;
        repn(i, n) replr(j, i + 1, n) replr(k, j + 1, n) {
            if (b[j][k] && !b[i][k]) ans += A * i + B * j + C * k;
        }
        return ans;
    };
    const auto vio5 = [&] {
        VVB b(n, VB(n, false));
        repn(i, n) for (int j : es[i]) b[i][j] = true;
        ULL ans = 0;
        repn(i, n) replr(j, i + 1, n) replr(k, j + 1, n) {
            if (b[i][j] && b[i][k] && b[j][k]) ans += A * i + B * j + C * k;
        }
        return ans;
    };

    cout << solve1() << " " << vio1() << endl;
    cout << solve2() << " " << vio2() << endl;
    cout << solve3() << " " << vio3() << endl;
    cout << solve5() << " " << vio5() << endl;
    //*/

    ULL ans = solve1();
    ans -= solve2();
    ans -= solve3();
    ans += solve4();
    ans -= solve5();
    cout << ans << endl;

    return 0;
}