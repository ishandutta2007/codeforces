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

	int r = n;
	set<int> right;
	while (r > 0 && !right.count(a[r - 1])) {
		right.insert(a[--r]);
	}
	int ans = right.size();
	set<int> left;
	for (int i = 0; i < n; ++i) {
		if (left.count(a[i])) {
			break;
		}
		left.insert(a[i]);
		while (right.count(a[i])) {
			right.erase(a[r++]);
		}
		ans = max(ans, n - r + i + 1);
	}
	cout << n - ans << "\n";

	return 0;
}