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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll cost[MX][3];
ll dp[MX][8];
ll last[MX][8];
ll color[MX];

vector<vi> graph;

ll dfs(int v, int p, int c, bool val) {
	ll ans = cost[v][c];
	color[v] = c;
	F0R(i, sz(graph[v])) {
		int nxt = graph[v][i];
		if (nxt == p) continue;
		int nxtVal = (c+2)%3;
		if (val) nxtVal = (c+1)%3;
		ans += dfs(nxt, v, nxtVal, val);
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N;
	F0R(i, N) cin >> cost[i][0];
	F0R(i, N) cin >> cost[i][1];
	F0R(i, N) cin >> cost[i][2];
	
	F0R(i, N) {
		vi blank; graph.pb(blank);
	}
	F0R(i, N-1) {
		int A, B; cin >> A >> B;
		A--;
		B--;
		graph[A].pb(B);
		graph[B].pb(A);
	}
	int S;
	F0R(i, N) {
		if (sz(graph[i]) > 2) {
			cout << -1 << endl; return 0;
		}
		if (sz(graph[i]) == 1) S = i;
	}
	
	
	
	ll ans = 1000000000000000;
	int val = 0;
	bool way;
	F0R(i, 3) {
		bool cur = false;
		ans = min(ans, dfs(S, -1, 0, cur));
		ll X = dfs(S, -1, 1, cur);
		if (ans > X) {
			ans = X;
			val = 1;
		}
		X = dfs(S, -1, 2, cur);
		if (ans > X) {
			ans = X;
			val = 2;
		}
		way = false;
	}
	
	F0R(i, 3) {
		bool cur = true;
		ll X = dfs(S, -1, 0, cur);
		if (ans > X) {
			ans = X;
			val = 0;
			way = true;
		}
		X = dfs(S, -1, 1, cur);
		if (ans > X) {
			ans = X;
			val = 1;
			way = true;
		}
		X = dfs(S, -1, 2, cur);
		if (ans > X) {
			ans = X;
			val = 2;
			way = true;
		}
	}
		
	
	dfs(S, -1, val, way);
	cout << ans << endl;
	
	F0R(i, N) {
		cout << color[i] +1 << " ";
	}
	cout << endl;
		

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE