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
bool multicase = true;

ll n, m, k;
ll a, b;
ll h, w;

bool used[200005];

ll alist[200005], blist[200005];
ll dis[200005], back[200005];
vec G[200005], G2[200005];
bool updated[200005];

vec segi;

void update(int v) {
    if (updated[v]) return;
    updated[v] = true;

    for (auto nv : G2[v]) {
        update(nv);
        back[v] = min(back[v], back[nv]);
    }
    return;
}

bool solve() {
    cin >> n >> m;
    segi.resize(n, INF);
    for (int i = 1; i <= n; i++) {
        updated[i] = false;
        back[i] = INF;
        dis[i] = INF;
        G[i].clear();
        G2[i].clear();
    }
    for (int i = 0; i < m; i++) {
        cin >> alist[i] >> blist[i];
        G[alist[i]].pb(blist[i]);
    }

    queue<ll> q;

    q.push(1);
    dis[1] = 0;
    back[1] = 0;
    while (q.size()) {

        int v = q.front(); q.pop();
        for (auto nv : G[v]) {
            if (dis[nv] == INF) {
                q.push(nv);
                dis[nv] = dis[v] + 1;
                back[nv] = dis[v] + 1;
            } else {

            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (dis[alist[i]] < dis[blist[i]]) {
            G2[alist[i]].pb(blist[i]);
        } else {
            back[alist[i]] = min(back[alist[i]], dis[blist[i]]);
        }
    }


    for (int i = 1; i <= n; i++) {
        update(i);
    }

    for (int i = 1; i <= n; i++) {
        pe(back[i]);
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