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
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	map<int, vector<int>> M;
	for (int i = 0; i < n; ++i) {
		M[a[i]].push_back(i);
	}
	vector<int> ans(n + 1, -1);
	for (const auto& [x, v] : M) {
		int maxd = v[0] + 1;
		for (int i = 0; i < (int)v.size() - 1; ++i) {
			maxd = max(maxd, v[i + 1] - v[i]);
		}
		maxd = max(maxd, n - v.back());
		if (ans[maxd] == -1) {
			ans[maxd] = x;
		}
	}
	for (int i = 1, cur = -1; i <= n; ++i) {
		if (ans[i] > -1) {
			if (cur == -1 || cur > ans[i]) {
				cur = ans[i];
			}
		}
		ans[i] = cur;
	}
	ans.erase(ans.begin());
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}