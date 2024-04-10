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
	long long sum = 0, xr = 0;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		sum += x;
		xr ^= x;
	}

	vector<long long> ans(3);
	ans[0] = 1ll << 57;
	ans[0] += sum % 2;
	sum += ans[0];
	xr ^= ans[0];
	long long rest = 2 * xr - sum;
	assert(rest >= 0);
	assert(rest % 2 == 0);
	rest /= 2;
	for (int i = 0; i < 60; ++i) {
		if (rest & (1ll << i)) {
			ans[1] |= 1ll << i;
			ans[2] |= 1ll << i;
		}
	}
	cout << 3 << "\n" << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}