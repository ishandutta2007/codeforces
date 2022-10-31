#include <bits/stdc++.h>
using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<int, int> P;
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
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, a, b) for (ll i = a; i <= (ll)(b); ++i)
#define rep3(i, a, b) for (ll i = a; i >= (ll)(b); --i)

typedef vector<int> vec;
typedef vector<vector<ll>> mat;

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec rv(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}
ll mul(ll a, ll b) { if (b == 0) return 0; if (a > INF / b) return INF; return a * b;}
ll mygcd(ll a, ll b) { if (b == 0 || a == b) return a; return mygcd(b, a % b);}

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


ll parent[500005], sizes[500005];

void init(ll n){
    for(ll i=0;i<=n;i++){
        parent[i] = i;
    }
}
ll find(ll x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = find(parent[x]);
    }
}

void unite(ll x,ll y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(sizes[x] < sizes[y])swap(x, y);

    parent[y] = x;
    sizes[x] += sizes[y];
}

bool same(ll x,ll y){
    return find(x) == find(y);
}

ll size(ll x){
    return sizes[find(x)];
}

bool icpc = false;
bool multicase = true;

ll n, k;

bool used[200005];
ll id[200005];

bool solve() {
    cin >> n >> k;
    vec a = rv(n), b = rv(k);
    rep(i, n) {
        used[i + 1] = false;
    }
    rep(i, k) {
        used[b[i]] = true;
    }
    for(int i=1;i<=n;i++){
        id[i] = 0;
    }
    ll idx = 0;
    ll ans = 1;
    for(int i=0;i<n;i++){
        if (used[a[i]]) {
            id[a[i]] = ++idx;
        }
    }
    a.pb(0);
    ll cnt = 0;
    vec v;
    for (int i = 0; i <= n; i++) {
        if (i == n || used[a[i]]) {
            v.pb(cnt);
            cnt = 0;
        } else {
            cnt ++;
        }
    }

    init(k + 5);
    for(int i=0;i<=k;i++){
        sizes[i] = v[i];
    }
    for(int i=0;i<k;i++){
        ll idx = id[b[i]];
        ll l = idx - 1, r = idx;
        if (size(l) > 0 && size(r) > 0) {
            ans *= 2;
            ans %= mod;
        } else if (size(l) == 0 && size(r) == 0) {
            ans = 0;
        }
        unite(l, r);
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