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

int dp[N][2];
int solve(int u, int s, int p) {
	if (dp[u][s] != -1) return dp[u][s];
	int b1, b2;
	b1 = b2 = -INF;
	int res = 0;
	for (int v : adj[u]) {
		if (v != p) {
			res += solve(v,0,u);
			int cur = solve(v,1,u)+1 - solve(v,0,u);
			if (cur > b1) { b2=b1; b1=cur; }
			else if (cur > b2) { b2=cur; }
		}
	}
	if (b1 == -INF) {
		return res;
	} else if (s || b2 == -INF) {
		return dp[u][s] = res + b1;
	} else {
		return dp[u][s] = res + b1 + b2;
	}
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

	memset(dp, -1, sizeof dp);

	int n,x,y;
	cin >> n >> x >> y;

	For(i,n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (x < y) {
		int m = solve(1,0,0);
		cout << (ll)m*x + (ll)(n-1-m)*y << nl;
	} else {
		bool block = false;
		FOR(i,1,n) {
			if (adj[i].size() == n-1) {
				block = true;
				break;
			}
		}
		if (block) cout << x + (ll)(n-2)*y << nl;
		else cout << (ll)(n-1)*y << nl;
	}
	return 0;
}