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
#define DEBUG_MAT(v)                            \
    cerr << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
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
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
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

int f(int a, int b) {
    return a + b;
}
int g(int a, int b) {
    return b;
}
int h(int a, int b, int l, int r) {
    return b * (r - l);
}

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

const int N = 3e5 + 10;
vii G1(N), G2(N);
vi depth(N);
vi leaf(N);
int ans = 1;

void pre_dfs(int now, int par, int d) {
    depth[now] = d;
    for (int ch : G2[now]) {
        if (ch == par) continue;
        pre_dfs(ch, now, d + 1);
    }
}

void dfs(int now, int par, HLD &hld, LazySegmentTree<int, int> &seg, int cnt) {
    int ori = -1;
    bool op = false;
    if (now != 0) {
        int val = seg.query(hld.vid[now], hld.vid[now] + 1, 0, 0, seg.n);
        ori = val;
        if (val != -1) {
            int d_ori = depth[ori];
            if (d_ori > depth[now]) {
                op = false;
            } else {
                op = true;
                seg.update(hld.vid[val], hld.vid[val] + hld.sub[val], -1, 0, 0, seg.n);

                auto func = [&](int a, int b) {
                    seg.update(a, b, -1, 0, 0, seg.n);
                };
                hld.for_each(val, 0, func);
                cnt--;
            }
        } else {
            op = true;
        }

        if (op) {
            cnt++;
            seg.update(hld.vid[now], hld.vid[now] + hld.sub[now], now, 0, 0, seg.n);

            auto func = [&](int a, int b) {
                seg.update(a, b, now, 0, 0, seg.n);
            };
            hld.for_each(now, 0, func);
        }
    }
    chmax(ans, cnt);

    for (int ch : G1[now]) {
        if (ch == par) continue;
        dfs(ch, now, hld, seg, cnt);
    }

    if (op) {
        cnt--;
        seg.update(hld.vid[now], hld.vid[now] + hld.sub[now], -1, 0, 0, seg.n);

        auto func = [&](int a, int b) {
            seg.update(a, b, -1, 0, 0, seg.n);
        };
        hld.for_each(now, 0, func);

        if (ori != -1) {
            int val = ori;
            seg.update(hld.vid[val], hld.vid[val] + hld.sub[val], val, 0, 0, seg.n);

            auto func = [&](int a, int b) {
                seg.update(a, b, val, 0, 0, seg.n);
            };
            hld.for_each(val, 0, func);
            cnt++;
        }
    }
}

void solve() {
    ans = 1;

    int n;
    cin >> n;
    rep1(i, n - 1) {
        int u;
        cin >> u;
        u--;
        G1[i].push_back(u);
        G1[u].push_back(i);
    }

    HLD hld(n);
    rep1(i, n - 1) {
        int u;
        cin >> u;
        u--;
        G2[i].push_back(u);
        G2[u].push_back(i);
        hld.add_edge(i, u);
    }
    hld.build();

    vi ini(n, -1);
    LazySegmentTree<int, int> seg(ini, f, g, h, 0, -2);

    pre_dfs(0, -1, 0);

    dfs(0, -1, hld, seg, 0);
    cout << ans << endl;

    rep(i, n) {
        G1[i].clear();
        G2[i].clear();
        leaf[i] = 0;
        depth[i] = 0;
    }
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}