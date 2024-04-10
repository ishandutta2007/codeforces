#include <bits/stdc++.h>
#include <cctype>


using namespace std;

typedef string::const_iterator State;
class ParseError {};

// using mint = long long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
//small priority queue
//top pop

ll dx[4] = {2, 2, -2, -2};
ll dy[4] = {1, -1, 1, -1};
//,,,

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, a, b) for (ll i = a; i <= (ll)(b); ++i)
#define rep3(i, a, b) for (ll i = a; i >= (ll)(b); --i)

typedef vector<ll> vec;

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec rv(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}
ll mul(ll a, ll b) { if (b == 0) return 0; if (a > INF / b) return INF; return a * b;}
ll mygcd(ll a, ll b) { if (b == 0 || a == b) return a; return mygcd(b, a % b);}

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
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/

bool icpc = false;
bool multicase = false;

ll n, m, offset;
string s , t;

ll dp[100005], dpsum[100005], dpidx[100005];

vector<ll> base_table = {128ll, 243ll, 125ll,
                         1340132568ll, 1025585316ll, 216ll
                        };
vector<ll> mod_table =  {2000000011ll, 2000000033ll, 2000000063ll,
                         2147467057ll, 2147483353ll, 3000001811ll
                        };

struct LLRollingHash {
// long long RollingHash
public:
    ll n;
    ll base;
    ll mod;
    vector<ll> hash_table;
    vector<ll> base_pow;

    void initialize(vector<ll> v, int idx) {
        n = v.size();
        base = base_table[idx];
        mod = mod_table[idx];
        hash_table.resize(n + 1, 0ll);
        base_pow.resize(n + 1, 1ll);
        ll tmp = 0;
        for (ll i = 0; i < n; i++) {
            assert(v[i] >= 0);
            tmp = tmp * base + v[i];
            tmp %= mod;
            hash_table[i + 1] = tmp;
        }
        for (ll i = 0; i < n; i++) {
            base_pow[i + 1] = (base_pow[i] * base) % mod;
        }
    }

    LLRollingHash(vector<ll> v, int idx) {
        initialize(v, idx);
    }

    LLRollingHash(string s, int idx){
        vector<ll> v;
        for(int i=0;i<s.size();i++){
            v.pb(s[i] - 'a');
        }
        initialize(v, idx);
    }



    ll hash(ll idx, ll len) {
        // idxnHash
        if (len == 0)return 0ll;
        assert(idx + len <= n);
        ll modpow = mod - base_pow[len];
        ll hash = (hash_table[len + idx] + (hash_table[idx] * modpow) % mod) % mod;
        return hash;
    }

    void add(ll val) {
        n++;
        ll tmp = hash_table.back() * base + val;
        tmp %= mod;
        hash_table.pb(tmp);
        base_pow.pb((base_pow.back() * base) % mod);
        return;
    }
};

bool solve() {
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    LLRollingHash hs = LLRollingHash(s, 1);
    LLRollingHash ht = LLRollingHash(t, 1);
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        dpsum[i] = 0;
        dpidx[i] = -1;
    }
    ll ans = 0;
    for (int i = m; i <= n; i++) {
        if (hs.hash(i - m, m) == ht.hash(0, m)) {
            ll res = dpsum[i - m] + i - m + 1;
            res += mod;
            dp[i] = dp[i - 1] + res;
            dp[i] %= mod;

            dpidx[i] = i;
            dpsum[i] = dpsum[i - 1] + dp[i];
            dpsum[i] %= mod;
        } else {
            dpidx[i] = dpidx[i - 1];

            if (dpidx[i] == -1) continue;

            dp[i] = dp[dpidx[i]] + (mod - dp[dpidx[i] - 1]) + dp[i - 1];
            dp[i] %= mod;
            dpsum[i] = dpsum[i - 1] + dp[i];
            dpsum[i] %= mod;
        }
    }
    ans = dp[n];
    p(ans);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (icpc) {
        while (solve());
        return 0;
    }
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }

// solve();
    return 0;
}