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

	int n = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(nxt());
		generate(all(a[i]), nxt);
	}
	vector<int> all_lasts;
	for (int i = 0; i < n; ++i) {
		if (is_sorted(all(a[i]), greater<int>())) {
			all_lasts.push_back(a[i].back());
		}
	}
	sort(all(all_lasts));
	long long ans = 1ll * n * n;
	for (int i = 0; i < n; ++i) {
		if (is_sorted(all(a[i]), greater<int>())) {
			ans -= all_lasts.end() - lower_bound(all(all_lasts), a[i][0]);
		}
	}

	cout << ans << "\n";

	return 0;
}