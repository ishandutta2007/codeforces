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

bool multicase = false;

ll n, m, k, w, a, b, c, d, e, h, q, l;

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

vector<ll> G[500005];


struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
 
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        // [a, b)x
        assert(a < b);
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }
 
    ll find(int a, int b, int k=0, int l=0, int r=-1) {
        // [a, b) 
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2*k+1, l, (l+r)/2);
        ll vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

    ll find_leftest(int a, int b, ll x){
        return find_leftest_sub(a, b, x, 0, 0, n);
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
};

struct query{
    ll l, r, id;
};

bool comp(const query& a, const query& b){
    return a.l < b.l;
}

void update(LazySegmentTree& seg1, LazySegmentTree& seg2, ll idx, vec& w){
    // idx 
    if (seg2.find(idx, idx + 1) >= INF / 2ll) return;
    ll findleft = idx;
    while(true){
        seg2.add(findleft, findleft+1, INF);
        seg1.add(findleft+1, n+1, -1);
        seg2.add(findleft+1, n+1, -1);

        // seg2-1
        ll id = seg2.find_leftest(findleft+1, n+1, -1);
        if (id == findleft || id == n) break;
        findleft = id;
    }
    return;
}


void solve() {
    cin >> n >> q;
    vec x(n), y(n), z(n+1), w(n);
    ll cnt = 0;
    for(int i=0;i<n;i++){
        cin >> x[i];
        y[i] = (i + 1) - x[i];
        z[i] = cnt;
        if (y[i] >= 0 && y[i] <= cnt) {
            w[i] = cnt - y[i];
            cnt ++;
        } else {
            w[i] = INF;
        }
    }
    z[n] = cnt;
    vector<query> table;
    for(int i=0;i<q;i++){
        cin >> a >> b;
        table.pb({a, b, i});
    }
    sort(table.begin(), table.end(), comp);
    LazySegmentTree seg1(z), seg2(w);
    int nowleft = 0;
    vec ans(q);
    for(int i=0;i<table.size();i++){
        ll l = table[i].l, r = table[i].r;
        if (l != nowleft) {
            for(int j=nowleft;j<l;j++){
                update(seg1, seg2, j, w);
            }
            nowleft = l;
        }
        ll value = seg1.find(n - r, n + 1 - r);
        ans[table[i].id] = value;
    }
    for(int i=0;i<q;i++){
        if (ans[i] < 0) ans[i] = 0;
        p(ans[i]);
    }
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