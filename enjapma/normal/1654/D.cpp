#include <bits/stdc++.h>
#include <sys/time.h>

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
const ll fact_table = 8000050;

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

#define p(x) cout << x << "\n";
#define el cout << "\n";
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
#define dump(var) cout << #var "= " << var << endl
#else
#define dump(var)
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
        cout << "c3_init() is not called." << endl;
        exit(1);
    }
    if (n < 0) return 0ll;
    if (r < 0) return 0ll;
    if (n < r) return 0ll;
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

bool icpc = false;
bool multicase = true;

// 
ll n, m, k;
vector<tuple<ll, ll, ll>> G[200005];

ll xs[200005];
unordered_map<ll, ll> mp;
unordered_map<ll, ll> mp_min;
map<ll, vector<P>> cache;

vector<P> factorize(ll n) {
    vector<P> ret;
    ll in = n;
    if (cache[n].size() > 0) {
        return cache[n];
    }
    for (int i = 2; i * i <= n; i++) {
        ll cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) ret.pb({i, cnt});
    }
    if (n > 1) ret.pb({n, 1});
    if (in <= 1000) cache[in] = ret;
    return ret;
}

void mul(ll x, ll y) {
    // x y
    auto r1 = factorize(x);
    auto r2 = factorize(y);

    for (auto [p, cnt] : r1) {
        mp[p] += cnt;
    }
    for (auto [p, cnt] : r2) {
        mp[p] -= cnt;
        mp_min[p] = min(mp_min[p], mp[p]);
    }
    return;
}

void dfs_1(int v, int p = -1) {
    for (auto [nv, x, y] : G[v]) {
        if (nv == p) continue;
        mul(y, x);
        dfs_1(nv, v);
        mul(x, y);
    }
    return;
}

void dfs_2(int v, int p = -1) {
    for (auto [nv, x, y] : G[v]) {
        if (nv == p) continue;
        ll nval = xs[v] * y % mod * mypow(x, mod - 2) % mod;
        xs[nv] = nval;
        dfs_2(nv, v);
    }
    return;
}

bool solve() {
    cin >> n;
    mp.clear();
    mp_min.clear();
    rep(i, n + 1) {
        G[i].clear();
    }
    rep(i, n - 1) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        ll r = gcd(x, y);
        x /= r;
        y /= r;
        G[a].pb({b, x, y});
        G[b].pb({a, y, x});
    }

    dfs_1(1);

    ll sum = 1ll;
    for (auto [p, cnt] : mp_min) {
        if (cnt < 0) {
            sum *= mypow(p, -cnt);
            sum %= mod;
        }
    }
    xs[1] = 1;
    dfs_2(1);

    ll sum2 = 0ll;
    for (int i = 1; i <= n; i++) {
        sum2 += xs[i];
        sum2 %= mod;
    }

    p(sum2 * sum % mod);
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