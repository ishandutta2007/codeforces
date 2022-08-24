#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222'222;
vector<int> a[N];
int pos[N];

vector<int> dp[N];
int pid[N];

int dfs_down(int v, int p = -1) {
	dp[v].resize(a[v].size());
	int res = pos[v];
	pid[v] = -1;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			pid[v] = i;
			continue;
		}
		res = max(res, dp[v][i] = dfs_down(a[v][i], v));
	}
	return res;
}

void dfs_up(int v, int from_above) {
	if (pid[v] > -1) {
		dp[v][pid[v]] = from_above;
	}
	vector<int> pref(a[v].size() + 1, pos[v]);
	vector<int> suf(a[v].size() + 1, pos[v]);
	for (int i = 0; i < (int)a[v].size(); ++i) {
		pref[i + 1] = max(pref[i], dp[v][i]);
	}
	for (int i = (int)a[v].size() - 1; i >= 0; --i) {
		suf[i] = max(suf[i + 1], dp[v][i]);
	}
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (pid[v] != i) {
			dfs_up(a[v][i], max(pref[i], suf[i + 1]));
		}
	}
}

void solve() {
	int n = nxt();
	vector<int> h(n);
	generate(all(h), nxt);
	vector<pair<int, int>> vi(n);
	for (int i = 0; i < n; ++i) {
		vi[i] = {h[i], i};
	}
	sort(all(vi));
	for (int i = 0; i < n; ++i) {
		pos[vi[i].second] = i;
	}
	
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs_down(0);
	dfs_up(0, 0);

	// for (int i = 0; i < n; ++i) {
	// 	cerr << pos[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < (int)a[i].size(); ++j) {
	// 		cerr << i + 1 << " -> " << a[i][j] + 1 << ": " << dp[i][j] << "\n";
	// 	}
	// }

	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			if (j == pid[i]) {
				continue;
			}
			edges.push_back({min(dp[i][j], dp[a[i][j]][pid[a[i][j]]]), i, a[i][j]});
		}
	}
	sort(all(edges));

	vector<int> deg(n);
	int cnt = 0;
	auto inc = [&](int v) {
		cnt -= deg[v] == 1;
		deg[v] += 1;
		cnt += deg[v] == 1;
	};

	long long ans = 0;
	int old = 0;
	for (int i = n - 1; i >= 0; --i) {
		// cerr << "considering " << vi[i].second + 1 << ", cost = " << vi[i].first << "\n";
		while (!edges.empty() && get<0>(edges.back()) == i) {
			[[maybe_unused]] auto [_, u, v] = edges.back();
			edges.pop_back();
			// cerr << "adding " << u + 1 << " -- " << v + 1 << "\n";
			inc(u);
			inc(v);
		}
		ans += 1ll * vi[i].first * (max(cnt, 2) - old);
		old = max(cnt, 2);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}