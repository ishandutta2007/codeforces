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
const int MX = 100001; //check the limits, dummy

vector<vi> graph;
pi rep[MX];
int par[MX];
int sub[MX];

void dfs(int v, int p) {
    par[v] = p;
    rep[v] = {v, p};
    sub[v] = 1;
    trav(a, graph[v]) {
        if (a == p) continue;
        dfs(a, v);
        rep[v] = rep[a];
        sub[v] += sub[a];
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        graph.clear(); F0R(i, N) graph.pb(vi());

        F0R(i, N-1) {
            int X, Y; cin >> X >> Y; X--; Y--;
            graph[X].pb(Y);
            graph[Y].pb(X);
        }
        dfs(0, 0);
        vi ans = {rep[0].f, rep[0].s, rep[0].f, rep[0].s};
        F0R(i, N) {
            if (sub[i] * 2 == N) {
                ans = {rep[i].f, rep[i].s, rep[i].f, par[i]};
            }
        }
        F0R(i, 4) ans[i]++;
        cout << ans[0] << " " << ans[1] << nl << ans[2] << " " << ans[3] << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343