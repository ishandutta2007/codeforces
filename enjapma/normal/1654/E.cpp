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
bool multicase = false;

// 
ll n, m, k;
ll x[100005];
int checks[40000005];
int mp[40000005];
ll ans = 0;
int check_cnt = 0;

void check(ll c, ll &ans) {
    //  c 
    int hit = 0;
    for (int i = 1; i <= n; i++) {
        ll val = x[i] + c * i + 20000000;
        if (checks[val] < check_cnt) {
            mp[val] = 0;
            checks[val] = check_cnt;
        }
        hit = max(hit, ++mp[val]);

        // if (n - (hit + n - i) > ans) return;
    }
    check_cnt++;

    ans = min(ans, n - hit);
    return;
}

void check(int l, int r, int diff, ll &ans) {
    int hit = 2;
    ll val = x[l] + diff;
    for (int i = l + 1; i < r; i++) {
        if (val == x[i]) hit++;
        val += diff;
    }
    ans = min(ans, n - hit);
    return;
}

// n * A * A + n * B
const ll A = 500;
const ll B = (100000 + A - 1) / A;

bool solve() {
    cin >> n;
    if (n == 1) {
        p(0);
        return true;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    // OK
    ans = n - 2;

    for (int l = 1; l <= n; l++) {
        int rmax = min(n, l + A);
        for (int r = l + 2; r <= rmax; r++) {
            assert(r - l > 0);
            if ((x[r] - x[l]) % (r - l) != 0) continue;

            int diff = (x[r] - x[l]) / (r - l);

            if (abs(diff) > B) {
                check(l, r, diff, ans);
            }
        }
    }
    for (int i = -B; i <= B; i++) {
        check(i, ans);
    }

    p(ans);
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