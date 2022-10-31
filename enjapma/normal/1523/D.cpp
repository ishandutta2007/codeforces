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
const ll fact_table = 820000;

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

#define p(x) cout << x << "\n";
#define el cout << "\n";
#define pe(x) cout << x << " ";
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define pu(x) cout << (x);
#define pb push_back
#define eb emplace_back
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

ll n, m, k;
string s[200005];

struct RandomNumberGenerator {
    mt19937 mt;

    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {
    }

    int operator()(int a, int b) { // [a, b)
        uniform_int_distribution<int> dist(a, b - 1);
        return dist(mt);
    }

    int operator()(int b) { // [0, b)
        return (*this)(0, b);
    }
};

ll range(ll a, ll b) {
    // [a, b] 
    ll num = rand() % (1 + b - a) + a;
    return num;
}

bool solve() {
    cin >> n >> m >> k;
    rep(i, n) {
        cin >> s[i];
    }
    ll ans = 0;
    string anss(m, '0');
    RandomNumberGenerator ransuu;
    rep(_, 36) {
        ll hito = ransuu(n);

        vec idx;
        for (int i = 0; i < m; i++) {
            if (s[hito][i] == '1') idx.pb(i);
        }

        vec dp((1ll << (idx.size())), 0);

        // idx := 
        for (int i = 0; i < n; i++) {
            ll num = 0;
            for (int j = 0; j < idx.size(); j++) {
                if (s[i][idx[j]] == '1') {
                    num += (1ll << j);
                }
            }
            dp[num]++;
        }
        for (int i = 0; i < idx.size(); i++) {
            for (ll bit = 0; bit < (1ll << idx.size()); bit++) {
                if (!((bit >> i) & 1)) {
                    dp[bit] += dp[bit ^ (1ll << i)];
                }
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] >= (n + 1) / 2) {
                if (ans < __builtin_popcount(i)) {
                    ans = __builtin_popcount(i);
                    anss = string(m, '0');
                    for (int j = 0; j < idx.size(); j++) {
                        if ((i >> j) & 1) {
                            anss[idx[j]] = '1';
                        }
                    }
                }
            }
        }
    }
    p(anss);
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