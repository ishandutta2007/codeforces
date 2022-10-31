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

const ll INF = 2e18;
const ll fact_table = 32008;

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
#define all(c) begin(c), end(c)

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

ll n;
vector<pair<int, bool>> G[200005];
ll fib[2005];
ll siz[200005];

void dfs(int v, int p) {
    int sum = 1;
    for (auto [nv, edge] : G[v]) {
        if (nv == p) continue;
        if (edge) continue;
        dfs(nv, v);
        sum += siz[nv];
    }
    siz[v] = sum;
    return;
}

P DFS_Check(int v, int p, int idx) {
    if (siz[v] == fib[idx - 1] || siz[v] == fib[idx - 2]) {
        if (siz[v] == fib[idx - 1]) {
            return P(v, p);
        } else {
            return P(p, v);
        }
    }
    P res = P(-1, -1);
    for (auto [nv, flag] : G[v]) {
        if (nv == p) continue;
        if (flag) continue;
        P res_nv = DFS_Check(nv, v, idx);
        if (res_nv != P(-1, -1)) {
            res = res_nv;
            break;
        }
    }
    return res;
}

void Check(int v, int idx) {
    if (idx <= 2) return;
    // vfib[idx]fib-tree
    dfs(v, -1);

    auto [a, b] = DFS_Check(v, -1, idx);
    if (a == -1) {
        YES(0);
        exit(0);
    }
    for (int i = 0; i < G[a].size(); i++) {
        if (G[a][i].first == b) {
            G[a][i].second = true;
        }
    }
    for (int i = 0; i < G[b].size(); i++) {
        if (G[b][i].first == a) {
            G[b][i].second = true;
        }
    }
    Check(a, idx - 1);
    Check(b, idx - 2);
    return;
}



bool solve() {
    cin >> n;
    if (n == 1) {
        YES(1);
        return true;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].pb(make_pair(b, false));
        G[b].pb(make_pair(a, false));
    }
    fib[1] = fib[2] = 1;
    int pidx = -1;
    for (int i = 3;; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > n) {
            YES(0);
            return true;
        } else if (fib[i] == n) {
            pidx = i;
            break;
        }
    }


    Check(1, pidx);

    YES(1);

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