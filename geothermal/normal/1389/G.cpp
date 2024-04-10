#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 300001; //check the limits, dummy
int N, M, K;  
vector<vector<pair<int, ll> > > graph(MX);
bool spec[MX];
int timer = 0;
vi tin(MX), low(MX);
bool vis[MX];
ll val[MX];
set<pi> bridges;
int tc[MX];
ll dp[MX];
ll cs[MX];
ll ans[MX];
void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    trav(nxt, graph[v]) {
        int to = nxt.f;
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.ins({min(v, to), max(v, to)});
            }
        }
    }
}

void dfs2(int v, int p, int c) {
    tc[v] = c;
    vis[v] = true;
    trav(nxt, graph[v]) {
        int to = nxt.f;
        if (vis[to]) continue;
        if (bridges.count({min(to, v), max(to, v)})) continue;
        dfs2(to, v, c);
    }
}

void dfs3(int v, int p) {
    dp[v] = val[v];
    cs[v] = 0;
    if (spec[v]) cs[v] = 1;
    trav(a, graph[v]) {
        if (a.f == p) continue;
        dfs3(a.f, v);
        cs[v] += cs[a.f];
        ll cur = dp[a.f] - a.s; 
        if (cs[a.f] == 0 || cs[a.f] == K) {
            cur += a.s;
        }
        if (cur >= 0) dp[v] += cur;
    }
}

void dfs4(int v, int p, pl up) { // up: dp, edge cost
    ans[v] = dp[v];
    if (p != -1) {
        up.f -= up.s;
        if (cs[v] == 0 || cs[v] == K) {
            up.f += up.s;
        }
        if (up.f >= 0) ans[v] += up.f;
    }
    ckmax(up.f, 0ll);
    up.f += val[v];

    trav(a, graph[v]) {
        if (a.f == p) continue;
        ll cur = dp[a.f] - a.s;
        if (cs[a.f] == 0 || cs[a.f] == K) {
            cur += a.s;
        }
        if (cur >= 0) up.f += cur;
    }

    trav(a, graph[v]) {
        if (a.f == p) continue;
        ll cur = dp[a.f] - a.s;
        if (cs[a.f] == 0 || cs[a.f] == K) {
            cur += a.s;
        }
        ckmax(cur, 0ll);
        dfs4(a.f, v, {up.f - cur, a.s});
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> M >> K;
    F0R(i, N) spec[i] = false;
    F0R(i, N) vis[i] = false;

    F0R(i, K) {
        int cur; cin >> cur; cur--;
        spec[cur] = true;
    }
    F0R(i, N) cin >> val[i];

    int ce[M]; F0R(i, M) cin >> ce[i];
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb({Y, ce[i]});
        graph[Y].pb({X, ce[i]});
    }
    F0R(i, N) tin[i] = -1, low[i] = -1;
    F0R(i, N) {
        if (!vis[i]) dfs(i);
    }
    F0R(i, N) vis[i] = false;
    int nxt = 0;
    F0R(i, N) {
        if (vis[i] == false) {
            dfs2(i, -1, nxt);
                nxt++;
        }
    }
    int oN = N;
    N = nxt;
    vector<vector<pair<int, ll> > > ng(N);
    F0R(i, oN) {
        trav(j, graph[i]) {
            if (bridges.count({min(i, j.f), max(i, j.f)})) {
                ng[tc[i]].pb({tc[j.f], j.s});
            }
        }
    }

    K = 0;
    bool nspec[N];
    ll nval[N];
    F0R(i, N) {
        nspec[i] = false; nval[i] = 0;
    }
    F0R(i, oN) {
        if (spec[i] && !nspec[tc[i]]) {
            nspec[tc[i]] = true;
            K++;
        }
        nval[tc[i]] += val[i];
    }
    graph = ng;
    F0R(i, N) {
        spec[i] = nspec[i];
        val[i] = nval[i];
    }
    //solve for tree
/*    F0R(i, oN) {
        cout << tc[i] << " ";
    }
    cout << nl;
    cout << sz(bridges) << nl;*/
    dfs3(0, -1);
/*    F0R(i, N) {
        cout << dp[i] << " " << cs[i] << nl;
    }
    cout << K << nl;*/
    dfs4(0, -1, {0, 0});

    F0R(i, oN) {
        cout << ans[tc[i]] << " ";
    }
    cout << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343