#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

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
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[0]) {
			ans = max(ans, i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[n - 1]) {
			ans = max(ans, n - 1 - i);
		}
	}
	cout << ans << "\n";

	return 0;
}