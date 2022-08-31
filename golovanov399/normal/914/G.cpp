#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1 << 17;
const int mod = 1000000007;
long long fib[N];
long long f1[N];
long long f2[N];
long long f3[N];

void xorwh(long long* b, long long* e) {
	if (e == b + 1) {
		return;
	}
	long long *m = b + (e - b) / 2;
	xorwh(b, m);
	xorwh(m, e);
	while (m != e) {
		long long x = *b, y = *m;
		*b = (x + y) % mod;
		*m = (x - y + mod) % mod;
		++b, ++m;
	}
}

void andwh(long long* b, long long* e, bool inverse = false) {
	if (e == b + 1) {
		return;
	}
	long long *m = b + (e - b) / 2;
	andwh(b, m, inverse);
	andwh(m, e, inverse);
	while (m != e) {
		long long x = inverse ? mod - *m : *m;
		*b += x;
		if (*b >= mod) {
			*b -= mod;
		}
		++b, ++m;
	}
}

int main() {
	fib[1] = 1;
	for (int i = 2; i < N; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= mod) {
			fib[i] -= mod;
		}
	}

	int n = nxt();
	while (n--) {
		f2[nxt()] += 1;
	}

	for (int mask = 0; mask < N; ++mask) {
		int cnt = f2[mask];
		if (!cnt) {
			continue;
		}
		int mm = (N - 1) ^ mask;
		for (int m = mm; m; m = (m - 1) & mm) {
			f1[mask | m] += cnt * f2[m] % mod;
		}
		f1[mask] += f2[mask] * f2[0] % mod;
	}
	for (int i = 0; i < N; ++i) {
		f1[i] %= mod;
	}

	memcpy(f3, f2, sizeof(f2));
	xorwh(f3, f3 + N);
	for (int i = 0; i < N; ++i) {
		f3[i] = f3[i] * f3[i] % mod;
	}
	xorwh(f3, f3 + N);
	int inv = 1;
	for (int i = 0; i < __builtin_ctz(N); ++i) {
		if (inv & 1) {
			inv += mod;
		}
		inv /= 2;
	}
	for (int i = 0; i < N; ++i) {
		f3[i] = f3[i] * inv % mod;
	}

	// for (int i = 0; i < N; ++i) {
	// 	if (f1[i]) {
	// 		cerr << "there are " << f1[i] << " disjoint unions equal to " << i << "\n";
	// 	}
	// }
	// for (int i = 0; i < N; ++i) {
	// 	if (f2[i]) {
	// 		cerr << "there are " << f2[i] << " elements equal to " << i << "\n";
	// 	}
	// }
	// for (int i = 0; i < N; ++i) {
	// 	if (f3[i]) {
	// 		cerr << "there are " << f3[i] << " xors equal to " << i << "\n";
	// 	}
	// }

	for (int i = 0; i < N; ++i) {
		f1[i] = f1[i] * fib[i] % mod;
		f2[i] = f2[i] * fib[i] % mod;
		f3[i] = f3[i] * fib[i] % mod;
	}

	andwh(f1, f1 + N);
	andwh(f2, f2 + N);
	andwh(f3, f3 + N);

	for (int i = 0; i < N; ++i) {
		f1[i] = f1[i] * f2[i] % mod;
		f1[i] = f1[i] * f3[i] % mod;
	}

	andwh(f1, f1 + N, true);

	long long ans = 0;
	for (int i = 1; i < N; i *= 2) {
		ans += f1[i];
	}
	cout << ans % mod << "\n";

	return 0;
}