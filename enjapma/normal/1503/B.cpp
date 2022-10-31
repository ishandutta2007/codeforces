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
const ll fact_table = 1200008;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
// priority_queue <ll, vector<ll>, greater<ll> > pqls;
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

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

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

ll n, k;
string s;

void answer(ll b, ll i, ll j) {
    pe(b);
    pe(i);
    p(j);
    return;
}

ll one = 0, two = 0, three = 0;

bool solve() {
    cin >> n;

    ll maxone = (n * n + 1) / 2;
    ll maxtwo = (n * n) / 2;

    ll x1 = 1, y1 = 1, x2 = 1, y2 = 2;
    ll cnt = 0;

    while (true) {
        ll a;
        cin >> a;
        cnt++;
        if (one == maxone || two == maxtwo) {
            if (one == maxone) {
                // 1 2 or 3 
                ll num = (a == 2) ? 3 : 2;
                answer(num, x2, y2);
                y2 += 2;
                if (y2 > n) {
                    x2++;
                    y2 = (x2 % 2 == 0) ? 1 : 2;
                }
            } else {
                // 2
                ll num = (a == 1) ? 3 : 1;
                answer(num, x1, y1);
                y1 += 2;
                if (y1 > n) {
                    x1++;
                    y1 = (x1 % 2 == 0) ? 2 : 1;
                }
            }
        } else {
            if (a != 1) {
                // 1 
                answer(1, x1, y1);
                one++;

                y1 += 2;
                if (y1 > n) {
                    x1++;
                    y1 = (x1 % 2 == 0) ? 2 : 1;
                }
            } else {
                // 2 
                answer(2, x2, y2);
                two++;

                y2 += 2;
                if (y2 > n) {
                    x2++;
                    y2 = (x2 % 2 == 0) ? 1 : 2;
                }
            }
        }
        if (cnt == n * n) break;
    }

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
        solve();
        testcase++;
    }

    // solve();
    return 0;
}