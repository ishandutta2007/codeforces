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

	long long n = nxt(), k = nxt();
	long long a = nxt(), b = nxt();

	auto get = [&](long long i, long long j) {
		long long d = abs(j - i);
		d = gcd(d, n * k);
		return n * k / d;
	};

	long long mn = LLONG_MAX, mx = LLONG_MIN;
	for (long long i = b; i < n * k; i += k) {
		auto x = get(a, i);
		mn = min(mn, x);
		mx = max(mx, x);
	}
	for (long long i = k - b; i < n * k; i += k) {
		auto x = get(a, i);
		mn = min(mn, x);
		mx = max(mx, x);
	}
	cout << mn << " " << mx << "\n";

	return 0;
}