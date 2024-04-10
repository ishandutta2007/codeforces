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

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

u32 mod;
u64 bar;

u32 reduce(u64 a) {
	u32 res = a - (((u128)a * bar) >> 64) * mod;
	return res - (res >= mod ? mod : 0);
}

const int N = 111;
u32 dp[N][N][N];
u64 C[N][N];

void add(u32& x, u32 y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

u64 fact[N];

void solve() {
	int n = nxt(), m = nxt(), k = nxt(), p = nxt();
	mod = p;
	bar = -1ull / p;
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < N; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= mod) {
				C[i][j] -= mod;
			}
		}
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = reduce(fact[i - 1] * i);
	}
	for (int im = 1; im <= m; ++im) {
		for (int in = 0; in <= n; ++in) {
			for (int ik = 0; ik <= k; ++ik) {
				if (in == 0) {
					dp[im][in][ik] = (ik == 0);
					continue;
				}
				if (im == 1) {
					dp[im][in][ik] = (ik == 1) ? fact[in] : 0;
					continue;
				}
				if (ik > 0 && in < ik + im - 1) {
					continue;
				}
				for (int nl = 0; nl < in; ++nl) {
					const int nr = in - nl - 1;
					for (int kl = 0; kl <= ik; ++kl) {
						const int kr = ik - kl;
						add(dp[im][in][ik], reduce(reduce((u64)dp[im - 1][nl][kl] * dp[im - 1][nr][kr]) * C[in - 1][nl]));
					}
				}
			}
		}
	}
	cout << dp[m][n][k] << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}