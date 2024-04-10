#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
	}

	vector<int> nx(n, -1);
	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() == n - 1) {
			continue;
		}
		nx[i] = 0;
		int j = 0;
		while (nx[i] == i || (j < (int)a[i].size() && a[i][j] == nx[i])) {
			if (nx[i] != i) {
				++j;
			}
			++nx[i];
		}
	}

	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) {
		if (nx[i] > -1) {
			int x = i, y = nx[i];
			if (x > y) {
				swap(x, y);
			}
			S.insert({x, y});
		}
	}

	// vector<vector<int>> eids(n);
	// vector<pair<int, int>> edges(all(S));
	// {
	// 	int cur = 0;
	// 	for (auto [u, v] : S) {
	// 		eids[u].push_back(cur);
	// 		eids[v].push_back(cur);
	// 		++cur;
	// 	}
	// }

	vector<vector<int>> gr(n);
	vector<int> remain(n);
	for (auto [u, v] : S) {
		remain[u] += 1;
		remain[v] += 1;
	}
	for (auto [u, v] : S) {
		remain[u] -= 1;
		remain[v] -= 1;
		if (!remain[u] || !remain[v]) {
			remain[u] += 1;
			remain[v] += 1;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
	}

	vector<char> used(n);
	vector<int> p(n), q(n);
	int last = 1;
	for (int i = 0; i < n; ++i) {
		if (nx[i] == -1) {
			used[i] = 1;
			p[i] = q[i] = last++;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i] && (int)gr[i].size() > 1) {
			used[i] = 1;
			p[i] = last;
			q[i] = last + (int)gr[i].size();
			for (int j = 0; j < (int)gr[i].size(); ++j) {
				assert(!used[gr[i][j]]);
				used[gr[i][j]] = true;
				p[gr[i][j]] = last + j + 1;
				q[gr[i][j]] = last + j;
			}
			last += (int)gr[i].size() + 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			assert((int)gr[i].size() == 1);
			assert(!used[gr[i][0]]);
			p[i] = q[gr[i][0]] = last;
			q[i] = p[gr[i][0]] = last + 1;
			last += 2;
			used[i] = used[gr[i][0]] = true;
		}
	}
	for (auto x : p) {
		printf("%d ", x);
	}
	printf("\n");
	for (auto x : q) {
		printf("%d ", x);
	}
	printf("\n");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}