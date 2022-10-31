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


bool icpc = false;
bool multicase = false;

ll n, m, k;

vector<P> edges;
vector<ll> G[5][300005];

ll cost[4500005];
ll twopow[300005];


ll calc1() {
    // 18
    ll m = 20;
    for (int i = 0; i <= m * n; i++) {
        cost[i] = INF;
    }
    deque<ll> q;
    cost[0] = 0;
    q.push_back(0);

    while (q.size()) {
        int v = q.front(); q.pop_front();
        int l = v / n, id = v % n;

        for (auto nid : G[l % 2][id]) {
            int nv = n * l + nid;
            if (cost[nv] != INF) continue;
            q.push_back(nv);
            cost[nv] = cost[v] + 1;
        }
        if (l < m - 1) {
            int nv = n * (l + 1) + id;
            if (cost[nv] != INF) continue;
            q.push_front(nv);
            cost[nv] = cost[v];
        }
    }
    ll res = INF;
    for (int i = 0; i < m; i++) {
        ll v = i * n + n - 1;
        ll mycost = cost[v] + twopow[i];
        res = min(res, mycost);
    }
    return res;
}

ll calc2() {
    // 
    for (ll i = 0; i <= 2 * n; i++) {
        cost[i] = INF;
    }
    cost[0] = 0;

    priority_queue <P, vector<P>, greater<P> > pqps;

    vector<P> vv;

    pqps.push(P(0, 0));

    for (int idd = 0; idd <= n + 5; idd++) {
        while (!pqps.empty()) {
            P p = pqps.top();
            pqps.pop();
            ll v = p.second, nowcost = p.first;
            int l = v / n, id = v % n;

            if (nowcost > cost[v]) continue;
            cost[v] = nowcost;

            for (auto nid : G[l % 2][id]) {
                int nv = n * l + nid;
                ll newcost = cost[v] + 1;
                if (cost[nv] > newcost) {
                    cost[nv] = newcost;
                    pqps.push(P(newcost, nv));
                }
            }
            int nv = (1 - (l % 2)) * n + id;
            vv.pb(P(v, nv));
        }

        // i

        if (cost[n - 1] < INF || cost[2 * n - 1] < INF) {
            ll res = min(cost[n - 1], cost[2 * n - 1]);
            res += twopow[idd];
            res %= mod;
            return res;
        }

        while (vv.size()) {
            int v = vv.back().first, nv = vv.back().second;
            if (cost[nv] > cost[v]) {
                cost[nv] = cost[v];
                pqps.push(P(cost[nv], nv));
            }
            vv.pop_back();
        }
    }
}



bool solve() {
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[0][a].pb(b);
        G[1][b].pb(a);
    }
    ll ans = INF;
    ans = min(ans, calc1());
    if (ans != INF) {
        p(ans);
        return true;
    }
    ans = min(ans, calc2());
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
    twopow[0] = 0;
    for (int i = 1; i <= 200010; i++) {
        twopow[i] = twopow[i - 1] * 2ll + 1ll;
        twopow[i] %= mod;
    }
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