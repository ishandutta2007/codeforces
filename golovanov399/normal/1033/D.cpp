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

const long long inf = 3e18;

long long pw(long long x, int p) {
	long long res = 1;
	for (int i = 0; i < p; ++i) {
		if ((long double)res * x > 2 * inf) {
			res = inf;
		} else {
			res = min(res * x, inf);
		}
	}
	return res;
}

long long getRoot(long long x, int p) {
	long long l = 1, r = x + 1;
	while (r > l + 1) {
		long long m = (l + r) / 2;
		if (pw(m, p) > x) {
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}

	set<long long> known_primes;
	vector<vector<long long>> divs(n);

	vector<long long> pq;
	function<void()> addPrime = [&]() {
		long long p = pq.back();
		pq.pop_back();
		if (known_primes.count(p)) {
			return;
		}
		known_primes.insert(p);
		for (int i = 0; i < n; ++i) {
			if (a[i] % p == 0) {
				while (a[i] % p == 0) {
					a[i] /= p;
					divs[i].push_back(p);
				}
				if (a[i] > 1) {
					pq.push_back(a[i]);
				}
			}
		}
	};

	auto detectPower = [&](long long x, int pwr) {
		long long y = getRoot(x, pwr);
		if (pw(y, pwr) == x) {
			pq.push_back(y);
			while (!pq.empty()) {
				addPrime();
			}
		}
	};

	for (int i = 0; i < n; ++i) {
		for (int p = 4; p >= 2; --p) {
			if (a[i] == 1) {
				break;
			}
			detectPower(a[i], p);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			continue;
		}
		for (int j = 0; j < i; ++j) {
			auto g = gcd(a[i], a[j]);
			if (g > 1 && g < min(a[i], a[j])) {
				pq.push_back(g);
			}
			while (!pq.empty()) {
				addPrime();
			}
		}
	}

	const int mod = 998244353;
	long long ans = 1;
	map<long long, int> cnt;
	/*for (int i = 0; i < n; ++i) {
		cerr << a[i] << ":";
		for (auto x : divs[i]) {
			cerr << " " << x;
		}
		cerr << "\n";
	}*/
	for (const auto& v : divs) {
		for (auto x : v) {
			cnt[x] += 1;
		}
	}
	for (const auto& [k, v] : cnt) {
		ans = ans * (v + 1) % mod;
	}
	map<long long, int> huita;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 1) {
			huita[a[i]] += 1;
		}
	}
	for (auto [_, c] : huita) {
		ans = ans * (c + 1) * (c + 1) % mod;
	}
	cout << ans << "\n";

	return 0;
}