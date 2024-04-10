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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int x = nxt() - 1, y = nxt() - 1;
		a[x].push_back(y);
	}
	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
		auto it = lower_bound(all(a[i]), i);
		rotate(a[i].begin(), it, a[i].end());
	}

	vector<int> last(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!a[i].empty()) {
			last[i] = a[i][0];
		}
	}

	int rounds = 0;
	for (int i = 0; i < n; ++i) {
		rounds = max<int>(rounds, a[i].size());
	}
	rounds = max(rounds - 2, 0);
	for (int i = 0; i < n; ++i) {
		int sz = (int)a[i].size() - rounds;
		a[i].resize(max(sz, 0));
	}

	int cn = 0;
	for (auto v : a) {
		cn += v.size();
	}

	for (int st = 0; st < n; ++st) {
		int ans = rounds * n;
		int cur = cn;
		set<int> S;
		int i = st;
		vector<int> cr(n);
		for (int i = 0; i < n; ++i) {
			cr[i] = (int)a[i].size() - 1;
		}
		while (cur || !S.empty()) {
			S.erase(i);
			if (cr[i] >= 0) {
				S.insert(a[i][cr[i]--]);
				--cur;
			}
			++i;
			if (i == n) {
				i = 0;
			}
			++ans;
		}
		printf("%d ", ans - 1);
	}
	printf("\n");

	return 0;
}