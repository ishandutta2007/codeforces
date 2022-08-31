#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(0);

	int n = nxt();
	vector<int> a(n);
	vector<long long> m(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> m[i];
	}
	long long s = accumulate(all(a), 0ll);
	if (s < 0) {
		for (auto& x : a) {
			x *= -1;
		}
	}

	long long mask = 0;
	for (int b = 62; b >= 0; --b) {
		long long sumofthose = 0;
		for (int i = 0; i < n; ++i) {
			if (__builtin_ctzll(m[i]) == b) {
				sumofthose += a[i];
			}
		}
		if (sumofthose > 0) {
			for (int i = 0; i < n; ++i) {
				if ((m[i] >> b) & 1ll) {
					a[i] *= -1;
				}
			}
			mask |= 1ll << b;
		}
	}
	cout << mask << "\n";

	return 0;
}