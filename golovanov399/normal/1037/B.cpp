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

	int n = nxt(), s = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	sort(all(a));
	int m = a[n / 2];
	long long ans = abs(s - m);
	if (m < s) {
		for (int i = n / 2 + 1; i < n; ++i) {
			ans += max(s, a[i]) - a[i];
		}
	} else {
		for (int i = 0; i < n / 2; ++i) {
			ans += a[i] - min(s, a[i]);
		}
	}

	cout << ans << "\n";

	return 0;
}