#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unistd.h>
#include <stdlib.h>
#include <cassert>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


using namespace std;
using namespace atcoder;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 2e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)();
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec readvec(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

/*
ll fact[fact_table + 5], rfact[fact_table + 5];

void c3_init() {
    fact[0] = rfact[0] = 1;
    for (ll i = 1; i <= fact_table; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table], mod - 2, mod);
    for (ll i = fact_table; i >= 1; i--) {
        rfact[i - 1] = rfact[i] * i;
        rfact[i - 1] %= mod;
    }
    return;
}
ll c3(ll n, ll r) {
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/

P edges[300005], query[500005];
bool multicase = false;
bool WillDelete[300005];
bool marked[500005];


vector<ll> G[800005];
ll parent[800005];
ll lef[800005], righ[800005];
ll bossnode;

struct S {
    ll v, id;
};

S op(S l, S r) {
    if (l.v > r.v) {
        return (S) {l.v, l.id};
    } else {
        return (S) {r.v, r.id};
    }
}

S e() {
    return (S) { 0, -1};
}

void add_edge(int v, int u) {
    G[v].pb(u);
    G[u].pb(v);
    return;
}



ll findd(int v) {
    // v
    if (parent[v] == v) {
        return v;
    } else {
        return parent[v] = findd(parent[v]);
    }
}

void merge(int v, int u, bool newboss) {
    v = findd(v);
    u = findd(u);
    if (v == u) return;
    if (!newboss) {
        parent[v] = u;
        add_edge(u, v);
    } else {
        parent[v] = bossnode;
        parent[u] = bossnode;
        parent[bossnode] = bossnode;
        add_edge(u, bossnode);
        add_edge(v, bossnode);
        bossnode ++;
    }
}

void dfs(ll v, ll p, int& idx) {
    lef[v] = idx ++;
    for (auto u : G[v]) {
        if (u != p) dfs(u, v, idx);
    }
    righ[v] = idx;
}

void init(ll n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    return;
}

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    init(n);
    bossnode = n + 1;
    vec po(n);
    for (int i = 0; i < n; i++) {
        cin >> po[i];
    }
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        edges[i].first = a, edges[i].second = b;
    }
    for (int i = 0; i < q; i++) {
        ll type, num;
        cin >> type >> num;
        query[i].first = type, query[i].second = num;
        if (type == 2) {
            WillDelete[num - 1] = true;
        }
    }

    for (int i = 0; i < m; i++) {
        if (WillDelete[i]) continue;
        merge(edges[i].first, edges[i].second, false);
    }

    vec nodes;

    for (int i = q - 1; i >= 0; i--) {
        ll type = query[i].first;
        if (type == 1) {
            // 
            ll node = query[i].second;
            ll p = findd(node);
            nodes.pb(p);
        } else {
            // 
            ll idx = query[i].second - 1;
            int v = edges[idx].first, u = edges[idx].second;
            merge(u, v, true);
        }
    }
    reverse(nodes.begin(), nodes.end());

    // 
    // 
    int id = 0;
    for (int i = 1; i < bossnode; i++) {
        if (marked[findd(i)]) continue;
        marked[findd(i)] = true;
        dfs(findd(i), -1, id);
    }

    for (int i = 1; i <= n; i++) {
        // pe(lef[i]); p(righ[i]);
    }
    // segtree
    segtree<S, op, e> seg(800000);
    for (int i = 1; i <= n; i++) {
        seg.set(lef[i], (S) {po[i - 1], lef[i]});
    }

    for (auto v : nodes) {
        // v
        auto ans = seg.prod(lef[v], righ[v]);
        if (ans.v > 0) seg.set(ans.id, (S) {0, ans.id});
        p(ans.v);
    }
    return;
}


int main() {
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }

    // solve();
    return 0;
}