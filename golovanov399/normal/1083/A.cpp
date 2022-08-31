#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 333333;
vector<pair<int, int>> a[N];
long long w[N];

long long max_from_down[N];

void dfs_down(int v, int p = -1) {
	max_from_down[v] = w[v];
	for (auto [x, c] : a[v]) {
		if (x == p) {
			continue;
		}
		dfs_down(x, v);
		long long tmp = max_from_down[x];
		if (tmp >= c) {
			max_from_down[v] = max(max_from_down[v], tmp - c + w[v]);
		}
	}
}

long long ans = 0;
void dfs_up(long long cur, int v, int p = -1) {
	cur = max(cur, 0ll);
	cur += w[v];
	ans = max(ans, cur);
	ans = max(ans, max_from_down[v]);
	vector<int> sons;
	vector<int> cs;
	for (auto [x, c] : a[v]) {
		if (x != p) {
			sons.push_back(x);
			cs.push_back(c);
		}
	}
	vector<long long> pr(sons.size() + 1);
	vector<long long> sf(sons.size() + 1);
	for (int i = 0; i < (int)sons.size(); ++i) {
		pr[i + 1] = max(pr[i], max_from_down[sons[i]] - cs[i]);
	}
	for (int i = (int)sons.size() - 1; i >= 0; --i) {
		sf[i] = max(sf[i + 1], max_from_down[sons[i]] - cs[i]);
	}
	for (int i = 0; i < (int)sons.size(); ++i) {
		dfs_up(max({cur, w[v] + pr[i], w[v] + sf[i + 1]}) - cs[i], sons[i], v);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		w[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1, c = nxt();
		a[u].push_back({v, c});
		a[v].push_back({u, c});
	}

	dfs_down(0);
	dfs_up(0, 0);
	cout << ans << "\n";

	return 0;
}