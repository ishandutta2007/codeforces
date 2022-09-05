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
const int MX = 3001; //check the limits, dummy

vector<vi> graph;
ll V[MX];

vpl dp[MX];

void dfs(int v, int p) {
    dp[v].pb({0, V[v]});

    trav(nxt, graph[v]) {
        if (nxt == p) continue;
        dfs(nxt, v);
        vpl nd; F0R(i, sz(dp[v]) + sz(dp[nxt]) - 1) nd.pb({0, -1e18});

        F0R(i, sz(dp[v])) {
            F0R(j, sz(dp[nxt])) {
                pl A = dp[v][i];
                pl B = dp[nxt][j];
                pl res = {A.f + B.f, A.s + B.s};
                ckmax(nd[i+j], res);
            }
        }
        dp[v] = nd;
    }

    dp[v].pb({0, -1e18});
    F0Rd(i, sz(dp[v]) - 1) {
        ckmax(dp[v][i+1], {dp[v][i].f + (dp[v][i].s>0?1:0), 0});
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        graph.clear();
        int N, M; cin >> N >> M;
        F0R(i, N) {
            graph.pb(vi());
        }
        F0R(i, N) {
            cin >> V[i];
        }
        F0R(i, N) {
            ll cur; cin >> cur; V[i] = cur - V[i];
        }

        F0R(i, N-1) {
            int A, B; cin >> A >> B; A--; B--;
            graph[A].pb(B); graph[B].pb(A);
        }
        F0R(i, N) dp[i].clear();

        dfs(0, -1);

        ll res = dp[0][M-1].f;
        if (dp[0][M-1].s > 0) res++;
        cout << res << nl;

/*        F0R(i, N) {
            cout << sz(dp[i]) << " ";
            F0R(j, sz(dp[i])) {
                cout << '(' << dp[i][j].f << ", " << dp[i][j].s << ')' << " ";
            }
            cout << nl;
        }*/
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343