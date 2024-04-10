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

	int n, a, b;
	cin >> n;

	vector<int> adj[n+1];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> val(n);
	vector<int> idx(n+1);
	for (int i = 0; i < n; i++) {
		cin >> val[i];
		idx[val[i]] = i;
	}

	auto cmp = [&] (int a, int b) {
		return idx[a] < idx[b];
	};

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), cmp);
	}

	vector<int> order;
	vector<bool> vis(n+1, 0);
	queue<int> bfs;

	vis[1] = true;
	bfs.push(1);
	while (!bfs.empty()) {
		int cur = bfs.front(); bfs.pop();
		order.push_back(cur);
		for (int x : adj[cur]) {
			if (!vis[x]) {
				vis[x] = true;
				bfs.push(x);
			}
		}
	}

	if (order == val) {
		cout << "Yes" << nl;
	} else {
		cout << "No" << nl;
	}

	return 0;
}