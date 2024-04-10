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
ll idx[10];

// 

bool solve() {
    ll n;
    cin >> n;
    string s[5];
    rep(i, 3) {
        cin >> s[i];
        idx[i] = 0;
    }

    for (int i = 0; i < 3 * n; i++) {
        ll zero = 0, one = 0;
        ll cnt = 0;
        rep(j, 3) {
            if (idx[j] == 2 * n) {
                cnt++;
                continue;
            }
            if (s[j][idx[j]] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (cnt == 1) {
            ll c = -1, maxi = -INF;
            rep(j, 3) {
                if (maxi < idx[j] && idx[j] != 2 * n) {
                    c = j;
                    maxi = idx[j];
                }
            }
            pu(s[c][idx[c]]);
            idx[c]++;
            continue;
        } else if (cnt >= 2) {
            pu(0);
            continue;
        }
        bool choice_zero = (zero >= one);
        rep(j, 3) {
            if (s[j][idx[j]] == '0' && choice_zero) {
                idx[j]++;
            } else if (s[j][idx[j]] == '1' && !choice_zero) {
                idx[j]++;
            }
        }
        if (choice_zero) {
            pu(0);
        } else {
            pu(1);
        }
    }
    cout << endl;

    return true;
}

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