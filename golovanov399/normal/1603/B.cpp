#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

long long f(int x, int y) {
	long long n = x;
	if (x > y) {
		n = x + y;
	} else if (x < y) {
		int k = y / x;
		n = (1ll * k * x + y) / 2;
	}
	return n;
}

void solve() {
	// for (int x = 2; x <= 100; x += 2) {
	// 	for (int y = 2; y <= 100; y += 2) {
	//		auto n = f(x, y);
	// 		assert(n % x == y % n);
	// 	}
	// }
	int x = nxt(), y = nxt();
	// assert(f(x, y) % x == y % f(x, y));
	cout << f(x, y) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}