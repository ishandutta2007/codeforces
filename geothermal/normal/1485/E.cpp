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
const int MX = 200022; //check the limits, dummy

vector<vi> graph(MX);
int par[MX];
vi at[MX];

void dfs(int v, int p, int d) {
    at[d].pb(v);
    trav(a, graph[v]) dfs(a, v, d+1);
}

void solve() {

    int N; cin >> N;
    F0R(i, N) graph[i].clear();
    F0R(i, N+10) at[i].clear();
    FOR(i, 1, N) {
        cin >> par[i]; par[i]--; graph[par[i]].pb(i);
    }
    ll dp[N]; dp[0] = 0;
    dfs(0, 0, 0);
    ll A[N]; FOR(i, 1, N) cin >> A[i];
    int x = 1;
    while (sz(at[x]) > 0) {
        ll lo = 1e10, hi = 0, loInc = -1e18, hiInc = 0;
        trav(a, at[x]) {
            ckmin(lo, A[a]);
            ckmax(hi, A[a]);
            ckmax(loInc, -A[a] + dp[par[a]]);
            ckmax(hiInc, A[a] + dp[par[a]]);
        }
        trav(a, at[x]) {
            dp[a] = 0;
            ckmax(dp[a], dp[par[a]] + A[a] - lo);
            ckmax(dp[a], dp[par[a]] + hi - A[a]);
            ckmax(dp[a], loInc + A[a]);
            ckmax(dp[a], hiInc - A[a]);
        }
        x++;
    }
    ll ans = 0; F0R(i, N) ckmax(ans, dp[i]);
    cout << ans << nl;
    
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343