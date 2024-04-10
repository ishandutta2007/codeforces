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

inline long long inv(long long x, long long y) {
	return x == 1 ? 1 : y - inv(y % x, x) * y / x % y;
}

void solve(long long x) {
	vector<tuple<long long, char, long long>> ans;
	long long y = x;
	while (gcd(x, x ^ y) > 1) {
		y += x;
	}

	for (long long i = 1; 2 * i <= y / x; i *= 2) {
		ans.push_back({i * x, '+', i * x});
	}
	long long cur = 1ll << (63 - __builtin_clzll(y / x));
	while (cur != (y / x)) {
		ans.push_back({cur * x, '+', x << (63 - __builtin_clzll((y / x) ^ cur))});
		cur |= 1ll << (63 - __builtin_clzll((y / x) ^ cur));
	}

	ans.push_back({y, '^', x});
	y ^= x;

	// long long r = 1;
	// while (r * y % x != 1) {
	// 	++r;
	// }

	long long r = inv(y % x, x);

	for (long long i = 1; 2 * i <= r; i *= 2) {
		ans.push_back({i * y, '+', i * y});
	}
	cur = 1ll << (63 - __builtin_clzll(r));
	while (cur != r) {
		ans.push_back({cur * y, '+', y << (63 - __builtin_clzll(r ^ cur))});
		cur |= 1ll << (63 - __builtin_clzll(r ^ cur));
	}

	r = (y * r - 1) / x;
	for (long long i = 1; 2 * i <= r; i *= 2) {
		ans.push_back({i * x, '+', i * x});
	}
	cur = 1ll << (63 - __builtin_clzll(r));
	while (cur != r) {
		ans.push_back({cur * x, '+', x << (63 - __builtin_clzll(r ^ cur))});
		cur |= 1ll << (63 - __builtin_clzll(r ^ cur));
	}

	ans.push_back({r * x, '+', r * x});
	ans.push_back({r * x, '+', r * x + 1});
	ans.push_back({r * x * 2, '^', r * x * 2 + 1});

	assert((int)ans.size() < 100'000);

	cout << ans.size() << "\n";
	for (auto [x, c, y] : ans) {
		cout << x << " " << c << " " << y << "\n";
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	// for (int i = 3; i <= 1'000'000; i += 2) {
	// 	solve(i);
	// }
	solve(nxt());

	return 0;
}