
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
ll n, m, k, a, b;
ll h, w;

ll x[200005], p[200005];

bool solve() {
    cin >> n >> m;

    vector<P> v;

    rep(i, n) {
        cin >> p[i] >> x[i];
        v.pb({p[i], 1});
        v.pb({p[i] - x[i], 0});
        v.pb({p[i] + x[i], 2});
    }

    sorti(v);

    ll sum = 0;
    ll acc = 0;
    ll pos = 0;

    vector<P> info;

    for (auto [pos_i, val_i] : v) {
        sum += acc * (pos_i - pos);
        pos = pos_i;

        // (pos, sum)
        if (val_i == 1 && sum > m) {
            info.pb({pos, sum - m});
        }

        if (val_i == 0) {
            acc++;
        } else if (val_i == 1) {
            acc -= 2;
        } else if (val_i == 2) {
            acc++;
        }
    }

    // info 
    // ()
    // 

    double place = 0;
    double value = -1e18;

    while (info.size()) {
        auto [place_n, value_n] = info.back();
        info.pop_back();

        double place_2 = (double)place_n;
        double value_2 = (double)value_n;

        // (place, value) + (place_2, value_2)
        double place_m, value_m;

        if (abs(place - place_2) <= abs(value - value_2)) {
            // 
            if (value > value_2) {
                place_m = place;
                value_m = value;
            } else {
                place_m = place_2;
                value_m = value_2;
            }
        } else {
            double len = abs(place - place_2) - abs(value - value_2);

            if (value < value_2) {
                swap(value, value_2);
                swap(place, place_2);
            }

            if (place <= place_2) {
                place_m = place + len / 2.0;
                value_m = value + len / 2.0;
            } else {
                place_m = place - len / 2.0;
                value_m = value + len / 2.0;
            }
        }

        place = place_m;
        value = value_m;
    }

    string s(n, '0');

    rep(i, n) {
        if ((double)x[i] >= value + abs((double)p[i] - place)) {
            s[i] = '1';
        }
    }

    p(s);

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