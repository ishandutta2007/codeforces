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

mt19937 rr;

inline std::uint_fast32_t custom_rand() {
	return rr();
}

#define rand custom_rand

template <int N>
void subsolve(int n) {
	[[maybe_unused]] int m = nxt(), p = nxt();
	vector<long long> a(n);
	using Bs = bitset<N>;
	vector<Bs> hui(m, Bs{});
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') {
				a[i] += 1ll << j;
				hui[j].set(i);
			}
		}
	}

	auto check_reliably = [&](long long mask) {
		if (!mask) {
			return true;
		}
		Bs res = hui[__builtin_ctzll(mask)];
		for (auto m = mask; m; m &= m - 1) {
			res &= hui[__builtin_ctzll(m)];
		}
		return (int)res.count() >= (n + 1) / 2;
	};
	auto check = [&](long long mask) {
		if (n <= 1000) {
			return check_reliably(mask);
		} else {
			int cnt = 0;
			for (int it = 0; it < 200; ++it) {
				long long x = a[rand() % n];
				cnt += ((x & mask) == mask);
			}
			if (cnt < 60) {
				return false;
			}
			if (cnt > 140) {
				return true;
			}
			return check_reliably(mask);
		}
	};


	long long ans = 0;
	vector<long long> need_to_check;
	for (int it = 0; it < 30; ++it) {
		long long m = a[rand() % n];
		for (auto mask = m; mask; mask = (mask - 1) & m) {
			need_to_check.push_back(mask);
			// if (__builtin_popcountll(mask) < __builtin_popcountll(ans)) {
			// 	continue;
			// }
			// if (check(mask)) {
			// 	if (check_reliably(mask)) {
			// 		ans = mask;
			// 	}
			// }
		}
	}
	sort(all(need_to_check), [](long long x, long long y) {
		return make_pair(__builtin_popcountll(x), x) < make_pair(__builtin_popcountll(y), y);
	});
	need_to_check.resize(unique(all(need_to_check)) - need_to_check.begin());
	reverse(all(need_to_check));
	for (auto mask : need_to_check) {
		if (__builtin_popcountll(mask) < __builtin_popcountll(ans)) {
			continue;
		}
		if (check(mask)) {
			if (check_reliably(mask)) {
				ans = mask;
				break;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << !!(ans & (1ll << i));
	}
	cout << "\n";
}

#define ifaem(N) if (n <= (N)) { subsolve<N>(n); }

void solve() {
	int n = nxt();
	ifaem(1024) else ifaem(2048) else ifaem(4096) else ifaem(8192) else ifaem(16384) else ifaem(32768) else ifaem(65536) else ifaem(131072) else ifaem(262144)
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}