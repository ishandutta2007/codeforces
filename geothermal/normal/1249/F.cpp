#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 210; //check the limits, dummy

int N, K;
ll dp[MX][MX];
ll W[MX];

vector<vi> graph;

void dfs(int v, int p) {
	
	vi children;
	F0R(i, sz(graph[v])) {
		if (graph[v][i] == p) continue;
		int nxt = graph[v][i];
		dfs(nxt, v);
		
		children.pb(nxt);
	}
	
		ll depth = K - 1;
		ll ans = W[v];
		F0R(j, sz(children)) {
			ans += dp[children[j]][depth];
		}
		dp[v][0] = ans;
		
		ll starSum[MX];
		F0R(i, MX) {
			starSum[i] = 0;
			F0R(j, sz(children)) {
				starSum[i] += dp[children[j]][i];
			}
		}
		
		F0R(i, sz(children)) {
			F0R(j, (K)-1) {
				ans = dp[children[i]][j];
				depth = K - 2 - j;
				if (sz(children) > 1) depth = max(depth, (ll) j);
				ans += starSum[depth] - dp[children[i]][depth];

				dp[v][j+1] = max(dp[v][j+1], ans);
				//cout << v << " " << i << " " << j << " " << ans << " ans " << endl;
			}
		}

	F0Rd(i, K+1) {
		dp[v][i] = max(dp[v][i], dp[v][i+1]);
	}
	
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	cin >> N >> K; K++;
	F0R(i, N) cin >> W[i];
	F0R(i, N) {vi blank; graph.pb(blank); }
	
	F0R(i, N-1) {
		int A, B; cin >> A >> B; A--; B--;
		graph[A].pb(B);
		graph[B].pb(A);
	}
	


	F0R(i, MX) {
		F0R(j, MX) {
			dp[i][j] = 0;
		}
	}
	 
	dfs(0, -1);
	
	F0R(i, N) {
		F0R(j, K) {
			//cout << dp[i][j] << " " << i << " " << j << endl;
		}
	}
	
	ll ans = 0;
	F0R(i, MX) F0R(j, MX) ans = max(ans, dp[i][j]);
	cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343