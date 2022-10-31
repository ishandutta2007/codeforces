#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<long double , ll> Ps;
typedef pair<ll, bool> Pb;

const ll INF = 1e18;
const ll fact_table = 3200008;
long double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
//,,,


#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)();
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= mod; b >>= 1;}(x *= a) %= mod; b--;} return x;}
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
struct Timer {
    int64_t start;
    const int64_t CYCLES_PER_SEC = 2800000000;
    Timer() { reset(); }
    void reset() { start = getCycle(); }
    inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
    inline int64_t getCycle() {
        uint32_t low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((int64_t)low) | ((int64_t)high << 32);
    }
};

bool multicase = true;

ll n, m, k, w, a, b, c, d, e, h, q, l;

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

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

void solve() {
    cin >> n >> k;
    init(n + 10);
    string s;
    cin >> s;
    for(int i=0;i<n-k;i++){
        unite(i, i + k);
    }
    for(int i=0;i<n;i++){
        if(s[i] != '?'){
            int offset = s[i] - '0';
            unite(i, offset + n);
        }
    }
    bool flag1 = !same(n, n + 1);
    int one = 0, two = 0;
    for(int i=0;i<k;i++){
        if (s[i] == '0') {
            one ++;
        } else if (s[i] == '1') {
            two ++;
        } else if (same(i, n)) {
            one ++;
        } else if (same(i, n + 1)) {
            two ++;
        }
    }
    bool flag2 = (one <= k / 2) && (two <= k / 2);
    YES(flag1 && flag2);
    return;
}

int main() {
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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