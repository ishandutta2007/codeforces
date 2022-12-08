// 15:46 - 16:00
//       - 16:37 - wa
//       - 16:55 -
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

// const int O = 50;
const int O = 500010;
const int N = O * 2;
const int kInf = 1 << 29;

struct Node {
    int in, buf;
    PII x, y;
    int m;
} tr[N * 4];
int a[N];

void update(int x, int l, int r) {
    if(l + 1 == r) {
        tr[x].m = kInf;
        tr[x].x = tr[x].y = {kInf, kInf};
        int d = tr[x].in - l;
        if(-a[l] <= d && d <= a[l]) {
            tr[x].m = l;
        } else {
            if(d < 0) {
                tr[x].x = {-d - a[l], l};
            } else {
                tr[x].y = {d - a[l], l};
            }
        }
    } else {
        tr[x].m = min(tr[x * 2 + 1].m, tr[x * 2 + 2].m);
        tr[x].x = min(tr[x * 2 + 1].x, tr[x * 2 + 2].x);
        tr[x].y = min(tr[x * 2 + 1].y, tr[x * 2 + 2].y);
    }
}

void init(int x, int l, int r) {
    tr[x].buf = 0;
    if(l + 1 == r) {
        tr[x].in = O;
    } else {
        const int m = (l + r) / 2;
        init(x * 2 + 1, l, m);
        init(x * 2 + 2, m, r);
    }
    update(x, l, r);
}

void push(int x, int val) {
    tr[x].buf += val;
    tr[x].in += val;
    tr[x].x.fi -= val, tr[x].y.fi += val;
}

void propagrate(int x) {
    if(tr[x].buf) {
        push(x * 2 + 1, tr[x].buf);
        push(x * 2 + 2, tr[x].buf);
        tr[x].buf = 0;
    }
}

int out(int x, int l, int r, int ind) {
    int ans;
    if(l + 1 == r) {
        ans = tr[x].in;
        if(ans < l) {
            ans = min(ans + a[l], l);
        } else {
            ans = max(ans - a[l], l);
        }
        // printf("  found i=%d in=%d out=%d\n", l - O, tr[x].in - O, ans - O);
    } else {
        propagrate(x);
        const int m = (l + r) / 2;
        if(ind < m) {
            ans = out(x * 2 + 1, l, m, ind);
        } else {
            ans = out(x * 2 + 2, m, r, ind);
        }
    }
    update(x, l, r);
    return ans;
}

Node get(int x, int l, int r, int ind) {
    if(ind <= l) return tr[x];
    const int m = (l + r) / 2;
    propagrate(x);
    if(ind < m) {
        Node ans = get(x * 2 + 1, l, m, ind);
        setmin(ans.m, tr[x * 2 + 2].m);
        setmin(ans.x, tr[x * 2 + 2].x);
        setmin(ans.y, tr[x * 2 + 2].y);
        return ans;
    } else {
        return get(x * 2 + 2, m, r, ind);
    }
}

void add(int x, int l, int r, int st, int en, int val) {
    if(st <= l && r <= en) {
        push(x, val);
        return;
    }
    propagrate(x);
    const int m = (l + r) / 2;
    if(st < m) add(x * 2 + 1, l, m, st, en, val);
    if(m < en) add(x * 2 + 2, m, r, st, en, val);
    update(x, l, r);
}

VI solve(VI vs) {
    fillchar(a, 0);
    init(0, 0, N);
    VI ans;
    for(int v : vs) {
        int i = v + O;
        int pre = out(0, 0, N, i);
        ++a[i];
        while(1) {
            int delta = out(0, 0, N, i) - pre;
            // printf("v=%d i=%d delta=%d (pre=%d cur=%d)\n", v, i - O, delta,
            // pre - O, pre + delta - O);
            if(delta == 0) break;
            Node p = get(0, 0, N, i + 1);
            int j = p.m;
            if(delta > 0) {
                if(p.x.fi == 1) setmin(j, p.x.se);
            } else {
                if(p.y.fi == 1) setmin(j, p.y.se);
            }
            // printf("  j=%d (m=%d x=%d,%d y=%d,%d)\n", j - O, p.m - O, p.x.fi,
            // p.x.se - O, p.y.fi, p.y.se - O);
            if(j < N) {
                pre = out(0, 0, N, j);
                // printf("now add\n");
                add(0, 0, N, i + 1, j + 1, delta);
                out(0, 0, N, j);
                i = j;
            } else {
                add(0, 0, N, i + 1, N, delta);
                break;
            }
        }
        ans.pb(out(0, 0, N, N - 1) - O);
    }
    return ans;
}

VI vio(VI xs) {
    VI b, ans;
    for(int x : xs) {
        b.pb(x);
        sort(all(b));
        int cur = 0;
        for(int y : b) {
            if(y != cur) cur += (cur < y ? 1 : -1);
        }
        ans.pb(cur);
    }
    return ans;
}

void check() {
    while(0) {
        srand(1234);
        VI b = {3, 3, 1, 2};
        cout << solve(b) << endl;
        cout << vio(b) << endl;
        exit(0);
    }
    int x = 0;
    while(1) {
        srand(x = x * 10101 ^ 3131214);
        VI xs;
        repn(i, 40) xs.pb(rand() % 70 - 30);
        srand(1234);
        VI ans = solve(xs);
        VI std = vio(xs);
        cout << xs << " " << ans << endl;
        if(ans != std) {
            cout << "  >>> std=" << std << endl;
            while(1)
                ;
        }
    }
}

int main() {
    // check();
    VI vs = read_vi();
    for(int x : solve(vs)) printf("%d\n", x);
    return 0;
}