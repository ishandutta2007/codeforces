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
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
vector<int> adj[N];
int sz[N], ch[N];
ll fact[N];

ll dp[N];
ll solve(int u, int p) {
	if (dp[u] != -1) return dp[u];

	sz[u] = 1;
	ch[u] = 0;
	ll cur = 1;
	for (int v : adj[u]) {
		if (v!=p) {
			cur = cur * solve(v,u) % MOD * (ch[v]+1) % MOD;
			sz[u] += sz[v];
			ch[u]++;
		}
	}
	//cerr << u << " -> " << ch[u] << nl;

	return dp[u] = cur * fact[ch[u]] % MOD;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	For(i,n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fact[0] = 1;
	FOR(i,1,n) {
		fact[i] = fact[i-1] * i % MOD;
	}

	memset(dp, -1, sizeof dp);
	cout << solve(1,0) * n % MOD << nl;

	return 0;
}