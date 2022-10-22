#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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

const int N = 2e5+1;
vector<int> adj[N];
int par[N];
ll sz[N], sub[N], dp[N];

void solve_sub(int u, int p) {
	par[u] = p;
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v!=p) {
			solve_sub(v,u);
			sub[u] += sub[v];
			sz[u] += sz[v];
		}
	}
	sub[u] += sz[u];
}

ll solve(int u, int n) {
	ll tot = 0;
	for (int v : adj[u]) {
		if (v!=par[u]) {
			tot += sub[v];
		}
	}
	ll res = -1;
	for (int v : adj[u]) {
		if (v!=par[u]) {
			ll cur = solve(v,n) + n-sz[v] + tot-sub[v];
			res = max(res, cur);
		}
	}
	if (res == -1) {
		res = n;
	}
	return dp[u] = res;
}

//#define DEBUG
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	For(i,n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve_sub(1,0);
	cout << solve(1,n) << nl;

#ifdef DEBUG
	FOR(i,1,n) {
		cout << i << ": sz " << sz[i] << "  sub " << sub[i] << "  dp " << dp[i] << nl;
	}
#endif

	return 0;
}