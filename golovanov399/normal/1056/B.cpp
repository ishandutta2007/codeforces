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

	int n = nxt(), m = nxt();
	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if ((i * i + j * j) % m) continue;
			ans += 1ll * (n + m - i) / m * ((n + m - j) / m);
			// cout << i << " " << j << " " << (n + m - 1 - i) / m << " " << ((n + m - 1 - j) / m) << "\n";
		}
	}
	cout << ans << "\n";

	return 0;
}