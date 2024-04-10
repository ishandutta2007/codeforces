/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                   \
    cerr << #v << ":";                 \
    for (int i = 0; i < v.size(); i++) \
        cerr << " " << v[i];           \
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
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
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
void YES(bool t = true) { cout << (t ? "YES" : "NO") << endl; }
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
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

//  O(1) 
// G[u] 
// 
class ErasableGraph {
    void _erase(int u, int i) {
        int i2 = (int)G[u].size() - 1;
        swap(G[u][i], G[u][i2]);
        swap(partner_position[u][i], partner_position[u][i2]);
        G[u].pop_back();
        partner_position[u].pop_back();
        if (i == i2) return;

        int v = G[u][i];
        int j = partner_position[u][i];
        assert(G[v][j] == u);
        partner_position[v][j] = i;
    }

  public:
    int n;
    vii G;
    vii partner_position;

    ErasableGraph(int n = 0) : n(n), G(n), partner_position(n) {}

    void add_edge(int u, int v) {
        assert(u != v);
        G[u].push_back(v);
        partner_position[u].push_back(G[v].size());
        G[v].push_back(u);
        partner_position[v].push_back((int)G[u].size() - 1);
    }

    // u  i 
    void erase(int u, int i) {
        int v = G[u][i];
        int j = partner_position[u][i];

        _erase(u, i);
        _erase(v, j);
    }
};

template <typename T>
class ErasableWeightedGraph {
    void _erase(int u, int i) {
        int i2 = (int)G[u].size() - 1;
        swap(G[u][i], G[u][i2]);
        swap(partner_position[u][i], partner_position[u][i2]);
        G[u].pop_back();
        partner_position[u].pop_back();
        if (i == i2) return;

        int v = G[u][i].first;
        int j = partner_position[u][i];
        assert(G[v][j].first == u);
        partner_position[v][j] = i;
    }

  public:
    int n;
    vector<vector<pair<int, T>>> G;
    vii partner_position;

    ErasableWeightedGraph(int n = 0) : n(n), G(n), partner_position(n) {}

    void add_edge(int u, int v, T w) {
        assert(u != v);
        G[u].push_back({v, w});
        partner_position[u].push_back(G[v].size());
        G[v].push_back({u, w});
        partner_position[v].push_back((int)G[u].size() - 1);
    }

    // u  i 
    void erase(int u, int i) {
        int v = G[u][i].first;
        int j = partner_position[u][i];

        _erase(u, i);
        _erase(v, j);
    }
};

const int N = 311111;
vl a(N);
ll n, m, X;

class UnionFind {
  public:
    int n;
    vi par;
    vi ran;
    vi num;
    int g;
    vl val;

    UnionFind(int _n) {
        n = _n;
        g = n;
        par.resize(n);
        ran.resize(n);
        num.resize(n);
        val.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            ran[i] = 0;
            num[i] = 1;
            val[i] = a[i];
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        int numsum = num[x] + num[y];
        ll valsum = val[x] + val[y];
        if (x == y) {
            return;
        }
        if (ran[x] < ran[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (ran[x] == ran[y]) {
                ran[x]++;
            }
        }
        num[x] = num[y] = numsum;
        val[x] = val[y] = valsum - X;
        g--;
    }

    bool same(int x, int y) { return find(x) == find(y); }
};

struct dice {
    mt19937 mt;
    dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    // [0, x)
    ll operator()(ll x) { return this->operator()(0, x); }
    // [x, y)
    ll operator()(ll x, ll y) {
        uniform_int_distribution<ll> dist(x, y - 1);
        return dist(mt);
    }
    vl operator()(int n, ll x, ll y) {
        vl res(n);
        for (int i = 0; i < n; i++)
            res[i] = this->operator()(x, y);
        return res;
    }
} rnd;

set<pii> G[N];

signed main() {
    cin >> n >> m >> X;
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    using P = pair<pii, int>;
    vector<P> es;
    vector<bool> used(m, true);
    ErasableWeightedGraph<int> GG(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        GG.add_edge(u, v, i);
        es.push_back({pii(u, v), i});
        // G[u].insert(pii(v, i));
        // G[v].insert(pii(u, i));
    }
    rep(_, 100000) {
        int idx = rnd(m);
        if (used[idx]) {
            int u = es[idx].first.first;
            int j = rnd(GG.G[u].size());
            int ii = GG.G[u][j].second;
            GG.erase(u, j);
            used[ii] = false;
        } else {
            GG.add_edge(es[idx].first.first, es[idx].first.second, es[idx].second);
            used[idx] = true;
        }
    }
    rep(idx, m) {
        if (not used[idx]) {
            GG.add_edge(es[idx].first.first, es[idx].first.second, es[idx].second);
        }
    }
    rep(u, n) {
        for (auto [v, i] : GG.G[u]) {
            G[u].insert(pii(v, i));
        }
    }

    if (sum < (n - 1) * X) {
        NO();
        return 0;
    }

    priority_queue<pair<ll, int>> pq;
    rep(i, n) { pq.push({a[i], i}); }

    UnionFind uf(n);
    vi ans;
    while (pq.size()) {
        auto [y, u] = pq.top();
        pq.pop();
        if (uf.find(u) != u) continue;
        if (uf.val[u] != y) continue;

        int tar = -1;
        for (auto itr = G[u].begin(); itr != G[u].end();) {
            auto [v, idx] = *itr;
            v = uf.find(v);
            if (uf.same(u, v)) {
                itr = G[u].erase(itr);
                continue;
            }
            ll valsum = uf.val[u] + uf.val[v];
            if (valsum >= X) {
                tar = v;
                ans.push_back(idx);
                break;
            }
            itr++;
        }
        if (tar == -1) continue;

        int v = tar;
        uf.unite(u, v);
        int root = uf.find(u);
        if (u != root) {
            swap(u, v);
        }
        if (G[u].size() < G[v].size()) {
            for (auto itr = G[u].begin(); itr != G[u].end(); itr++) {
                auto [w, idx] = *itr;
                w = uf.find(w);
                if (uf.same(v, w)) continue;
                if (G[v].lower_bound({w, -inf})->first == w) continue;
                G[v].insert({w, idx});
            }
            G[u].clear();
            swap(G[u], G[v]);
        } else {
            for (auto itr = G[v].begin(); itr != G[v].end(); itr++) {
                auto [w, idx] = *itr;
                w = uf.find(w);
                if (uf.same(u, w)) continue;
                if (G[u].lower_bound({w, -inf})->first == w) continue;
                G[u].insert({w, idx});
            }
            G[v].clear();
        }
        pq.push({uf.val[root], root});
    }

    YES();
    for (int u : ans) {
        cout << u + 1 << '\n';
    }
}