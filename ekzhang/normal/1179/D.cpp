#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 500013
int N;
vector<int> adj[MAXN];
int sz[MAXN];
LL dp[MAXN];
LL ans; // minimize this

inline LL nc2(LL n) {
	return n * (n - 1) / 2;
}

inline double isect(pair<LL, LL>& a, pair<LL, LL>& b) {
	return 1.0 * (b.second - a.second) / (a.first - b.first);
}

void dfs(int n, int p) {
	sz[n] = 1;
	for (int v : adj[n]) if (v != p) {
		dfs(v, n);
		sz[n] += sz[v];
	}

	if (sz[n] == 1) {
		dp[n] = 0;
		return;
	}

	dp[n] = nc2(N);
	vector<pair<LL, LL> > c;
	for (int v : adj[n]) if (v != p) {
		dp[n] = min(dp[n], dp[v] + nc2(sz[n] - sz[v]));

		// convex hull trick
		LL a = sz[v];
		c.emplace_back(a, dp[v] - N * a + nc2(a) + a);
	}

	sort(c.begin(), c.end());
	LL m = nc2(N);
	vector<pair<LL, LL> > cht;
	for (auto p : c) {
		LL y = p.first, x = p.second;
		// query cht
		if (cht.size()) {
			while (cht.size() >= 2 && isect(cht.back(), cht[cht.size() - 2]) < y)
				cht.pop_back();
			m = min(m, cht.back().first * y + cht.back().second + x);
		}

		// add new line
		if (cht.empty() || cht.back().first != y) {
			while (cht.size() >= 2 && isect(p, cht.back()) > isect(cht.back(), cht[cht.size() - 2]))
				cht.pop_back();
			cht.push_back(p);
		}
	}

	ans = min(ans, m + nc2(N));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = nc2(N);
	dfs(0, -1);
	ans = min(ans, dp[0]);
	// DON'T FORGET IF ROOT IS LEAF!!!

	cout << 2 * nc2(N) - ans << endl;
	return 0;
}