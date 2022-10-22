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

ll nc2(ll n) {
	return n*(n-1)/2;
}

const int N = 5e5+1;
vector<int> adj[N], tree[N];
ll f[N], g[N], sz[N];

int n;

int precmp(int u, int p=0) {
	sz[u] = 1;
	for (int v : tree[u]) {
		if (v!=p) {
			adj[u].push_back(v);
			sz[u] += precmp(v,u);
		}
	}
	return sz[u];
}

ll solve(int);
ll path(int);
const int CAP = 5;

ll solve(int u) {
	if (f[u] != -1) return f[u];

	f[u] = INFLL;
	for (int v : adj[u]) {
		f[u] = min(f[u], solve(v));
	}

	For(i,min(CAP,(int)adj[u].size())) {
		For(j,i) {
			int a = adj[u][i];
			int b = adj[u][j];
			f[u] = min(f[u], path(a) + path(b) + nc2(n-sz[a]-sz[b]));
		}
	}

	return f[u];
}

ll path(int u) {
	if (g[u] != -1) return g[u];

	g[u] = nc2(sz[u]);
	for (int v : adj[u]) {
		g[u] = min(g[u], path(v) + nc2(sz[u]-sz[v]));
	}

	return g[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);

	cin >> n;

	int r = -1;
	For(i,n-1) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		if (tree[a].size() > 1) r = a;
		if (tree[b].size() > 1) r = b;
	}

	if (r == -1) {
		assert(n == 2);
		cout << 2 << nl;
	} else {
		//cerr << "root: " << r << nl;
		precmp(r);
		FOR(i,1,n) {
			sort(adj[i].begin(), adj[i].end(), [&] (int a, int b) {
				return sz[a] > sz[b];
			});
		}
		//cerr << "f[r] = " << solve(r) << nl;
		//cerr << " -> " << nc2(n)-solve(r) << " more paths" << nl;
		cout << nc2(n) + nc2(n)-solve(r) << nl;
	}

	return 0;
}