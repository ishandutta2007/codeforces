#include <bits/stdc++.h>
using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 1e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)
#define rep2(i, a, b) for (ll i = a; i <= (b); i++)
#define rep3(i, a, b) for (ll i = a; i >= (b); i--)

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec readvec(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

ll mygcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0 || a == b) return b;
    return mygcd(b % a, a);
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
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/

bool icpc = false;
bool multicase = false;

ll n, m, k, a, b;
string s;

ll x[100005], y[100005];

bool solve() {
    cin >> s;
    cin >> a >> b;
    n = s.size();
    ll all0 = 0, all1 = 0;
    ll base = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            all0 ++;
            base += all1 * b;
        }
        if (s[i] == '1') {
            all1 ++;
            base += all0 * a;
        }
    }
    ll now0 = 0, now1 = 0;
    ll res = 0;
    vec v;

    ll idx = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            ll cost0 = now1 * b + (all1 - now1) * a;
            ll cost1 = now0 * a + (all0 - now0) * b;
            res += cost0;
            x[idx] = cost0, y[idx] = cost1;
            idx ++;
        } else if (s[i] == '1') {
            now1 ++;
        } else {
            now0 ++;
        }
    }
    ll m = idx;
    ll ans = res;
    for (int i = 0; i < m; i++) {
        res -= x[i];
        res += y[i];
        res -= i * b;
        res += (m - 1 - i) * b;
        ans = min(ans, res);
    }
    for (int i = 0; i < m; i++) {
        res -= y[i];
        res += x[i];
        res -= i * a;
        res += (m - 1 - i) * a;
        ans = min(ans, res);
    }
    ans += base;
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