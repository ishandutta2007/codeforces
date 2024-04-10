#include <bits/stdc++.h>

using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 3e18;
const ll fact_table = 3200000;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
priority_queue<ll, vector<ll>, greater<ll>> pqls;
// priority_queue<P, vector<P>, greater<P>> pqps;

// small priority queue
// top pop

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

const ll mod = 1000000007ll;
// const ll mod = 998244353ll;

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
    assert(n >= r);
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

bool icpc = false;
bool multicase = false;

ll n;
ll times = 0;
bool ok[2005];

vec query(int r) {
    times++;
    assert(times <= (n + 1) / 2);
    pe("?");
    p(r);
    return rv(n);
}

bool solve() {
    cin >> n;
    assert(n <= 2000);
    auto depth = query(1);
    int r = 1;
    vector<P> edges;
    for (int i = 0; i < n; i++) {
        // 1
        if (depth[i] == 1) {
            ok[i] = true;
            edges.pb(P(i + 1, 1));
        }
    }
    ll cnt = 0;
    for (int d = 1;; d += 1) {
        for (int i = 0; i < n; i++) {
            if (depth[i] == d + 1 && !ok[i]) {
                cnt++;
                // assert(cnt <= n);
                vec res = query(i + 1);
                ll r = -1;
                vec douryo;
                for (int j = 0; j < n; j++) {
                    if (res[j] == 1 && depth[j] == d + 2) {
                        // 
                        assert(!ok[j]);
                        ok[j] = true;
                        edges.pb(P(j + 1, i + 1));
                    } else if (res[j] == 1 && depth[j] == d) {
                        // 
                        assert(!ok[i]);
                        ok[i] = true;
                        edges.pb(P(j + 1, i + 1));
                        r = j;
                    } else if (res[j] == 2 && depth[j] == d + 1) {
                        // 
                        douryo.pb(j);
                        assert(!ok[j]);
                        ok[j] = true;
                    }
                }
                assert(r != -1);
                for (auto e : douryo) {
                    edges.pb(P(e + 1, r + 1));
                }
            }
        }
        assert(edges.size() <= n - 1);
        if (edges.size() == n - 1) break;
    }
    p("!");
    for (auto [l, r] : edges) {
        cout << l << " " << r << "\n";
    }
    el;
    return true;
}
/*







*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
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