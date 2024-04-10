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

const int B = 11;
const int L = 66;
const int M = 1 << B;

long long dp[B][L][M];
long long down_dp[B][L][M][B];

long long solve(int b, long long l, long long r) {
	string s_l = "", s_r = "";
	while (l) {
		s_l += (char)('0' + l % b);
		l /= b;
	}
	// reverse(all(s_l));
	while (r) {
		s_r += (char)('0' + r % b);
		r /= b;
	}
	// reverse(all(s_r));

	int len_l = s_l.length();
	int len_r = s_r.length();
	if (len_l % 2) {
		++len_l;
	}

	long long ans = 0;
	for (int len = len_l; len <= len_r; len += 2) {
		bool left = ((int)s_l.length() == len);
		bool right = ((int)s_r.length() == len);

		vector<int> l(len), r(len, b - 1);
		int idx = len - 1;
		l[idx] = 1;
		if (left) {
			for (int i = 0; i < len; ++i) {
				l[i] = s_l[i] - '0';
			}
		}
		if (right) {
			for (int i = 0; i < len; ++i) {
				r[i] = s_r[i] - '0';
			}
		}

		int mask = 0;
		while (idx >= 0 && l[idx] == r[idx]) {
			mask ^= 1 << l[idx];
			--idx;
		}

		// for (int i = len - 1; i >= 0; --i) {
		// 	cerr << l[i];
		// }
		// cerr << "\n";
		// for (int i = len - 1; i >= 0; --i) {
		// 	cerr << r[i];
		// }
		// cerr << "\n\n";

		if (idx < 0) {
			if (!mask) {
				ans += 1;
			}
			continue;
		}

		for (int d = l[idx] + 1; d < r[idx]; ++d) {
			ans += dp[b][idx][/*__builtin_popcount*/(mask ^ (1 << d))];
		}
		int lmask = mask, rmask = mask;
		for (int i = idx - 1; i >= 0; --i) {
			lmask ^= 1 << l[i + 1];
			rmask ^= 1 << r[i + 1];

			// for (int d = l[i] + 1; d < 10; ++d) {
			// 	ans += dp[b][i][/*__builtin_popcount*/(lmask ^ (1 << d))];
			// }

			ans += down_dp[b][i][lmask][b] - down_dp[b][i][lmask][l[i] + 1];

			// for (int d = 0; d < r[i]; ++d) {
			// 	ans += dp[b][i][/*__builtin_popcount*/(rmask ^ (1 << d))];
			// }

			ans += down_dp[b][i][rmask][r[i]];
		}

		lmask ^= 1 << l[0];
		rmask ^= 1 << r[0];
		ans += dp[b][0][/*__builtin_popcount*/(lmask)];
		ans += dp[b][0][/*__builtin_popcount*/(rmask)];
	}

	return ans;
}

long long stupid(int b, long long l, long long r) {
	long long ans = 0;
	for (long long i = l; i <= r; ++i) {
		long long n = i;
		int mask = 0;
		while (n) {
			mask ^= (1 << (n % b));
			n /= b;
		}
		if (!mask) {
			++ans;
		}
	}
	return ans;
}

int main() {
	for (int b = 2; b <= 10; ++b) {
		dp[b][0][0] = 1;
		for (int pos = 1; pos < L; ++pos) {
			// for (int cnt = 0; cnt < b; ++cnt) {
			// 	dp[b][pos][cnt] += dp[b][pos - 1][cnt + 1] * (cnt + 1);
			// }
			// for (int cnt = 1; cnt <= b; ++cnt) {
			// 	dp[b][pos][cnt] += dp[b][pos - 1][cnt - 1] * (b - cnt);
			// }
			for (int mask = 0; mask < (1 << b); ++mask) {
				for (int d = 0; d < b; ++d) {
					dp[b][pos][mask] += dp[b][pos - 1][mask ^ (1 << d)];
				}
			}
		}

		for (int pos = 0; pos < L; ++pos) {
			for (int mask = 0; mask < (1 << b); ++mask) {
				for (int d = 0; d < b; ++d) {
					down_dp[b][pos][mask][d + 1] = down_dp[b][pos][mask][d] + dp[b][pos][mask ^ (1 << d)];
				}
			}
		}
	}

#if 0
	while (true) {
		int b = 10; // rand() % 9 + 2;
		long long l = rand() % 100 + 1;
		long long r = rand() % 100 + 1;
		if (l > r) {
			swap(l, r);
		}

		long long solve_ans = solve(b, l, r);
		long long stupid_ans = stupid(b, l, r);
		if (solve_ans != stupid_ans) {
			cerr << "\n" << b << " " << l << " " << r << ": got " << solve_ans << ", expected " << stupid_ans << "\n";
			return 0;
		} else {
			cerr << "ok ";
		}
	}
#else
	int q = nxt();
	while (q--) {
		int b = nxt();
		long long l, r;
		scanf("%lld%lld", &l, &r);

		printf("%lld\n", solve(b, l, r));
	}
#endif

	return 0;
}