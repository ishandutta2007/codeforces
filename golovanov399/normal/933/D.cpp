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

const int N = 1111111;
long long sum[4][N];
const int mod = 1000000007;

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long solve(long long m) {
	long long r = sqrt(m);
	while (r * r <= m) {
		++r;
	}

	long long c0 = (m % mod) * ((m + 1) % mod) % mod * ((2 * m + 1) % mod) % mod * pw(12, mod - 2) % mod + m % mod * ((m + 1) % mod) % mod * pw(4, mod - 2) % mod;
	c0 %= mod;
	long long c1 = m % mod * pw(2, mod - 2) % mod + 2 * pw(3, mod - 2) % mod;
	c1 %= mod;
	long long c2 = mod - (m % mod * pw(2, mod - 2) % mod + 1) % mod;
	c2 %= mod;
	long long c3 = pw(3, mod - 2) % mod;

	long long ans = 0;
	for (long long l = 0; l * l <= m; ++l) {
		while (l * l + r * r > m) {
			--r;
		}
		long long tmp = 0;

		long long cur[4];
		for (int d = 0; d <= 3; ++d) {
			cur[d] = pw(l * l % mod, d);
		}
		tmp += c3 * ((cur[3] * sum[0][r] + cur[2] * sum[1][r] % mod * 3 + cur[1] * sum[2][r] % mod * 3 + cur[0] * sum[3][r]) % mod) % mod;
		tmp += c2 * ((cur[2] * sum[0][r] + cur[1] * sum[1][r] % mod * 2 + cur[0] * sum[2][r] % mod) % mod) % mod;
		tmp += c1 * ((cur[1] * sum[0][r] + cur[0] * sum[1][r] % mod) % mod) % mod;
		tmp += c0 * ((cur[0] * sum[0][r]) % mod) % mod;
		tmp %= mod;

		if (l) {
			tmp *= 2;
		}
		ans += tmp;
	}

	return ans % mod;
}

long long stupid(long long m) {
	long long ans = 0;
	for (long long l = -m; l <= m; ++l) {
		for (long long r = -m; r <= m; ++r) {
			if (l * l + r * r > m) {
				continue;
			}
			for (int i = l * l + r * r; i <= m; ++i) {
				ans += i * (m - i + 1);
			}
		}
	}
	return ans % mod;
}

int main() {
	sum[0][0] = 1;
	for (int d = 0; d <= 3; ++d) {
		for (int i = 1; i < N; ++i) {
			sum[d][i] = (sum[d][i - 1] + 2 * pw(1ll * i * i % mod, d)) % mod;
		}
	}

	long long m;
	cin >> m;
	cout << solve(m) << "\n";

	// for (int m = 1;; ++m) {
	// 	long long q = solve(m);
	// 	long long w = stupid(m);
	// 	if (q != w) {
	// 		cerr << m << " " << q << " " << w << "\n";
	// 		return 0;
	// 	} else {
	// 		cerr << "ok ";
	// 	}
	// }

	// while (true) {
	// 	long long m = (((rand() * 1ll) << 30) + rand()) % 1000000000000ll;
	// 	long long q = solve(m);
	// 	if (q < 0 || q >= mod) {
	// 		cout << m << ": " << q << "\n";
	// 		return 0;
	// 	} else {
	// 		cerr << "ok ";
	// 	}
	// }

	return 0;
}