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
	vector<long long> a(n);
	generate(all(a), nxt);
	vector<long long> need(n);
	need[0] = a[0];
	for (itn i = 1; i < n; ++i) {
		need[i] = max(a[i], need[i - 1]);
	}
	long long mx = 0;
	for (int i = 0; i < n; ++i) {
		mx = max(mx, need[i] - a[i]);
	}
	if (mx == 0) {
		cout << "0\n";
	} else {
		cout << 64 - __builtin_clzll(mx) << "\n";
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}