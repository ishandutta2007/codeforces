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
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	set<pair<int, int>> S;
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		if (!i || a[i] != a[i - 1]) {
			S.insert({a[i], i});
			M[i] = a[i];
		}
	}
	long long ans = 0;
	while ((int)S.size() > 1) {
		// for (auto [v, p] : S) {
		// 	cerr << "(" << v << ", " << p << ") ";
		// }
		// cerr << "| ";
		// for (auto [p, v] : M) {
		// 	cerr << "[" << p << ", " << v << "] ";
		// }
		// cerr << "\n";
		auto [v, p] = *S.begin();
		S.erase(S.begin());
		auto it = M.find(p);
		if (it == M.begin()) {
			M.erase(it);
			continue;
		}
		if (next(it) != M.end() && prev(it)->second > next(it)->second) {
			ans += next(it)->second - v;
			S.insert({next(it)->second, p});
			it->second = next(it)->second;
			S.erase({next(it)->second, next(it)->first});
			M.erase(next(it));
		} else {
			ans += prev(it)->second - v;
			M.erase(it);
		}
	}
	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}