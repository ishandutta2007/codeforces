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



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m, k, a, b;
	cin >> n >> m >> k;

	unordered_set<int> adj[n+1];
	vector<pii> edges;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		edges.push_back(pii(a,b));
		adj[a].insert(b);
		adj[b].insert(a);
	}

	int res = n;
	vector<bool> vis(n+1);
	auto remove = [&] (queue<int> topo) {
		while (!topo.empty()) {
			int i = topo.front(); topo.pop();
			if (vis[i]) continue;
			vis[i] = true;
			res--;
			for (int x:adj[i]) {
				adj[x].erase(i);
				if (adj[x].size() < k) topo.push(x);
			}
			adj[i].clear();
		}
	};

	vector<int> ans;

	queue<int> topo;
	for (int i=1; i<=n; i++) {
		if (adj[i].size() < k) {
			topo.push(i);
		}
	}
	remove(topo);
	ans.push_back(res);

	for (int i=m-1; i>0; i--) {
		tie(a,b) = edges[i];
		if (!vis[a] && !vis[b]) {
			queue<int> nxt;
			adj[a].erase(b);
			adj[b].erase(a);
			if (adj[a].size() < k) nxt.push(a);
			if (adj[b].size() < k) nxt.push(b);
			remove(nxt);
		}
		ans.push_back(res);
	}

	reverse(ans.begin(), ans.end());
	for (int i:ans) {
		cout << i << nl;
	}

	return 0;
}