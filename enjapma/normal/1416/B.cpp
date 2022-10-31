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

struct query{
    ll qi, qj, qx;
};

bool multicase = true;

void solve() {
    ll n;
    cin >> n;
    vec a(n+1);

    ll sum = 0;

    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n != 0) {
        p(-1);
        return;
    }

    vector<query> buf;
    for(int i=2;i<=n;i++){
        ll need = i - (a[i] % i);
        if (need == i) need = 0;

        if (need > 0) {
            buf.pb({1, i, need});
            a[1] -= need;
            a[i] += need;
        }

        assert(a[i] % i == 0);
        buf.pb({i, 1, a[i] / i});
        a[1] += a[i];
        a[i] -= a[i];
    }

    ll norm = sum / n;
    for(int i=2;i<=n;i++){
        assert(a[i] == 0);
    }
    for(int i=2;i<=n;i++){
        buf.pb({1, i, norm});
    }

    p(buf.size());
    for(auto u : buf){
        pe(u.qi);pe(u.qj);p(u.qx);
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