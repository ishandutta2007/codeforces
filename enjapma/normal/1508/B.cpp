#include <bits/stdc++.h>
#include <numeric>

using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 4e18;
const ll fact_table = 3200008;

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

#define p(x) cout << x << endl;
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

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

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
bool multicase = true;

// 

ll mul(ll a, ll b) {
    // a * b > INF ?
    if (b == 0) {
        return 0ll;
    } else if (a > INF / b) {
        return INF;
    } else {
        return a * b;
    }
}

ll n, k;
ll pow2[200005];
vector<ll> ans;
bool dame = false;

void myprint(ll maxi, ll mini) {
    for (int i = maxi; i >= mini; i--) {
        ans.pb(i);
    }
    return;
}

void calc(ll n, ll k, ll mini, ll maxi) {
    if (n == 0) return;
    if (dame) return;

    for (ll use = mini; use <= maxi; use++) {
        //  use 
        ll len = n - (use - mini + 1);
        ll cnt = pow2[len];
        if (cnt >= k) {
            myprint(use, mini);
            calc(len, k, use + 1, maxi);
            return;
        } else {
            k -= pow2[len];
        }
    }
    dame = true;
    return;
}

bool solve() {
    cin >> n >> k;
    dame = false;
    ans.clear();
    calc(n, k, 1, n);
    if (dame) {
        p(-1);
        return true;
    }
    for (auto e : ans) {
        pe(e);
    }
    el;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pow2[0] = 1, pow2[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        pow2[i] = mul(2ll, pow2[i - 1]);
    }
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