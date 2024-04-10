#include <bits/stdc++.h>

using namespace std;

typedef string::const_iterator State;
class ParseError {};

// using mint = long double;
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;
typedef pair<ll, vector<ll>> Pd;

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

#define p(x) cout << x << endl;
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

// const ll mod = 1000000007ll;
const ll mod = 998244353ll;

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
    assert(n >= 0);
    assert(r >= 0);
    assert(n >= r);
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

bool icpc = false;
bool multicase = true;

// 
ll n;

ll query(ll l, ll r) {
    pe("?");
    pe(l);
    p(r);
    ll ans;
    cin >> ans;
    return ans;
}

bool solve() {
    cin >> n;
    ll ok = 1, ng = n;
    ll all = query(1, n);
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll ret = query(mid, n);
        if (ret == all) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    // ok 1
    ll ret2 = query(ok + 1, n);
    ll dec = all - ret2;
    // [ok, ok + dec]
    ll res = all - dec * (dec + 1) / 2;
    res *= 2ll;
    ll aim = sqrt(res);
    ll find = -1;
    for (ll i = -3; i <= 3; i++) {
        ll check = aim + i;
        if (check * (check + 1) == res) find = check + 1;
    }
    // [ok, ok + dec - 1]
    // [ok + dec, ok + dec + check - 1]
    pe("!");
    pe(ok);
    pe(ok + dec + 1);
    p(ok + dec + find);
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