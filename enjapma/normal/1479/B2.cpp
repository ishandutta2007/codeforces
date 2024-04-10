#include <bits/stdc++.h>
#include <numeric>
using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll> > Pd;

const ll INF = 1e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
// priority_queue <ll, vector<ll>, greater<ll> > pqls;
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

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec rv(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
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

ll n, m;
ll x[500005];

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[2 * k + 1] += lazy[k];
                lazy[2 * k + 2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        // [a, b)x
        assert(a < b);
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll find(int a, int b, int k = 0, int l = 0, int r = -1) {
        // [a, b) 
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    ll find_leftest(int a, int b, ll x) {
        // [a, b) xa-1
        return find_leftest_sub(a, b, x, 0, 0, n);
    }

    ll find_rightest(int a, int b, ll x) {
        return find_rightest_sub(a, b, x, 0, 0, n);
    }

    ll find_leftest_sub(int a, int b, ll x, int k, int l, int r) {
        eval(k, l, r);
        if (node[k] > x || r <= a || b <= l) {
            return a - 1;
        } else if (k >= n - 1) {
            return (k - (n - 1));
        } else {
            ll vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != a - 1) {
                return vl;
            } else {
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }

    ll find_rightest_sub(int a, int b, ll x, int k, int l, int r) {
        eval(k, l, r);
        if (node[k] > x || r <= a || b <= l) {
            return a - 1;
        } else if (k >= n - 1) {
            return (k - (n - 1));
        } else {
            ll vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {
                return vr;
            } else {
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
};

bool solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    vec v;
    v.pb(1);
    for (int i = 1; i <= n; i++) {
        v.pb(INF / 2ll);
    }
    v.pb(0);
    v.pb(0);
    v.pb(0);
    LazySegmentTree dp(v);

    for (int i = 2; i <= n; i++) {
        ll a = x[i - 1];
        ll c = x[i];

        ll dpa = dp.find(a, a + 1);
        ll dpc = dp.find(c, c + 1);

        if (a == c) {

            ll r = min(dpc, 1 + dp.find(0, n + 1));

            ll newdpa = min(dpa, r);

            ll now = dp.find(a, a + 1);

            ll dif = newdpa - now;

            dp.add(a, a + 1, dif);  
        } else {
            // dp  1 
            dp.add(0, n + 1, 1);

            ll r = min(dpc, dp.find(0, n + 1));

            ll newdpa = min(dpa, r);

            ll now = dp.find(a, a + 1);

            ll dif = newdpa - now;

            dp.add(a, a + 1, dif);
        }
    }

    ll ans = dp.find(0, n + 1);
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