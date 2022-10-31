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

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

//,,,

#define p(x) cout << x << '\n';
#define el cout << '\n';
#define pe(x) cout << x << " ";
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define pu(x) cout << (x);
#define pb push_back
#define eb emplace_back
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
bool multicase = true;

// 1. 
// 2. 
// 3. 
ll n, m, k, a, b, c, d;
ll h, w, q;

ll parent[500005], sizes[500005];
void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        parent[i] = i;
        sizes[i] = 1;
    }
}
ll find(ll x) {
    if (sizes[0] == 0) cerr << "init() is not called" << endl;
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}
void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    parent[y] = x;
    sizes[x] += sizes[y];
}
bool same(ll x, ll y) {
    return find(x) == find(y);
}
ll size(ll x) {
    return sizes[find(x)];
}

vector<P> G[200005];

bool solve() {
    cin >> n >> m;

    init(n + 10);

    rep(i, n) {
        G[i + 1].clear();
    }

    vector<tuple<ll, ll, ll>> unused;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        if (!same(a, b)) {
            // 
            unite(a, b);
            G[a].pb({b, i});
            G[b].pb({a, i});
        } else {
            unused.pb({a, b, i});
        }
    }

    vec v;
    for (auto [a, b, idx] : unused) {
        v.pb(a);
        v.pb(b);
    }
    sorti(v);

    rep(i, 6) {
        v.pb(-i - 1);
    }

    if (!(v[0] == v[1] && v[2] == v[3] && v[4] == v[5])) {
        // 
        string s(m, '0');
        for (auto [a, b, idx] : unused) {
            s[idx] = '1';
        }
        p(s);
    } else {
        // 
        assert(unused.size() == 3);
        string s(m, '0');

        auto [sv, tv, idx] = unused[0];

        for (int i = 1; i < 3; i++) {
            auto [a, b, idx] = unused[i];
            s[idx] = '1';
        }

        ll choice = -1;
        ll last_edge = -1;

        // s -> t 
        auto dfs = [&](auto self, int v, int p) -> void {
            dump(v);
            if (v == tv) {
                choice = last_edge;
                return;
            }
            for (auto [nv, idx] : G[v]) {
                if (nv == p) continue;
                last_edge = idx;
                self(self, nv, v);
            }
        };

        dfs(dfs, sv, -1);
        assert(choice != -1);

        s[choice] = '1';
        p(s);
    }

    return true;
}
/*







*/

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#else
    cerr << "[LOCAL] mod = " << mod << endl;
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