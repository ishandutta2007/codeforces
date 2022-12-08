// 22:34 - 22:47
#include <algorithm>
#include <cassert>
#include <cmath>
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
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
// clang-format on
// }}}

class DS {
    const int n;
    vector<set<PII>> tr;

    void insert(int x, int l, int r, int st, int en, PII p, bool flag) {
        if(st <= l && r <= en) {
            if(flag) {
                tr[x].insert(p);
            } else {
                tr[x].erase(p);
            }
            return;
        }
        const int m = (l + r) / 2;
        if(st < m) insert(x * 2 + 1, l, m, st, en, p, flag);
        if(m < en) insert(x * 2 + 2, m, r, st, en, p, flag);
    }

    PII getmax(int x, int l, int r, int ind) {
        PII ans{-1, -1};
        if(!tr[x].empty()) {
            setmax(ans, *tr[x].rbegin());
        }
        if(l + 1 == r) return ans;
        const int m = (l + r) / 2;
        if(ind < m) {
            setmax(ans, getmax(x * 2 + 1, l, m, ind));
        } else {
            setmax(ans, getmax(x * 2 + 2, m, r, ind));
        }
        return ans;
    }

public:
    DS(int n) : n(n), tr(n * 4) {}

    void insert(int st, int en, PII p) { insert(0, 0, n, st, en, p, true); }

    void erase(int st, int en, PII p) { insert(0, 0, n, st, en, p, false); }

    PII getmax(int x) { return getmax(0, 0, n, x); }
};

int main() {
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    struct Barrier {
        int u, l, r, s;
        void read() { scanf("%d%d%d%d", &u, &l, &r, &s), --l; }
    };
    vector<Barrier> a(n);
    repn(i, n) a[i].read();

    vector<PII> events;
    repn(i, n) {
        events.pb(mp(a[i].u, i + 1));
        if(a[i].u + a[i].s <= h) {
            events.pb(mp(a[i].u + a[i].s + 1, -i));
        }
    }
    sort(all(events));
    DS d(w);
    VI f(n);
    const auto query = [&](int x) {
        PII p = d.getmax(x);
        if(p.fi < 0) return 1;
        return f[p.se];
    };
    const int MOD = int(1e9) + 7;
    for(const auto& e : events) {
        if(e.se > 0) {
            const int i = e.se - 1;
            d.insert(a[i].l, a[i].r, mp(a[i].u, i));
            int l = a[i].l - 1, r = a[i].r;
            if(l < 0) l = r;
            if(r == w) r = l;
            f[i] = (query(l) + query(r)) % MOD;
        } else {
            const int i = -e.se;
            d.erase(a[i].l, a[i].r, mp(a[i].u, i));
        }
    }
    int ans = 0;
    repn(x, w)(ans += query(x)) %= MOD;
    printf("%d\n", ans);
    return 0;
}