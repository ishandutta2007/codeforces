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

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

//,,,

#define p(x) cout << x << endl;
#define el cout << endl;
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

// 
ll n, m, k, l;

bool solve() {

    ll a = 1, b = (1ll << 30) + 1;

    auto query = [](ll a, ll b) {
        assert(a <= 2000000000);
        assert(b <= 2000000000);
        cout << "? " << a << " " << b << endl;
        cout.flush();
        ll ret;
        cin >> ret;
        for (int i = 0; i < 31; i++) {
            if ((ret >> i) & 1ll) {
                return i;
            }
        }
    };
    vec v;
    ll beforebit = -1;
    ll cnt = 0;
    while (true) {
        ll ret = query(a, b);
        if (beforebit == -1) {
            for (int i = 0; i < ret; i++) {
                v.pb(0);
            }
            v.pb(1);
        } else {
            for (int i = beforebit + 1; i < ret; i++) {
                v.pb(1);
            }
            v.pb(0);
        }
        beforebit = ret;
        a += (1ll << ret);
        b += (1ll << ret);
        cnt++;
        if (v.size() >= 30) break;
        assert(cnt <= 40);
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) ans += (1ll << i);
    }
    cout << "! " << ans - 1 << endl;
    cout.flush();

    // assert(ans - 1 == x);

    return true;
}

/*







*/

int main() {
#ifndef LOCAL
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