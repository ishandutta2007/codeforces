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

inline long long nxt() {
	long long x;
	scanf("%lld", &x);
	return x;
}

template <int N>
array<int, N> genErat() {
	array<int, N> erat;
	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
	}
	return erat;
}

const int N = 1111111;
int erat[N];
vector<int> primes;
int ans = N;

void relax(const map<long long, int>& M, long long p) {
	long long cur = 0;
	for (const auto& [x, c] : M) {
		long long y = x % p;
		if (p - y < y || x == y) {
			y = p - y;
		}
		cur += y * c;
		if (cur >= ans) {
			return;
		}
	}
	ans = cur;
}

long long err[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	vector<int> primes;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			primes.push_back(i);
			erat[i] = i;
		}
		for (int p : primes) {
			if (p > erat[i] || i * p >= N) {
				break;
			}
			if (erat[i * p] == 0) {
				erat[i * p] = p;
			}
		}
	}
	
	int n = nxt();
	map<long long, int> M;
	for (int i = 0; i < n; ++i) {
		M[nxt()] += 1;
	}

	for (int p : primes) {
		relax(M, p);
	}

	long long mn = M.begin()->first;
	mn = max(mn - n - 5, 1ll);
	int cnt = 2 * n + 10;
	iota(err, err + cnt, mn);
	for (int p : primes) {
		long long i = mn - mn % p;
		if (i < mn) {
			i += p;
		}
		while (i < mn + cnt) {
			while (err[i - mn] % p == 0) {
				err[i - mn] /= p;
			}
			i += p;
		}
	}
	for (int i = 0; i < cnt; ++i) {
		if (err[i] > 1) {
			relax(M, err[i]);
		}
	}

	cout << ans << "\n";

	return 0;
}