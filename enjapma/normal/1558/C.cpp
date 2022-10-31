#include <bits/stdc++.h>

using namespace std;

// using mint = long double;
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 3e18;
const ll fact_table = 3000050;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
// priority_queue<ll, vector<ll>, greater<ll>> pqls;
priority_queue<P, vector<P>, greater<P>> pqps;
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
    if (n < r) return 0ll;
    assert(n >= r);
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

bool icpc = false;
bool multicase = true;

// 
ll n, m;
vec x, op;

void ope(ll idx) {
    reverse(x.begin(), x.begin() + idx);
    op.pb(idx);
    return;
}

bool solve() {
    cin >> n;
    op.clear();
    x = rv(n);
    bool ok = true;
    rep(i, n) {
        if (x[i] % 2 == i % 2) ok = false;
    }

    if (!ok) {
        p(-1);
        return true;
    }

    for (int a = n; a >= 3; a -= 2) {
        int b = a - 1;
        // last 2  [b, a] 
        int apos = -1, bpos = -1;
        rep(j, n) {
            if (x[j] == a) apos = j;
            if (x[j] == b) bpos = j;
        }
        if (apos < bpos) {
            ope(apos + 1);
            ope(bpos);
            apos = bpos - 1;
            ope(a);
            apos = a - 1 - apos;
            ope(apos + 1);
            ope(a);
        } else {
            ope(apos + 1);
            bpos = apos - bpos;
            ope(bpos);
            apos = bpos - 1;
            ope(a);
            apos = a - 1 - apos;
            ope(apos + 1);
            ope(a);
        }
    }
    p(op.size());
    for (auto e : op) {
        pe(e);
    }
    el;
    return true;
}

/*







*/

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