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
	vector<int> ans;

	int timer = 0;
	vector<int> used(n + 1);

	auto mex = [&]() {
		++timer;
		for (int x : a) {
			used[x] = timer;
		}
		for (int i = 0;; ++i) {
			if (used[i] < timer) {
				return i;
			}
		}
		return -1;
	};

	while (!is_sorted(all(a))) {
		int m = mex();
		if (m == n) {
			int i = 0;
			while (a[i] == i) {
				++i;
			}
			ans.push_back(i);
			a[i] = m;
		} else {
			ans.push_back(m);
			a[m] = m;
		}
	}

	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}