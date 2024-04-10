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

typedef pair<int, LL> PIL;

class Set {
    struct Node {
        int ran, size;
        LL val;
        int l, r;
    } tr[800020];
    int root, cnt = 0;

    void update(int x) { tr[x].size = tr[tr[x].l].size + tr[tr[x].r].size + 1; }

    int lrotate(int x) {
        int y = tr[x].l;
        tr[x].l = tr[y].r, tr[y].r = x;
        update(x);
        return y;
    }

    int rrotate(int x) {
        int y = tr[x].r;
        tr[x].r = tr[y].l, tr[y].l = x;
        update(x);
        return y;
    }

    int insert(int x, LL val) {
        if(x == 0) {
            x = ++cnt;
            tr[x].ran = rand(), tr[x].val = val;
            tr[x].l = tr[x].r = 0;
        } else {
            if(val < tr[x].val) {
                tr[x].l = insert(tr[x].l, val);
                if(tr[tr[x].l].ran > tr[x].ran) x = lrotate(x);
            } else {
                tr[x].r = insert(tr[x].r, val);
                if(tr[tr[x].r].ran > tr[x].ran) x = rrotate(x);
            }
        }
        update(x);
        return x;
    }

    int remove(int x, LL val) {
        if(tr[x].val == val) {
            if(tr[x].l == 0 && tr[x].r == 0) return 0;
            if(tr[tr[x].l].ran > tr[tr[x].r].ran) {
                x = lrotate(x);
                tr[x].r = remove(tr[x].r, val);
            } else {
                x = rrotate(x);
                tr[x].l = remove(tr[x].l, val);
            }
        } else {
            if(val < tr[x].val) {
                tr[x].l = remove(tr[x].l, val);
            } else {
                tr[x].r = remove(tr[x].r, val);
            }
        }
        update(x);
        return x;
    }

    PIL upper_bound(int x, LL val) const {
        if(x == 0) return {0, -1};
        if(val < tr[x].val) {
            return upper_bound(tr[x].l, val);
        } else {
            PIL t = upper_bound(tr[x].r, val);
            setmax(t.se, tr[x].val);
            t.fi += tr[tr[x].l].size + 1;
            return t;
        }
    }

    LL kth(int x, int k) const {
        assert(x > 0);
        int lsize = tr[tr[x].l].size;
        if(k < lsize) return kth(tr[x].l, k);
        if(k == lsize) return tr[x].val;
        return kth(tr[x].r, k - lsize - 1);
    }

public:
    Set() {
        root = 0;
        tr[0].ran = -1, tr[0].size = 0;
        tr[0].l = tr[0].r = 0;
    }

    void insert(LL val) { root = insert(root, val); }
    void remove(LL val) { root = remove(root, val); }

    // (tot, max)
    PIL upper_bound(LL val) const { return upper_bound(root, val); }

    bool empty() const { return root == 0; }
    LL kth(int k) const { return kth(root, k); }
};

Set s;

int main() {
    const auto get = [&](LL i) { return s.upper_bound(i).fi % 2; };
    const auto invert = [&](LL i) {
        // printf("invert %d\n", i);
        if(s.upper_bound(i).se == i) {
            s.remove(i);
        } else {
            s.insert(i);
        }
    };
    const auto remove = [&](LL l, LL r) {
        while(1) {
            auto p = s.upper_bound(r);
            if(p.se >= l) {
                s.remove(p.se);
            } else {
                break;
            }
        }
    };

    int q;
    scanf("%d", &q);
    while(q--) {
        int t;
        LL l, r;
        scanf("%d%lld%lld", &t, &l, &r);
        // printf("cur %d %d %d\n", t, l, r);
        if(t == 1 || t == 2) {
            int wanted = (t == 1 ? 1 : 0);
            LL p = get(r + 1);
            remove(l + 1, r);
            if(get(l) != wanted) invert(l);
            if(get(r + 1) != p) invert(r + 1);
        } else {
            invert(l), invert(r + 1);
        }
        // if(!s.empty()) printf("0th=%d 1th=%d\n", s.kth(0), s.kth(1));
        LL ans = 1;
        if(!s.empty() && s.kth(0) == 1) {
            ans = s.kth(1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*

VI vio(vector<pair<int, PII>> qs) {
    VB a(1111);
    VI ans;
    for(const auto& q : qs) {
        if(q.fi == 1) {
            rep(i, q.se.fi, q.se.se) a[i] = true;
        } else if(q.fi == 2) {
            rep(i, q.se.fi, q.se.se) a[i] = false;
        } else {
            rep(i, q.se.fi, q.se.se) a[i] = !a[i];
        }
        int p = 1;
        while(a[p]) ++p;
        ans.pb(p);
    }
    return ans;
}

vector<pair<int, PII>> gen() {
    vector<pair<int, PII>> a;
    repn(i, 30) {
        int t = rand() % 3 + 1;
        int l = rand() % 50 + 1, r = rand() % 50 + 1;
        if(l > r) swap(l, r);
        a.pb(mp(t, mp(l, r)));
    }
    return a;
}

void check() {
    while(1) {
        auto a = gen();
        auto v = vio(a), s = solve(a);
        if(v != s) {
            cout << "wrong for " << a << endl;
            cout << "vio:   " << v << endl;
            cout << "solve: " << s << endl;
            for(;;)
                ;
        } else {
            cout << "ok. ans=" << v << endl;
        }
    }
}
*/