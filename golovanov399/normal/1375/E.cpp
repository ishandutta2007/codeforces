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

void f(vector<int> a) {
	int n = a.size();
	vector<pair<int, int>> ans;
	vector<vector<int>> opts(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] < a[j]) {
				opts[i].push_back(j);
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		sort(all(opts[i]), [&](int x, int y) {
			return a[x] < a[y];
		});
		for (int j : opts[i]) {
			swap(a[i], a[j]);
			ans.push_back({j, i});
		}
	}
	assert(is_sorted(all(a)));
	printf("%d\n", (int)ans.size());
	for (auto [x, y] : ans) {
		printf("%d %d\n", x + 1, y + 1);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = {nxt(), i};
	}
	auto b = a;
	sort(all(b));
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = lower_bound(all(b), a[i]) - b.begin();
	}
	f(p);

	return 0;
}