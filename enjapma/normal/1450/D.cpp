#include <bits/stdc++.h>

using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 2e18;
const ll fact_table = 3200008ll;

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
void print(int n) {
    rep2(i, 1, 30) {
        rep2(j, 1, i) {
            ll res = i * mypow(j, mod - 2, mod); res %= mod;
            if (res == n) {pe(j); pe("bunnno"); p(i); return;}
        }
    }
}

ll mul(ll a, ll b) { if (b == 0) { return 0ll; } else { if (INF / b < a) { return INF; } else { return a * b;}}}

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
bool multicase = true;

ll n, m, k, q;
ll x[300005];
ll cnt[300005];

string ans;

void atohadame() {
    ll k = ans.size();
    ans += string(n - k, '0');
    return;
}

void dfs(ll m, ll l, ll r) {
    if (cnt[m] > 1) {
        ans += '1';
        atohadame();
        return;
    } else if (cnt[m] == 0) {
        atohadame();
        return;
    } else if (x[l] != m && x[r] != m) {
        ans += '1';
        atohadame();
        return;
    } else {
        ans += '1';
        if (x[l] == m) {
            dfs(m + 1, l + 1, r);
        } else {
            dfs(m + 1, l, r - 1);
        }
    }
}

bool solve() {
    cin >> n;
    for (int i = 1; i <= n + 10; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cnt[x[i]] ++;
    }
    ans = "";

    dfs(1, 0, n - 1);
    reverse(ans.begin(), ans.end());
    bool dame = false;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 1) dame = true;
    }
    if (!dame) ans[0] = '1';
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