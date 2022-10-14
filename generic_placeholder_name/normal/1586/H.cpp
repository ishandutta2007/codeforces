#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 2e5 + 5, K = 18;
constexpr int INF = 0x3f3f3f3f;

vector<pii> adj[N];
int n;

int par[N][K + 1];
int dst[N][K + 1];
int dep[N];
int rtdist[N];

void ldfs(int u, int p) {
    par[u][0] = p;
    rep1(i, K) par[u][i] = par[par[u][i - 1]][i - 1];
    rep1(i, K) dst[u][i] = max(dst[u][i - 1], dst[par[u][i - 1]][i - 1]);

    for (auto& [v, w] : adj[u])
        if (v != p) {
            dep[v] = dep[u] + 1;
            dst[v][0] = w;
            ldfs(v, u);
        }
}

int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);

    for (int i = K; ~i; i--)
        if (dep[u] - (1 << i) >= dep[v])
            u = par[u][i];

    if (u == v)
        return u;

    for (int i = K; ~i; i--)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }

    return par[u][0];
}

int dist(int u, int v) {
    int ans = 0;

    if (dep[u] < dep[v])
        swap(u, v);

    for (int i = K; ~i; i--)
        if (dep[u] - (1 << i) >= dep[v]) {
            ans = max(ans, dst[u][i]);
            u = par[u][i];
        }

    if (u == v)
        return ans;

    for (int i = K; ~i; i--)
        if (par[u][i] != par[v][i]) {
            ans = max({ans, dst[u][i], dst[v][i]});
            u = par[u][i];
            v = par[v][i];
        }

    return max({ans, dst[u][0], dst[v][0]});
}

vi cadj[N];
int cpar[N];
array<pii, 2> mdist[N];
int cdist[N][K + 1];

bool cvis[N];
int csz[N];

void cdfs(int u, int p = -1) {
    csz[u] = 1;

    for (auto& [v, _] : adj[u])
        if (!cvis[v] && v != p) {
            cdfs(v, u);
            csz[u] += csz[v];
        }
}

int decomp(int u) {
    cdfs(u, -1);
    int s = csz[u];
    int ans = u, par = -1;

    while (1) {
        int lg = 0, lg_sz = 0;

        for (auto& [v, _] : adj[ans])
            if (!cvis[v] && v != par && csz[v] > lg_sz)
                lg_sz = csz[v], lg = v;

        if (lg_sz > s / 2)
            par = ans, ans = lg;
        else {
            cvis[ans] = 1;

            for (auto& [v, _] : adj[ans])
                if (!cvis[v]) {
                    int x = decomp(v);
                    cadj[ans].pb(x);
                    cpar[x] = ans;
                }

            return ans;
        }
    }
}

void bld() {
    memset(cpar, -1, sizeof(cpar));
    decomp(0);
    memset(cdist, 0x3f, sizeof(cdist));
    ldfs(0, 0);
    rep(u, n) {
        for (int i = 0, v = u; ~v; v = cpar[v], i++)
            cdist[u][i] = dist(u, v);
    }
    rep(i, n) mdist[i] = {mp(-INF, -1), mp(-INF, -1)};
}

bool in[N];
int _add_elem[N];
int _add_sz;

void upd_arr(array<pii, 2> &a, const pii &x) {
    if (a[1] > x)
        return;
    else if (a[0] > x) {
        if (a[0].se != x.se)
            a[1] = x;
    } else {
        if (a[0].se != x.se)
            a[1] = a[0];

        a[0] = x;
    }
}

int get_not_eq(const array<pii, 2> &a, int x) {
    if (a[0].se != x)
        return a[0].fi;
    else
        return a[1].fi;
}

void mark(int u) {
    if (!in[u]) {
        in[u] = 1;
        _add_elem[_add_sz++] = u;
    }
}

void add(int u) {
    mark(u);
    upd_arr(mdist[u], mp(0, u));

    for (int i = 1, v = u; ~cpar[v]; v = cpar[v], i++) {
        upd_arr(mdist[cpar[v]], mp(cdist[u][i], v));
        mark(cpar[v]);
    }
}

void remove_all() {
    for (int i = _add_sz; ~i; i--) {
        in[_add_elem[i]] = 0;
        mdist[_add_elem[i]] = {mp(-INF, -1), mp(-INF, -1)};
    }

    _add_sz = 0;
}

int query(int u) {
    int ans = max(0, get_not_eq(mdist[u], u));

    for (int i = 1, v = u; ~cpar[v]; v = cpar[v], i++) {
        int x = get_not_eq(mdist[cpar[v]], v);
        if(x >= 0) ans = max(ans, max(x, cdist[u][i]));
    }

    return ans;
}

int d[N], v[N];
int cur;
vi adj2[N << 1];

void init_dsu() {
    memset(d, -1, sizeof(d));
    rep(i, n) v[i] = i;
    cur = n;
}

int find(int x) {
    return d[x] < 0 ? x : d[x] = find(d[x]);
}

int find_vert(int x) {
    return v[find(x)];
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y]; d[y] = x;
    adj2[cur].pb(v[x]); adj2[v[x]].pb(cur);
    adj2[cur].pb(v[y]); adj2[v[y]].pb(cur);
    v[x] = cur++;
}

int tin[N << 1], sz[N << 1], idx[N << 1];
int heavy[N << 1], heavy_size[N << 1];
int e[N], mx[N << 1];
vector<pii> qry[N << 1];
pii ans[N];

void dfs1(int u, int p = -1) {
    static int t = 0;
    sz[u] = 1;
    idx[t] = u;
    tin[u] = t++;

    for (auto& v : adj2[u])
        if (v != p) {
            dfs1(v, u);
            sz[u] += sz[v];
            mx[u] = max(mx[u], mx[v]);

            if (sz[v] > heavy_size[u]) {
                heavy_size[u] = sz[v];
                heavy[u] = v;
            }
        }
}

void dfs2(int u, int p = -1, bool del = 0) {
    for (auto& v : adj2[u])
        if (v != p && v != heavy[u])
            dfs2(v, u, 1);

    if (~heavy[u])
        dfs2(heavy[u], u, mx[heavy[u]] != mx[u]);

    for (auto& v : adj2[u])
        if (v != p && v != heavy[u]) {
            for (int i = tin[v]; i < tin[v] + sz[v]; i++)
                if(idx[i] < n && e[idx[i]] == mx[u])
                    add(idx[i]);
        }

    if(u < n && e[u] == mx[u])
        add(u);

    for(auto& [v, id]: qry[u]) {
        ans[id] = {mx[u], query(v)};
    }

    if (del)
        remove_all();
}


int32_t main() {
    fastio;
    int q; cin >> n >> q;
    rep(i, n) cin >> e[i], mx[i] = e[i];
    vector<tuple<int, int, int>> edges;
    rep(i, n - 1) {
        int u, v, c, t; cin >> u >> v >> c >> t; --u, --v;
        adj[u].eb(v, t);
        adj[v].eb(u, t);
        edges.eb(c, u, v);
    }
    vector<tuple<int, int, int>> queries(q);
    rep(i, q) {
        int x, v; cin >> x >> v; --v;
        queries[i] = {x, v, i};
    }
    sort(all(queries));
    sort(rall(edges));
    bld();
    init_dsu();
    for(auto& [c, u, v]: edges) {
        while(!queries.empty() && get<0>(queries.back()) > c) {
            auto [x, v, i] = queries.back();
            qry[find_vert(v)].eb(v, i);
            queries.pop_back();
        }
        join(u, v);
    }
    while(!queries.empty()) {
        auto [x, v, i] = queries.back();
        qry[find_vert(v)].eb(v, i);
        queries.pop_back();
    }
    memset(heavy, -1, sizeof(heavy));
    dfs1(cur - 1);
    dfs2(cur - 1);
    rep(i, q) cout << ans[i].fi << ' ' << ans[i].se << endl;
}