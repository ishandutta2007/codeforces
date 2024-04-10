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

const long long to[4] = {0ll, 2ll, 3ll, 1ll};

long long f(long long n) {
	int rem = (n - 1) % 3;
	n = (n - 1) / 3;
	int k = 0;
	while (n >= (1ll << (2 * k))) {
		n -= (1ll << (2 * k));
		++k;
	}
	long long a = 1ll << (2 * k);
	long long b = 2ll << (2 * k);
	a |= n;
	for (int i = 0; i < k; ++i) {
		b |= to[(a >> (2 * i)) & 3ll] << (2 * i);
	}
	return vector<long long>{a, b, a ^ b}[rem];
}

void solve() {
	long long n;
	scanf("%lld", &n);
	cout << f(n) << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	// for (int i = 1; i <= 900; ++i) {
	// 	cout << f(i) << " ";
	// }
	// cout << "\n";

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}