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

ll n, m, k;
ll l[2005], r[2005], c[2005];
ll dp[3][60006];

const ll offset = 2000;

void sum(ll l, ll r, ll start, ll d) {
    dp[1][l + offset] += start;
    dp[1][r + 1 + offset] -= start + (r - l) * d;
    dp[0][l + 1 + offset] += d;
    dp[0][r + 1 + offset] -= d;
}

bool solve() {
    cin >> n >> m >> k;
    rep(i, m) {
        cin >> l[i] >> r[i];
    }
    ll ans = -INF;
    for (ll l1 = 1; l1 <= n - k + 1; l1 ++) {
        ll base = 0;
        for (int i = 0; i < 6000; i++) {
            dp[0][i] = dp[1][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            c[i] = max(0ll, min(l1 + k - 1, r[i]) - max(l1, l[i]) + 1);

            base += c[i];
            if (k >= r[i] - l[i] + 1) {
                // 
                sum(l[i] - k + c[i], l[i], 0, 1);
                sum(l[i] + 1, r[i] - k, k - c[i], 0);
                sum(r[i] - k + 1, r[i] + 1 - c[i], k - c[i], -1);

            } else {
                // 
                sum(l[i] - k + c[i], r[i] - k + 1, 0, 1);
                sum(r[i] - k + 2, l[i] - 1, r[i] - l[i] + 1 - c[i], 0);
                sum(l[i], r[i] + 1 - c[i], r[i] - l[i] + 1 - c[i], -1);
            }
        }

        for (int i = 1; i < 6000; i++) {
            dp[0][i] = dp[0][i - 1] + dp[0][i];
        }
        for (int i = 1; i < 6000; i++) {
            dp[1][i] = dp[1][i - 1] + dp[0][i];
        }
        ll maxi = -INF;
        for (int i = 0; i < 6000; i++) {
            maxi = max(maxi, dp[1][i]);
        }
        ans = max(ans, base + maxi);
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