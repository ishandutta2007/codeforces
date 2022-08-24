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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n = nxt(), m = nxt(), k = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
	}

	if (k == 1) {
		// cout << "2 1\n1\n";
		printf("2\n1\n");
		return;
	}

	set<pair<int, int>> S;
	vector<int> degree(n);
	for (int i = 0; i < n; ++i) {
		degree[i] = a[i].size();
		S.insert({degree[i], i});
	}

	auto check_clique = [&](const vector<int>& vec) {
		for (int v : vec) {
			for (int u : vec) {
				if (u == v) {
					break;
				}
				if (!binary_search(all(a[v]), u)) {
					return false;
				}
			}
		}
		printf("2\n");
		for (int v : vec) {
			printf("%d ", v + 1);
		}
		printf("\n");
		return true;
	};

	vector<char> removed(n);
	while (!S.empty() && S.begin()->first < k) {
		auto [deg, v] = *S.begin();
		S.erase(S.begin());
		removed[v] = 1;
		if (deg == k - 1) {
			vector<int> cand = {v};
			for (int u : a[v]) {
				if (!removed[u]) {
					cand.push_back(u);
				}
			}
			assert((int)cand.size() == k);
			if (check_clique(cand)) {
				return;
			}
		}
		for (int u : a[v]) {
			if (!removed[u]) {
				S.erase({degree[u], u});
				degree[u] -= 1;
				S.insert({degree[u], u});
			}
		}
	}
	if (!S.empty()) {
		printf("1 %d\n", (int)S.size());
		for (auto p : S) {
			printf("%d ", p.second + 1);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}