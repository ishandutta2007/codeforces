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
	// cin >> x;
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> a(n);
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		d[i] = nxt();
		a[i] = {d[i], 2 * i + 1};
	}
	sort(all(a));
	reverse(all(a));
	for (int i = 0; i < n - 1; ++i) {
		printf("%d %d\n", a[i].second, a[i + 1].second);
	}
	for (int i = 0; i < n; ++i) {
		assert(i + a[i].first - 1 < (int)a.size());
		int idx = i + a[i].first - 1;
		assert(idx >= 0);
		printf("%d %d\n", a[idx].second, a[i].second + 1);
		if (idx == (int)a.size() - 1) {
			a.push_back({0, a[i].second + 1});
		}
	}

	return 0;
}