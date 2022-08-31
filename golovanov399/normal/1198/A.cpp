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

	int n = nxt(), I = nxt();
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		M[nxt()] += 1;
	}
	vector<pair<int, int>> a;
	for (const auto& [k, v] : M) {
		a.push_back({k, v});
	}

	int cnt = 1;
	while (cnt < (int)a.size() && (32 - __builtin_clz(cnt)) * 1ll * n <= I * 8) {
		++cnt;
	}
	int sz = a.size();
	vector<int> p(sz + 1);
	for (int i = 0; i < sz; ++i) {
		p[i + 1] = p[i] + a[i].second;
	}
	int ans = 0;
	for (int i = 0; i + cnt <= sz; ++i) {
		ans = max(ans, p[i + cnt] - p[i]);
	}
	cout << n - ans << "\n";

	return 0;
}