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

struct Edge {
	int a, b;
};

const int N = 2e5+1;
vector<int> adj[N];

int root[N];
int find(int i) {
	if (root[i] == -1) return i;
	return root[i] = find(root[i]);
}
int link(int i, int j) {
	i = find(i); j = find(j);
	if (i==j) return false;
	root[i] = j;
	return true;
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

	memset(root, -1, sizeof root);

	int n, m;
	cin >> n >> m;

	vector<Edge> edges;
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({a,b});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int best = 1;
	for (int i=2; i<=n; i++) {
		if (adj[i].size() > adj[best].size()) {
			best = i;
		}
	}

	vector<Edge> ans;
	for (int x : adj[best]) {
		link(x,best);
		ans.push_back({x,best});
	}
	for (const Edge& e : edges) {
		if (link(e.a,e.b)) {
			ans.push_back(e);
		}
	}

	assert(ans.size() == n-1);
	cerr << "ANSWER: " << nl;
	for (const Edge& e : ans) {
		cout << e.a << " " << e.b << nl;
	}

	return 0;
}