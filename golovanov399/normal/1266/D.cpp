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

	int n = nxt(), m = nxt();
	vector<long long> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		int d = nxt();
		a[u] += d;
		a[v] -= d;
	}

	vector<int> p(n);
	iota(all(p), 0);
	sort(all(p), [&](int i, int j) {
		return a[i] < a[j];
	});

	vector<tuple<int, int, long long>> ans;
	int i = 0, j = n - 1;
	while (i < n && j >= 0 && a[p[i]] < 0 && a[p[j]] > 0) {
		long long d = min(-a[p[i]], a[p[j]]);
		ans.push_back({p[j], p[i], d});
		a[p[i]] += d;
		a[p[j]] -= d;
		while (i < n && a[p[i]] == 0) {
			++i;
		}
		while (j >= 0 && a[p[j]] == 0) {
			--j;
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto [u, v, d] : ans) {
		printf("%d %d %lld\n", u + 1, v + 1, d);
	}

	return 0;
}