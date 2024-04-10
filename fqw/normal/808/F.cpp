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

template <class T> class Net {
public:
    explicit Net(int n0)
        : n(n0 + 4),
          original_s(n0),
          original_t(n0 + 1),
          super_s(n0 + 2),
          super_t(n0 + 3),
          es(n),
          dis(n) {}

    int s() const { return original_s; }
    int t() const { return original_t; }

    void* add(int x, int y, T w) {
        assert(x >= 0 && x < n && y >= 0 && y < n);
        Edge *e1, *e2;
        es[x].emplace_back(e1 = new Edge{y, w, nullptr});
        es[y].emplace_back(e2 = new Edge{x, 0, nullptr});
        e1->oppo = e2, e2->oppo = e1;
        return e1;
    }
    void* add(int x, int y, pair<T, T> w) {
        assert(w.fi <= w.se);
        if(w.fi > 0) {
            add(super_s, y, w.fi);
            add(x, super_t, w.fi);
            super_total += w.fi;
        }
        return add(x, y, w.se - w.fi);
    }

    // returns -1 if no solution.
    T compute() {
        if(super_total > 0) {
            add(original_t, original_s, numeric_limits<T>::max());
            LL r = 0, tmp;
            while((tmp = augment(super_s, super_t)) > 0) {
                r += tmp;
            }
            if(r != super_total) return -1;
        }
        T ans = 0, tmp;
        while((tmp = augment(original_s, original_t)) > 0) {
            ans += tmp;
        }
        return ans;
    }

    T flow(void* e) const { return static_cast<Edge*>(e)->oppo->w; }
    bool on_cut(void* e) const {
        return dis[static_cast<Edge*>(e)->oppo->y] > 0 &&
               dis[static_cast<Edge*>(e)->y] == 0;
    }
    VI left() const {
        VI r;
        repn(i, n - 4) if(dis[i] > 0) r.pb(i);
        return r;
    }

private:
    struct Edge {
        int y;
        T w;
        Edge* oppo;
    };

    T augment(int s, int t) {
        dis.resize(n);
        fill(all(dis), 0);
        dis[s] = 1;
        queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for(const auto& e : es[x]) {
                if(e->w > 0 && dis[e->y] == 0) {
                    dis[e->y] = dis[x] + 1;
                    que.push(e->y);
                }
            }
        }
        if(dis[t] == 0) return 0;

        vector<size_t> ce(n);
        const function<T(int, T)> dfs = [&](int x, T rest) {
            if(x == t) return rest;
            T r = 0;
            for(size_t& i = ce[x]; i < es[x].size(); ++i) {
                const auto& e = es[x][i];
                if(e->w > 0 && dis[e->y] > dis[x]) {
                    T cur = dfs(e->y, min(e->w, rest));
                    e->w -= cur, e->oppo->w += cur;
                    r += cur, rest -= cur;
                    if(rest == 0) break;
                }
            }
            return r;
        };
        return dfs(s, numeric_limits<T>::max());
    }

    const int n, original_s, original_t, super_s, super_t;
    T super_total = 0;
    vector<vector<unique_ptr<Edge>>> es;
    VI dis;
};

bool is_prime(int x) {
    for(int y = 2; y * y <= x; ++y) {
        if(x % y == 0) return false;
    }
    return true;
}

int solve(VPI a) {
    VPI l, r;
    int m1 = -1;
    for(auto p : a) {
        if(p.se == 1) {
            setmax(m1, p.fi);
        } else if(p.se % 2 == 0) {
            l.pb(p);
        } else {
            r.pb(p);
        }
    }
    if(m1 > 0) r.pb({m1, 1});
    Net<int> net(sz(l) + sz(r));
    repn(i, sz(l)) net.add(net.s(), i, l[i].fi);
    repn(i, sz(r)) net.add(sz(l) + i, net.t(), r[i].fi);
    repn(i, sz(l)) repn(j, sz(r)) {
        if(is_prime(l[i].se + r[j].se)) net.add(i, sz(l) + j, 1 << 30);
    }

    int ans = 0;
    for(auto p : l) ans += p.fi;
    for(auto p : r) ans += p.fi;
    ans -= net.compute();
    return ans;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    VI p(n), c(n), l(n);
    repn(i, n) scanf("%d%d%d", &p[i], &c[i], &l[i]);
    int le = 1, ri = n + 1;
    while(le < ri) {
        int mid = (le + ri) / 2;
        VPI a;
        repn(i, n) if(l[i] <= mid) a.pb({p[i], c[i]});
        if(solve(a) >= k) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }
    if(le > n) le = -1;
    printf("%d\n", le);
    return 0;
}