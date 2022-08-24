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
	vector<int> vert(n);
	for (int i = 0; i < n; ++i) {
		vert[i] = nxt();
	}
	sort(all(vert));

	vector<int> hor;
	for (int i = 0; i < m; ++i) {
		int x1 = nxt(), x2 = nxt();
		[[maybe_unused]] int y = nxt();
		if (x1 != 1) {
			continue;
		}
		hor.push_back(x2);
	}
	sort(all(hor));

	int ans = n + m;
	for (int i = 0; i <= n; ++i) {
		int cur = i < n ? vert[i] : (int)1e9;

		ans = min(ans, i + (int)(hor.end() - lower_bound(all(hor), cur)));
	}

	cout << ans << "\n";

	return 0;
}