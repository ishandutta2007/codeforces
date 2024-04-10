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

	int q = nxt();
	while (q--) {
		int x = nxt();
		if (x & (x + 1)) {
			cout << (1 << (32 - __builtin_clz(x))) - 1 << "\n";
		} else {
			int ans = 1;
			for (int d = 2; d * d <= x; ++d) {
				if (x % d == 0) {
					ans = x / d;
					break;
				}
			}
			cout << ans << "\n";
		}
	}

	return 0;
}