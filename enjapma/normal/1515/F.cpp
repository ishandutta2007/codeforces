#include <bits/stdc++.h>

using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 1e18;
const ll fact_table = 5000;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
priority_queue<ll, vector<ll>, greater<ll>> pqls;
priority_queue<P, vector<P>, greater<P>> pqps;
// small priority queue
// top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/

#define p(x) cout << x << "\n";
#define el cout << endl;
#define pe(x) cout << x << " ";
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define pu(x) cout << (x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = a; i <= (b); i++)
#define rep3(i, a, b) for (ll i = a; i >= (b); i--)
#define all(c) begin(c), end(c)
#define sorti(v) sort(all(v))
#define sortd(v)                                                               \
    sort(all(v));                                                              \
    reverse(all(v));
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

// const ll mod = 998244353ll;
ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {
    ll x = 1;
    while (b) {
        while (!(b & 1)) {
            (a *= a) %= m;
            b >>= 1;
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
    return (((fact[n] * rfact[r]) % mod) * rfact[n - r]) % mod;
}
*/

bool icpc = false;
bool multicase = false;

ll n, m, k, q, x;

vec ans;
vector<P> G[300005];
vector<P> eraseset;
vec a;

ll parent[300105], sizes[300105];
void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        parent[i] = i;
    }
}
ll find(ll x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}
bool same(ll x, ll y) {
    return find(x) == find(y);
}
void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (G[x].size() < G[y].size()) swap(x, y);
    parent[y] = x;
    for (auto [v, edge] : G[y]) {
        if (v != x) G[x].pb(P(v, edge));
    }
    sizes[x] += sizes[y];
    G[y].clear();
}

ll size(ll x) {
    return sizes[find(x)];
}

bool solve() {
    cin >> n >> m >> x;
    init(n + 10);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= x;
        sizes[i] += a[i];
    }
    ll sum = SUM(a);
    if (sum < -x) {
        p("NO");
        return true;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(P(b, i));
        G[b].pb(P(a, i));
    }
    set<P> pq;
    rep(i, n) {
        pq.insert(P(a[i], i));
    }
    vector<ll> ans;
    while (true) {
        auto [w, v] = *pq.rbegin();
        eraseset.clear();
        for (int i = G[v].size() - 1; i >= 0; i--) {
            auto [u, edge] = G[v][i];
            if (same(u, v)) {
                G[v].pop_back();
                continue;
            }
            pq.erase(P(size(u), find(u)));
            pq.erase(P(size(v), find(v)));
            unite(u, v);
            ans.pb(edge);
            pq.insert(P(size(find(u)), find(u)));
            break;
        }
        if (ans.size() == n - 1) break;
    }
    assert(ans.size() == n - 1);
    p("YES");
    for (auto e : ans) {
        p(e + 1);
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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