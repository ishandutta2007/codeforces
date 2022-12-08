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

constexpr LL P = 911, M = LL(1e9) + 7;
LL power[200010];

void init() {
    power[0] = 1;
    replr(i, 1, 200010) power[i] = power[i - 1] * P % M;
}

struct String {
    struct Node {
        LL h[26];
        int cnt;
        void merge_from(const Node& a, const Node& b) {
            cnt = a.cnt + b.cnt;
            repn(i, 26) h[i] = (a.h[i] * power[b.cnt] + b.h[i]) % M;
        }
    };
    const int n;
    vector<Node> tr;

    void build(int x, int l, int r, const string& s) {
        if (l + 1 == r) {
            repn(i, 26) tr[x].h[i] = (s[l] == char('a' + i) ? 1 : 2);
            tr[x].cnt = 1;
            return;
        }
        const int m = (l + r) / 2;
        build(x * 2 + 1, l, m, s);
        build(x * 2 + 2, m, r, s);
        tr[x].merge_from(tr[x * 2 + 1], tr[x * 2 + 2]);
    }

    String(string s) : n(len(s)), tr(n * 4) { build(0, 0, n, s); }

    Node get(int x, int l, int r, int st, int en) {
        if (st <= l && r <= en) {
            return tr[x];
        }
        const int m = (l + r) / 2;
        const auto L = [&] { return get(x * 2 + 1, l, m, st, en); };
        const auto R = [&] { return get(x * 2 + 2, m, r, st, en); };
        if (st < m && m < en) {
            Node ans;
            ans.merge_from(L(), R());
            return ans;
        } else {
            if (st < m) {
                return L();
            } else {
                return R();
            }
        }
    }

    bool same(int x, int y, int len) {
        Node a = get(0, 0, n, x, x + len);
        Node b = get(0, 0, n, y, y + len);
        sort(a.h, a.h + 26);
        sort(b.h, b.h + 26);
        repn(i, 26) if (!(a.h[i] == b.h[i])) return false;
        return true;
    }
};

int main() {
    init();
    (void)IN;
    int m = IN;
    String s(read_string());
    while (m--) {
        int x = IN - 1, y = IN - 1, len = IN;
        if (s.same(x, y, len)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}