#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6+1;
vector<int> adj[N];
int parent[N];

vector<int> topo;
vector<int> nxt[N];
vector<int> val[N];
int depth[N];
int ans[N];

int solve(int x) {
	x = depth[x];
	return nxt[x].size() - nxt[x].back() - 1;
}

// parent, child
int combine(int a, int b) {
	a = depth[a];
	b = depth[b];
	val[b].push_back(0);
	nxt[b].push_back(nxt[b].size());
	if (val[a].size() < val[b].size()) {
		swap(a,b);
	}

	int len = val[b].size();
	int n = val[a].size();
	int m = val[b].size();
	for (int i=1; i<=len; i++) {
		val[a][n-i] += val[b][m-i];
		if (val[a][n-i] >= val[a][nxt[a][n-i]]) {
			nxt[a][n-i] = n-i;
		}
	}

	for (int i=len; i>0; i--) {
		if (i < n) {
			if (val[a][nxt[a][n-i-1]] > val[a][nxt[a][n-i]]) {
				nxt[a][n-i] = nxt[a][n-i-1];
			}
			else if (val[a][nxt[a][n-i-1]] == val[a][nxt[a][n-i]]) {
				nxt[a][n-i] = max(nxt[a][n-i-1], nxt[a][n-i]);
			}
		}
	}

	return a;
}

void toposort(int cur, int par) {
	parent[cur] = par;
	depth[cur] = cur;
	val[cur].push_back(1);
	nxt[cur].push_back(0);
	for (int x : adj[cur]) {
		if (x != par) {
			toposort(x, cur);
		}
	}
	topo.push_back(cur);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	int a, b;
	for (int i=1; i<n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	toposort(1, 0);

	for (int cur : topo) {
		for (int x : adj[cur]) {
			if (x != parent[cur]) {
				depth[cur] = combine(cur, x);
			}
		}
		ans[cur] = solve(cur);
	}

	for (int i=1; i<=n; i++) {
		cout << ans[i] << nl;
	}

	return 0;
}