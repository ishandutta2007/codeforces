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

long long sqr(long long x) {
	return x * x;
}

void solve() {
	int n[3];
	vector<int> a[3];
	for (int i = 0; i < 3; ++i) {
		n[i] = nxt();
	}
	for (int i = 0; i < 3; ++i) {
		a[i].resize(n[i]);
		generate(all(a[i]), nxt);
		sort(all(a[i]));
	}
	int p[3];
	iota(p, p + 3, 0);
	long long ans = 3e18;
	do {
		for (int i = -1, j = 0, k = 0; j < n[p[1]]; ++j) {
			while (k < n[p[2]] && a[p[2]][k] < a[p[1]][j]) {
				++k;
			}
			while (i + 1 < n[p[0]] && a[p[0]][i + 1] <= a[p[1]][j]) {
				++i;
			}
			if (i >= 0 && k < n[p[2]]) {
				int x = a[p[0]][i];
				int y = a[p[1]][j];
				int z = a[p[2]][k];
				ans = min(ans, sqr(x - y) + sqr(y - z) + sqr(z - x));
			}
		}
	} while (next_permutation(p, p + 3));
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