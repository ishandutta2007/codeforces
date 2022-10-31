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
// priority_queue <ll, vector<ll>, greater<ll> > pqls;
// priority_queue <P, vector<P>, greater<P> > pqps;
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
bool multicase = false;

ll n, m, k;
ll l, r;
ll a, b, c, d;

ll parent[1000005], sizes[1000005];
set<ll> st[1000005];
bool used[500005];
int have[500005];

void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        sizes[i] = 1;
        parent[i] = i;
    }
}
ll find(ll x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    if (sizes[x] < sizes[y])swap(x, y);

    parent[y] = x;
    sizes[x] += sizes[y];
    have[x] += have[y];
    used[x] |= used[y];
    for (auto e : st[y]) {
        st[x].insert(e);
    }
}

bool same(ll x, ll y) {
    return find(x) == find(y);
}

ll size(ll x) {
    return sizes[find(x)];
}

bool solve() {
    cin >> n >> m;
    init(m + 10);
    set<int> use;
    for (int i=0;i<n;i++) {
        cin >> k;
        if (k == 1) {
            cin >> a;
            if (!used[find(a)] && have[find(a)] < size(a)) {
                use.insert(i);
                have[find(a)] ++;
            }
        } else {
            cin >> a >> b;
            if (!same(a, b) && (have[find(a)] < size(a) || have[find(b)] < size(b))) {
                unite(a, b);
                use.insert(i);
                have[find(a)] ++;
            }
        }
    }
    pe(mypow(2, use.size(), mod));
    p(use.size());
    for (auto e : use) {
        pe(e + 1);
    }
    el;
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