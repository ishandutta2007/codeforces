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

const int mod = 998244353;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	long long ans = 1;
	int last = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] > n - k) {
			if (last > -1) {
				ans = 1ll * ans * (i - last) % mod;
			}
			last = i;
		}
	}

	cout << 1ll * k * (2 * n - k + 1) / 2 << " " << ans << "\n";

	return 0;
}