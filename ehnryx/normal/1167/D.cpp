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
int par[N], col[N], depth[N], height[N];

void dfs(int u) {
	if (u) depth[u] = 1 + depth[par[u]];
	for (int v : adj[u]) {
		dfs(v);
		height[u] = max(height[u], 1 + height[v]);
	}
	col[u] = (depth[u] > height[u]);
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

	string s;
	cin >> s;

	{
		int u = 0;
		int id = 1;
		for (char c : s) {
			if (c == '(') {
				par[id] = u;
				adj[u].push_back(id);
				u = id++;
			} else {
				u = par[u];
			}
		}
	}

	dfs(0);

	{
		int u = 0;
		int id = 1;
		for (char c : s) {
			if (c == '(') {
				par[id] = u;
				adj[u].push_back(id);
				u = id++;
				cout << col[u];
			} else {
				cout << col[u];
				u = par[u];
			}
		}
		cout << nl;
	}

	return 0;
}