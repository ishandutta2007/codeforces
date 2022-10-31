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
// using namespace atcoder;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 2e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
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
#define CLEAR(a) a = decltype(a)();
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)

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

bool multicase = false;

struct SegmentTree {
    //SegmentTree seg( vector<ll>(l + 5, INF) );
private:
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(ll x, ll val) {
        //a[x]y()
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    ll getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        //[a,b)
        if (r < 0) r = n;
        if (r <= a || b <= l) return -INF;
        if (a <= l && r <= b) return node[k];

        ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};

// ACL

ll n;
ll p[100];
vector<vector<ll>> print;

bool order(ll l, ll r) {
    // l  r 
    int o = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == l) o++;
        if (p[i] == r && o == 1) return true;
    }
    return false;
}

void shuffle(vec& v) {
    print.pb(v);

    reverse(v.begin(), v.end());
    vec res = {0};
    int l = n - v[0] + 1, r = n;
    for (int i = 0; i < v.size(); i++) {
        for (int j = l; j <= r; j++) {
            res.pb(p[j]);
        }
        if (i + 1 == v.size()) break;
        r = l - 1;
        l = r - v[i + 1] + 1;
    }

    for (int i = 1; i <= n; i++) {
        p[i] = res[i];
    }
    return;
}

void act(ll s, ll l, ll r) {
    vec v;
    for (int i = 0; i < s; i++) {
        v.pb(1);
    }
    ll cnt = 0;
    for (int i = s + 1; i <= n - s; i++) {
        cnt ++;
        if (p[i] == l || p[i + 1] == r) {
            v.pb(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0) v.pb(cnt);
    for (int i = 0; i < s; i++) {
        v.pb(1);
    }

    shuffle(v);
    return;
}

void rev(ll s) {
    if (s == 0) {
        vec v(n, 1);
        shuffle(v);
        return;
    }
    vec v;
    for (int i = 0; i < s; i++) {
        v.pb(1);
    }
    if (n - 2 * s > 0) v.pb(n - 2 * s);
    for (int i = 0; i < s; i++) {
        v.pb(1);
    }

    shuffle(v);
    return;
}

bool isSorted() {
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) return false;
    }
    return true;
}

void out() {
    for (int i = 1; i <= n; i++) {
        pe(p[i]);
    }
    el;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int s = 0;
    int l = n, r = 1;
    ll cnt = 0;
    while (true) {
        if (isSorted()) break;
        if (order(l, r)) {
            act(s, l, r);
            swap(l, r);
            if (l < r) {
                l ++;
                r --;
            } else {
                l --;
                r ++;
            }
            s ++;
        } else {
            rev(s);
            if (s > 0) swap(l, r);
        }
        if (isSorted()) break;
        // out();
    }
    p(print.size());
    assert(print.size() <= n);
    for (auto u : print) {
        pe(u.size());
        for (auto uu : u) {
            pe(uu);
        }
        el;
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