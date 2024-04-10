//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

// #define _GLIBCXX_DEBUG

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
vi dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

class UnionFind {
  private:
    vi par_;      
    vi ran_;      
    vi num_;      
    vi edge_num_; 
  public:
    int n;
    int g; 

    UnionFind(int _n) {
        n = _n;
        g = n;
        par_.resize(n);
        ran_.resize(n);
        num_.resize(n);
        edge_num_.resize(n);
        for (int i = 0; i < n; i++) {
            par_[i] = i;
            ran_[i] = 0;
            num_[i] = 1;
            edge_num_[i] = 0;
        }
    }

    int find(int x) {
        if (par_[x] == x) {
            return x;
        } else {
            return par_[x] = find(par_[x]);
        }
    }

    void unite(int x, int y) {
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

    // move d from u to v
    // if d == 0: return u
    // if d == dist(u, v): return v
    int move(int u, int v, int d) {
        if (d == 0) {
            return u;
        }

        int full_d = distance(u, v);
        assert(d <= full_d);

        if (d == full_d) {
            return v;
        }

        // following to lca, move from v
        d = full_d - d;
        while (1) {
            if (vid[u] > vid[v]) {
                swap(u, v);
                d = full_d - d;
            }

            int nv = par[head[v]];
            int move_d = vid[v] - vid[head[v]] + 1;

            if (move_d >= d) {
                return inv[vid[v] - d];
            }
            v = nv;
            d -= move_d;
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

const int N = 100011, M = 200011;
vector<vector<pii>> G(N);
vi used(M);

ll kruskal(int n, vector<pair<int, pii>> edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    ll res = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (!uf.same(edges[i].second.first, edges[i].second.second)) {
            uf.unite(edges[i].second.first, edges[i].second.second);
            used[edges[i].first] = true;
        }
    }
    return res;
}

vi val(N);
vi depth(N);
constexpr int K = 20;
vii par(N, vi(K, -1));

void pre_dfs(int now, int pa, int d, const vii &G) {
    par[now][0] = pa;
    depth[now] = d;
    for (int ch : G[now]) {
        if (ch == pa) {
            continue;
        }
        pre_dfs(ch, now, d + 1, G);
    }
}

int up(int u, int k) {
    int now = u;
    rep(j, K) {
        int mask = 1 << j;
        if (k & mask) {
            now = par[now][j];
            assert(now != -1);
        }
    }
    return now;
}

void dfs(int now, int par, const vii &G) {
    for (int ch : G[now]) {
        if (ch == par) {
            continue;
        }
        val[ch] += val[now];
        dfs(ch, now, G);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    using P = pair<int, pii>;
    vector<P> edges;

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(i, v);
        G[v].emplace_back(i, u);
        edges.emplace_back(i, pii(u, v));
    }

    kruskal(n, edges);
    vii G2(n);

    HLD hld(n);
    rep(i, m) {
        if (used[edges[i].first]) {
            auto [u, v] = edges[i].second;
            hld.add_edge(u, v);
            G2[u].push_back(v);
            G2[v].push_back(u);
        }
    }
    hld.build({0});
    pre_dfs(0, -1, 0, G2);

    for (int j = 1; j < K; j++) {
        rep(now, n) {
            int p1 = par[now][j - 1];
            if (p1 == -1) {
                par[now][j] = p1;
                continue;
            }
            int p2 = par[p1][j - 1];
            par[now][j] = p2;
        }
    }

    int cnt = 0;
    rep(i, m) {
        if (!used[edges[i].first]) {
            cnt++;
            auto [u, v] = edges[i].second;

            int lc = hld.lca(u, v);

            if (lc == u or lc == v) {
                int non_lc;
                if (lc == u) {
                    non_lc = v;
                } else {
                    non_lc = u;
                }

                // int d_lc = depth[lc];
                // int d_no = depth[non_lc];

                // int diff = d_no - d_lc;
                // int ch = up(non_lc, diff - 1);
                int ch = hld.move(lc, non_lc, 1);

                val[0]++;
                val[ch]--;
                val[non_lc]++;
            } else {
                val[u]++;
                val[v]++;
            }
        }
    }

    dfs(0, -1, G2);

    rep(i, n) {
        if (val[i] == cnt) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}