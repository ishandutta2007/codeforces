#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+1;
const int X = 10+1;
vector<int> adj[N];
ll dp[N][X][3];
ll memo[N][X][3];
ll ndp[N][X];

ll m, k;
ll solve_node(int, int, int, int, int);
ll solve(int, int, int, int);

ll solve_node(int u, int x, int s, int p, int i) {
	if (i==adj[u].size()) return (x==0);
	if (ndp[i][x] != -1) return ndp[i][x];
	if (adj[u][i] == p) return ndp[i][x] = solve_node(u, x, s, p, i+1);
	ll res = 0;
	for (int j=0; j<=x; j++) {
		res += solve(adj[u][i], j, s, u) * solve_node(u, x-j, s, p, i+1) % MOD;
	}
	return ndp[i][x] = res % MOD;
}

ll solve(int u, int x, int s, int p) {
	if (dp[u][x][s] != -1) return dp[u][x][s];
	for (int v : adj[u]) {
		if (v!=p) {
			for (int j=0; j<=x; j++) {
				solve(v, j, 0, u);
				solve(v, j, 1, u);
				solve(v, j, 2, u);
			}
		}
	}

	ll res = 0;
	if (memo[u][x][0] == -1) {
		for (int i=0; i<adj[u].size(); i++) {
			for (int j=0; j<=x; j++) {
				ndp[i][j] = -1;
			}
		}
		memo[u][x][0] = solve_node(u, x, 0, p, 0);
	}
	res += (k-1) * memo[u][x][0] % MOD;

	if (s!=1) {
		if (memo[u][x][2] == -1) {
			for (int i=0; i<adj[u].size(); i++) {
				for (int j=0; j<=x; j++) {
					ndp[i][j] = -1;
				}
			}
			memo[u][x][2] = solve_node(u, x, 2, p, 0);
		}
		res += (m-k) * memo[u][x][2] % MOD;
	}

	if (!s && x>0) { // don't skip
		if (memo[u][x-1][1] == -1) {
			for (int i=0; i<adj[u].size(); i++) {
				for (int j=0; j<=x; j++) {
					ndp[i][j] = -1;
				}
			}
			memo[u][x-1][1] = solve_node(u, x-1, 1, p, 0);
		}
		res += memo[u][x-1][1];
	}

	return dp[u][x][s] = res % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n >> m;
	For(i,n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int x;
	cin >> k >> x;
	memset(dp, -1, sizeof dp);
	memset(memo, -1, sizeof memo);
	ll ans = 0;
	for (int j=0; j<=x; j++) {
		ans += solve(1, j, 0, 0);
	}
	cout << ans % MOD << nl;

	return 0;
}