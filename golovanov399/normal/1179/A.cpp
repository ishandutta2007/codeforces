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

	int n = nxt(), q = nxt();
	deque<int> a;
	for (int i = 0; i < n; ++i) {
		a.push_back(nxt());
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < n; ++i) {
		int x = a.front();
		a.pop_front();
		int y = a.front();
		a.pop_front();
		ans.push_back({x, y});
		if (x < y) {
			swap(x, y);
		}
		a.push_front(x);
		a.push_back(y);
	}

	while (q--) {
		long long m;
		scanf("%lld", &m);
		if (m - 1 < (long long)(ans.size())) {
			printf("%d %d\n", ans[m - 1].first, ans[m - 1].second);
		} else {
			m -= (int)ans.size() + 1;
			m %= (n - 1);
			printf("%d %d\n", a[0], a[m + 1]);
		}
	}

	return 0;
}