#include <bits/stdc++.h>

using namespace std;

typedef string::const_iterator State;
class ParseError {};

// using mint = ll;
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;

const ll INF = 3e18;
const ll fact_table = 8000005;

/*
priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
// priority_queue<ll, vector<ll>, greater<ll>> pqls;
priority_queue<P, vector<P>, greater<P>> pqps;
// small priority queue
// top pop
*/

// ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
// ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//,,,

#define p(x) cout << x << '\n';
#define el cout << '\n';
#define pe(x) cout << x << " ";
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define pu(x) cout << (x);
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = a; i <= (b); i++)
#define rep3(i, a, b) for (ll i = a; i >= (b); i--)
#define all(c) begin(c), end(c)
#define sorti(v) sort(all(v))
#define sortd(v)                                                                                   \
    sort(all(v));                                                                                  \
    reverse(all(v));
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#ifdef LOCAL
#define dump(var) cerr << #var "= " << var << endl
#else
#define dump(var)
#pragma GCC optimize("O3")
#endif

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {
    ll x = 1ll;
    while (b) {
        while (!(b & 1ll)) {
            (a *= a) %= m;
            b >>= 1ll;
        }
        (x *= a) %= m;
        b--;
    }
    return x;
}
vec rv(ll read) {
    vec res(read);
    for (int i = 0; i < read; i++) {
        cin >> res[i];
    }
    return res;
}

vec fact, rfact;

void c3_init() {
    fact.resize(fact_table + 5);
    rfact.resize(fact_table + 5);
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
    if (fact.size() == 0) {
        c3_init();
    }
    if (n < 0) return 0ll;
    if (r < 0) return 0ll;
    if (n < r) return 0ll;
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

bool icpc = false;
bool multicase = false;

// 1. 
// 2. 
// 3. 
ll n, m, k;

vector<P> G[200005];
ll depth[200005];
P par[200005];
ll v[200005], vr[200005];
ll edge_cost[200005];

vec v_to_e[200005];
vec e_to_v[200005];

vector<P> input_edges;

void dfs(int v, int d, int p = -1) {
    depth[v] = d;
    for (auto [nv, edge] : G[v]) {
        if (depth[nv] != 0) continue;
        par[nv] = {v, edge};
        dfs(nv, d + 1, v);
    }
    return;
}

vec route_edges(int a, int b) {
    vec ra, rb;
    // a -> b 

    int va = a, vb = b;

    while (depth[va] != depth[vb]) {
        if (depth[va] > depth[vb]) {
            auto [p, edge] = par[va];
            ra.push_back(edge);
            va = p;
        }
        if (depth[va] < depth[vb]) {
            auto [p, edge] = par[vb];
            rb.push_back(edge);
            vb = p;
        }
    }

    while (va != vb) {
        auto [pa, edge_a] = par[va];
        auto [pb, edge_b] = par[vb];

        ra.push_back(edge_a);
        rb.push_back(edge_b);

        va = pa;
        vb = pb;
    }

    reverse(all(rb));

    for (auto e : rb) {
        ra.push_back(e);
    }
    return ra;
}

bool solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        vr[v[i]] = i;
    }

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        G[a].pb({b, i});
        G[b].pb({a, i});

        input_edges.push_back({a, b});
    }

    for (int i = 1; i <= n; i++) {
        if (depth[i] == 0) {
            dfs(i, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        auto [v, e] = par[i];
    }

    for (int i = 1; i <= n; i++) {
        int a = vr[i];
        int b = i;

        // a -> b 

        vec edges = route_edges(a, b);

        reverse(all(edges));

        // 

        for (int i = 0; i + 1 < edges.size(); i++) {
            edge_cost[edges[i]]++;
        }

        v_to_e[a] = edges;
        if (edges.size()) e_to_v[edges.back()].push_back(a);
    }

    vec can_use_edges;

    for (int i = 0; i < m; i++) {
        if (edge_cost[i] == 0) can_use_edges.push_back(i);
    }

    vec ans;

    while (can_use_edges.size()) {

        auto e = can_use_edges.back();
        can_use_edges.pop_back();

        //  e 
        for (auto v : e_to_v[e]) {
            v_to_e[v].pop_back();

            if (v_to_e[v].size()) {
                auto ne = v_to_e[v].back();

                edge_cost[ne]--;
                e_to_v[ne].push_back(v);

                if (edge_cost[ne] == 0) {
                    can_use_edges.push_back(ne);
                }
            }
        }

        e_to_v[e].clear();
        ans.push_back(e + 1);
    }

    for (auto e : ans) {
        p(e);
    }

    for (auto ai : ans) {
        auto [a, b] = input_edges[ai - 1];
        swap(v[a], v[b]);
    }

    for (int i = 1; i <= n; i++) {
        assert(i == v[i]);
    }

    return true;
}

/*







*/

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    if (icpc) {
        while (solve())
            ;
        return 0;
    }
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // cout << "Case #" << testcase << ": ";
        solve();
        testcase++;
    }

    // solve();
    return 0;
}