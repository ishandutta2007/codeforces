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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int r = nxt(), n = nxt();
	vector<int> t(n + 1), x(n + 1), y(n + 1);
	vector<int> ans(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		t[i] = nxt();
		x[i] = nxt() - 1;
		y[i] = nxt() - 1;
	}
	ans[0] = 0;
	int mx = -1;
	for (int i = 1; i <= n; ++i) {
		int cur = mx;
		for (int j = 0; j < i && j <= 2 * r; ++j) {
			if (t[i] - t[i - 1 - j] >= abs(x[i] - x[i - 1 - j]) + abs(y[i] - y[i - 1 - j])) {
				cur = max(cur, ans[i - 1 - j]);
			}
		}
		if (cur > -1) {
			ans[i] = cur + 1;
		}

		if (i >= 2 * r) {
			mx = max(mx, ans[i - 2 * r]);
		}
	}

	cout << *max_element(all(ans)) << "\n";

	return 0;
}