#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>

// #include <algorithm>
#define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int N = 1e5 + 228;
const int K = 20;
int ans[N];
int val[N];
int up[N][K];
int d[N];

vector<pair<int, int>> G[N];

int la(int v, int level) {
	for(int i = K - 1; i >= 0; --i) {
		if ((1 << i) <= level) {
			level -= (1 << i);
			v = up[v][i];
		}
	}
	return v;
}

int lca(int v, int u) {
	if (d[v] < d[u])
		swap(v, u);
	v = la(v, d[v] - d[u]);
	if (v == u)
		return v;

	for(int i = K - 1; i >= 0; --i) {
		if (up[v][i] != up[u][i])
			v = up[v][i], u = up[u][i];
	}
	return up[v][0];
}

void dfs1(int v, int p, int k) {
	up[v][0] = p;
	d[v] = k;
	for(auto i: G[v]) {
		if (i.first != p)
			dfs1(i.first, v, k + 1);
	}
}

int dfs(int v, int p) {
	int sum = 0;
	for(auto i: G[v]) {
		if (i.first != p) {
			int z = dfs(i.first, v);
			sum += z;
			ans[i.second] = z;
		}
	}
	return sum + val[v];
}

signed main() {
	setup();
	fill(val, val + N, 0);

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		G[a - 1].emplace_back(b - 1, i);
		G[b - 1].emplace_back(a - 1, i);
	}
	dfs1(0, 0, 0);

	for(int k = 1; k < K; ++k) {
		for(int i = 0; i < n; ++i)
			up[i][k] = up[up[i][k - 1]][k - 1];
	}

	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		int c = lca(a - 1, b - 1);
		if (a - 1 != c) ++val[a - 1], --val[c];
		if (b - 1 != c) ++val[b - 1], --val[c];
	}
	dfs(0, 0);
	for(int i = 0; i < n - 1; ++i)
		cout << ans[i] << ' ';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}