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
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> b(n);
	long long ans = accumulate(all(a), 0ll);
	int q = nxt();
	map<pair<int, int>, int> M;
	auto rem = [&](int s, int t) {
		int v = M[{s, t}];
		M.erase({s, t});
		ans += min(a[v], b[v]);
		--b[v];
		ans -= min(a[v], b[v]);
	};
	auto add = [&](int s, int t, int v) {
		ans += min(a[v], b[v]);
		++b[v];
		ans -= min(a[v], b[v]);
		M[{s, t}] = v;
	};
	while (q--) {
		int s = nxt() - 1, t = nxt(), u = nxt() - 1;
		if (M.count({s, t})) {
			rem(s, t);
		}
		if (u != -1) {
			add(s, t, u);
		}
		printf("%lld\n", ans);
	}

	return 0;
}