#include <bits/stdc++.h>
#include <cctype>

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder


using namespace std;
using namespace atcoder;

typedef string::const_iterator State;
class ParseError {};

// using mint = long long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
//small priority queue
//top pop

ll dx[4] = {2, 2, -2, -2};
ll dy[4] = {1, -1, 1, -1};
//,,,

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, a, b) for (ll i = a; i <= (ll)(b); ++i)
#define rep3(i, a, b) for (ll i = a; i >= (ll)(b); --i)

typedef vector<ll> vec;

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec rv(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}
ll mul(ll a, ll b) { if (b == 0) return 0; if (a > INF / b) return INF; return a * b;}
ll mygcd(ll a, ll b) { if (b == 0 || a == b) return a; return mygcd(b, a % b);}

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

bool icpc = false;
bool multicase = false;

ll n, q;
vec v;

struct node {
    ll left, right;
    long double p;
};

struct mylist {
    int siz;
    vector<ll> v;
    vector<long double> prop;
};

mylist init(ll maxi) {
    return mylist{1, vec(1, maxi), vector<long double>(1, 1.0)};
}

node nodes[5005];
mylist lists[5005];
bool used[5005];

struct SegmentTree {
    //SegmentTree seg( vector<ll>(l + 5, INF) );
private:
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(ll x, ll val) {
        //a[x]y()
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    ll getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        //[a,b)
        if (r < 0) r = n;
        if (r <= a || b <= l) return -INF;
        if (a <= l && r <= b) return node[k];

        ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};

bool is_in(node& a, node& b) {
    if (a.left <= b.left && b.right <= a.right) return true;
    return false;
}


mylist merge(mylist a, mylist b) {
    auto va = a.v, vb = b.v;
    auto pa = a.prop, pmb = b.prop;
    int up = max(va[0], vb[0]);
    int down = max(va.back(), vb.back());
    int newsize = up - down + 1;
    vector<ll> vv(newsize, 0);
    vector<long double> pp(newsize, 0.0);
    for (int i = 0; i < newsize; i++) {
        vv[i] = up - i;
    }
    for (int i = 0; i < va.size(); i++) {
        for (int j = 0; j < vb.size(); j++) {
            int nv = max(va[i], vb[j]);
            long double p = pa[i] * pmb[j];
            int idx = up - nv;
            if (idx < 0 || idx >= newsize) continue;
            pp[idx] += p;
        }
    }
    return (mylist){newsize, vv, pp};
}

mylist conv(mylist a, long double p) {
    vector<ll> newv;
    vector<long double> newp;
    auto nowv = a.v;
    auto nowp = a.prop;
    newv.pb(nowv[0] + 1);
    newp.pb(nowp[0] * p);
    for (int i = 0; i + 1 < nowv.size(); i++) {
        newv.pb(nowv[i]);
        newp.pb(nowp[i] * (1.0 - p) + nowp[i + 1] * p);
    }
    newv.pb(newv.back() - 1);
    newp.pb(nowp.back() * (1.0 - p));
    return (mylist) {(int)newv.size(), newv, newp};
}

void printlist(mylist a){
    for(int i=0;i<a.siz;i++){
        pe(a.v[i]);
        ps(a.prop[i]);
    }
    line();
    return;
}

bool solve() {
    cin >> n >> q;
    v.resize(n);
    rep(i, n) {
        cin >> v[i];
    }
    SegmentTree seg = SegmentTree(v);
    rep(i, q) {
        ll l, r;
        long double p;
        cin >> l >> r >> p;
        nodes[i] = {l, r, p};
    }
    nodes[q++] = {1, n, 0.0};
    scc_graph g(q);

    rep(i, q) {
        rep(j, q) {
            if (is_in(nodes[i], nodes[j])) {
                g.add_edge(i, j);
            }
        }
    }

    auto scc = g.scc();

    reverse(scc.begin(), scc.end());

    for (int i = 0; i < scc.size(); i++) {
        int v = scc[i][0];
        ll l = nodes[v].left, r = nodes[v].right;
        mylist base = init(seg.getmax(l - 1, r));
        for (int j = 0; j < i; j++) {
            if (used[j]) continue;
            int u = scc[j][0];
            if (is_in(nodes[v], nodes[u])) {
                base = merge(base, lists[j]);
                used[j] = true;
            }
        }

        for (auto v : scc[i]) {
            base = conv(base, nodes[v].p);
        }

        lists[i] = base;
    }

    mylist res = lists[scc.size() - 1];

    long double ans = 0.0;

    for (int i = 0; i < res.siz; i++) {
        ans += ((long double)res.v[i] * res.prop[i]);
    }

    ps(ans);

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (icpc) {
        while (solve());
        return 0;
    }
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