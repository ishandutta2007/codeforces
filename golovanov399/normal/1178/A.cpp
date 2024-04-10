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
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> ans = {1};
	int s = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] * 2 <= a[0]) {
			ans.push_back(i + 1);
			s += a[i];
		}
	}
	if (2 * s <= accumulate(all(a), 0)) {
		ans.clear();
	}
	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}