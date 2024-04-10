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

void solve() {
	int n = nxt(), m = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	vector<vector<int>> ar(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		ar[v].push_back(u);
	}
	for (auto& v : ar) {
		sort(all(v));
	}
	map<vector<int>, long long> M;
	for (int i = 0; i < n; ++i) {
		if (!ar[i].empty()) {
			M[ar[i]] += a[i];
		}
	}
	long long g = 0;
	for (const auto& it : M) {
		g = gcd(g, it.second);
	}
	printf("%lld\n", g);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}