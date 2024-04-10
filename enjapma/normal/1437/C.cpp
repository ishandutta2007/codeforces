#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unistd.h>
#include <stdlib.h>
#include <cassert>

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

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec readvec(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

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
bool multicase = true;

ll n, m;
ll dp[226][326];
ll x[225], y[225];

ll cost(ll i, ll l, ll r) {
    // pe(i);pe(l);p(r);
    ll num = y[i];
    ll time = i;
    if (num == 0) return 0;
    if (r - l + 1 != num) {
        return INF;
    }
    ll res;
    if (l <= time && time <= r) {
        ll n1 = time - l;
        ll n2 = r - time;
        res = n1 * (n1 + 1) / 2 + n2 * (n2 + 1) / 2;
    } else {
        ll n1 = abs(time - l), n2 = abs(time - r);
        res =  (n1 + n2) * num / 2;
    }
    // p(res);
    return res;
}

bool solve() {
    cin >> n;
    ll m = n * 3 / 2 + 10;
    rep2(i, 1, n + 10) {
        y[i] = 0;
    }
    rep2(i, 1, n) {
        cin >> x[i];
        y[x[i]] ++;
    }
    rep2(i, 1, n + 10) {
        rep2(j, 0, m) {
            dp[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (y[i] == 0) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        for (int j = 0; j <= m; j++) {
            int len = y[i];
                if (j >= len) dp[i][j] = min(dp[i][j], dp[i - 1][j - len] + cost(i, j - len + 1, j));
                if (j >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 20; j++) {
            pe(dp[i][j]);
        }
        el;
    }
    */
    ll ans = INF;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dp[n][i]);
    }
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