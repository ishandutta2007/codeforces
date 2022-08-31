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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	int s = accumulate(all(a), 0);
	if (s % n) {
		cout << "-1\n";
		return;
	}
	vector<array<int, 3>> ans;
	auto go = [&](int from, int to, int x) {
		a[to] += (from + 1) * x;
		a[from] -= (from + 1) * x;
		assert(a[from] >= 0);
		ans.push_back({from + 1, to + 1, x});
	};
	for (int i = 1; i < n; ++i) {
		int need = (i + 1) - a[i] % (i + 1);
		need %= (i + 1);
		if (need) {
			go(0, i, need);
		}
		assert(a[i] % (i + 1) == 0);
		go(i, 0, a[i] / (i + 1));
	}
	for (int i = 1; i < n; ++i) {
		go(0, i, s / n);
	}
	cout << ans.size() << "\n";
	for (auto [f, t, x] : ans) {
		cout << f << " " << t << " " << x << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}