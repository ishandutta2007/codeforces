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
const int M = 2e5+1;
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

	int n, m, d;
	cin >> n >> m >> d;

	vector<Edge> edges;
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({a,b});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (const Edge& e : edges) {
		if (e.a==1 || e.b==1) continue;
		link(e.a,e.b);
	}

	vector<Edge> ans;
	unordered_set<int> seen;
	unordered_set<int> connected;
	for (int x : adj[1]) {
		if (!seen.count(find(x))) {
			seen.insert(find(x));
			connected.insert(x);
			ans.push_back({1,x});
		}
	}

	int lb = ans.size();
	int ub = adj[1].size();
	cerr << "lb: " << lb << nl;
	cerr << "ub: " << ub << nl;

	if (d<lb || d>ub) {
		cout << "NO" << nl;
		return 0;
	}

	cout << "YES" << nl;

	for (int x : adj[1]) {
		if (lb < d && !connected.count(x)) {
			lb++;
			ans.push_back({1,x});
		}
	}

	memset(root, -1, sizeof root);
	for (const Edge& e : ans) {
		link(e.a, e.b);
	}
	for (const Edge& e : edges) {
		if (e.a == 1 || e.b == 1) continue;
		if (link(e.a,e.b)) {
			ans.push_back(e);
		}
	}

	cerr << "ANSWER: " << nl;
	for (const Edge& e : ans) {
		cout << e.a << " " << e.b << nl;
	}

	assert(ans.size() == n-1);

	return 0;
}