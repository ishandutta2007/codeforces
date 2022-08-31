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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	if (find(all(a), k) == a.end()) {
		puts("No");
		return;
	}
	if (n == 1) {
		puts("Yes");
		return;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] >= k && a[i + 1] >= k) {
			puts("Yes");
			return;
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (a[i] >= k && a[i + 2] >= k) {
			puts("Yes");
			return;
		}
	}
	puts("No");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}