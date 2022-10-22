//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                                \
    cerr << #v << endl;                             \
    for (int iv = 0; iv < v.size(); iv++) {         \
        for (int jv = 0; jv < v[iv].size(); jv++) { \
            cerr << v[iv][jv] << " ";               \
        }                                           \
        cerr << endl;                               \
    }
typedef long long ll;
// #define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

class UnionFind {
  private:
    vi par_;
    vi ran_;
    vi num_;
    vi edge_num_;
    vi roots;

  public:
    int n;
    int g;
    int nu;
    vii G;
    vl val;

    UnionFind(int _n) {
        n = _n;
        g = n;
        nu = n;
        par_.resize(n);
        ran_.resize(n);
        num_.resize(n);
        edge_num_.resize(n);
        roots.resize(n);
        for (int i = 0; i < n; i++) {
            par_[i] = i;
            ran_[i] = 0;
            num_[i] = 1;
            edge_num_[i] = 0;
            roots[i] = i;
        }
        G.resize(2 * n - 1);
        val.resize(n, -1);
    }

    int find(int x) {
        if (par_[x] == x) {
            return x;
        } else {
            return par_[x] = find(par_[x]);
        }
    }

    void unite(int x, int y, int w) {
        x = find(x);
        y = find(y);
        int numsum = num_[x] + num_[y];
        int edge_numsum = edge_num_[x] + edge_num_[y];
        if (x == y) {
            edge_num_[x]++;
            return;
        }
        if (ran_[x] < ran_[y]) {
            par_[x] = y;
        } else {
            par_[y] = x;
            if (ran_[x] == ran_[y]) {
                ran_[x]++;
            }
        }
        num_[x] = num_[y] = numsum;
        edge_num_[x] = edge_num_[y] = edge_numsum + 1;
        g--;

        int rx = roots[x], ry = roots[y];
        G[rx].push_back(nu);
        G[ry].push_back(nu);
        G[nu].push_back(rx);
        G[nu].push_back(ry);
        roots[x] = roots[y] = nu;
        val.push_back(w);
        nu++;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int num(int x) {
        return num_[find(x)];
    }

    int edge_num(int x) {
        return edge_num_[find(x)];
    }
};

class HLD {
  private:
    void dfs_sz(int v) {
        for (int &u : G[v])
            if (u == par[v]) swap(u, G[v].back());
        if (~par[v]) G[v].pop_back();

        for (int &u : G[v]) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[G[v][0]]) swap(u, G[v][0]);
        }
    }

    void dfs_hld(int v, int c, int &pos) {
        vid[v] = pos++;
        inv[vid[v]] = v;
        type[v] = c;
        for (int u : G[v]) {
            if (u == par[v]) continue;
            head[u] = (u == G[v][0] ? head[v] : u);
            dfs_hld(u, c, pos);
        }
    }

  public:
    vector<vector<int>> G;
    vector<int> vid, head, sub, par, dep, inv, type;

    HLD(int n) : G(n), vid(n, -1), head(n), sub(n, 1),
                 par(n, -1), dep(n, 0), inv(n), type(n) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(vector<int> rs = {0}) {
        int c = 0, pos = 0;
        for (int r : rs) {
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, c++, pos);
        }
    }

    int lca(int u, int v) {
        while (1) {
            if (vid[u] > vid[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    // for_each(vertex)
    // [l, r) <- attention!!
    template <typename F>
    void for_each(int u, int v, const F &f) {
        while (1) {
            if (vid[u] > vid[v]) swap(u, v);
            f(max(vid[head[v]], vid[u]), vid[v] + 1);
            if (head[u] != head[v])
                v = par[head[v]];
            else
                break;
        }
    }

    template <typename T, typename Q, typename F>
    T for_each(int u, int v, T ti, const Q &q, const F &f) {
        T l = ti, r = ti;
        while (1) {
            if (vid[u] > vid[v]) {
                swap(u, v);
                swap(l, r);
            }
            l = f(l, q(max(vid[head[v]], vid[u]), vid[v] + 1));
            if (head[u] != head[v])
                v = par[head[v]];
            else
                break;
        }
        return f(l, r);
    }

    // for_each(edge)
    // [l, r) <- attention!!
    template <typename F>
    void for_each_edge(int u, int v, const F &f) {
        while (1) {
            if (vid[u] > vid[v]) swap(u, v);
            if (head[u] != head[v]) {
                f(vid[head[v]], vid[v] + 1);
                v = par[head[v]];
            } else {
                if (u != v) {
                    f(vid[u] + 1, vid[v] + 1);
                }
                break;
            }
        }
    }
};

template <typename T1, typename T2>
class LazySegmentTree {
  public:
    using F = function<T1(T1 &, T1 &)>;           // query_func
    using G = function<T2(T2 &, T2 &)>;           // update_func
    using H = function<T1(T1 &, T2 &, int, int)>; // lazy to node (node, lazy, left, right)
    int n;
    vector<T1> node;
    vector<T2> lazy;
    T1 e1;
    T2 e2;
    F query_func;
    G update_func;
    H eval_func;

    LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1, T2 e2)
        : query_func(query_func), update_func(update_func), eval_func(eval_func), e1(e1), e2(e2) {
        int _n = a.size();
        n = 1;
        while (n < _n)
            n *= 2;
        node.resize(2 * n - 1, e1);
        lazy.resize(2 * n - 1, e2);
        for (int i = 0; i < _n; i++)
            node[i + n - 1] = a[i];
        for (int i = n - 2; i >= 0; i--) {
            node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    inline void eval(int k, int l, int r) {
        if (lazy[k] != e2) { // Change
            node[k] = eval_func(node[k], lazy[k], l, r);
            if (r - l > 1) {
                lazy[2 * k + 1] = update_func(lazy[2 * k + 1], lazy[k]);
                lazy[2 * k + 2] = update_func(lazy[2 * k + 2], lazy[k]);
            }
            lazy[k] = e2; // Change
        }
    }

    void update(int a, int b, T2 x, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = update_func(lazy[k], x);
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    T1 query(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return e1;
        if (a <= l && r <= b) return node[k];
        T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return query_func(resl, resr);
    }
};

void dfs(int now, int par, vi &ord, int n, vii &G) {
    if (now < n) ord.push_back(now);
    for (int ch : G[now]) {
        if (ch == par) continue;
        dfs(ch, now, ord, n, G);
    }
}

struct S {
    int all_ma, all_mi, on_ma, on_mi;
    S(int all_ma = -inf, int all_mi = inf, int on_ma = -inf, int on_mi = inf) : all_ma(all_ma), all_mi(all_mi), on_ma(on_ma), on_mi(on_mi){};
};

S f(S a, S b) {
    S res;
    res.all_ma = max(a.all_ma, b.all_ma);
    res.all_mi = min(a.all_mi, b.all_mi);
    res.on_ma = max(a.on_ma, b.on_ma);
    res.on_mi = min(a.on_mi, b.on_mi);
    return res;
}

int g(int a, int b) {
    return b;
}

S h(S a, int b, int l, int r) {
    if (b == 1) {
        a.on_ma = a.all_ma;
        a.on_mi = a.all_mi;
    } else if (b == 0) {
        a.on_ma = -inf;
        a.on_mi = inf;
    }
    return a;
}

signed main() {
    int n, q;
    cin >> n >> q;

    using P = pair<int, pii>;
    vector<P> wuv(n - 1);
    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        wuv[i] = P(w, pii(u, v));
    }
    sort(all(wuv));

    UnionFind uf(n);

    for (auto [w, uv] : wuv) {
        auto [u, v] = uv;
        uf.unite(u, v, w);
    }

    vii G = uf.G;
    vl val = uf.val;

    vi ord;
    dfs(2 * n - 2, -1, ord, n, G);
    vi pos(n);
    rep(i, n) {
        pos[ord[i]] = i;
    }

    vector<S> ini(n);
    rep(i, n) {
        ini[i] = S(pos[i], pos[i]);
    }
    LazySegmentTree<S, int> seg(ini, f, g, h, S(), -1);

    HLD hld(2 * n - 1);
    rep(u, 2 * n - 1) {
        for (int v : G[u]) {
            if (u < v) hld.add_edge(u, v);
        }
    }
    hld.build({2 * n - 2});

    while (q--) {
        int t;
        cin >> t;
        if (t == 3) {
            int x;
            cin >> x;
            x--;

            S res = seg.query(0, n, 0, 0, seg.n);
            int l = res.on_mi, r = res.on_ma;
            ll ans = -1;
            if (in(l, 0, n) && ord[l] != x) {
                int u = hld.lca(ord[l], x);
                chmax(ans, val[u]);
            }
            if (in(r, 0, n) && ord[r] != x) {
                int u = hld.lca(ord[r], x);
                chmax(ans, val[u]);
            }
            cout << ans << endl;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            if (t == 1) {
                seg.update(l, r, 1, 0, 0, seg.n);
            } else {
                seg.update(l, r, 0, 0, 0, seg.n);
            }
        }
    }
}