#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

template <const int mod, const int G>
struct DS {
	void ADD(int &x, int y) {
		x += y;
		if (x >= mod) x -= mod;
	}
	void SUB(int &x, int y) {
		x -= y;
		if (x < 0) x += mod;
	}
	long long power(long long a, int b) {
		long long ans = 1;
		while (b) {
			if (b & 1) ans = ans * a % mod;
			a = a * a % mod, b >>= 1;
		}
		return ans;
	}
	void NTT(int *f, int N, int flag) {
		static int lstN, num[1 << 18];
		static long long invN, W[1 << 18 | 10];
		if (lstN != N) {
			lstN = N, invN = power(N, mod - 2);
			; for (int i = 0; i < N; i++) num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
			W[0] = 1, W[1] = power(G, (mod - 1) / N); for (int i = 2; i <= N; i++) W[i] = W[i - 1] * W[1] % mod;
		}
		; for (int i = 0; i < N; i++) if (i < num[i]) swap(f[i], f[num[i]]);
		for (int len = 2; len <= N; len <<= 1) {
			for (int i = 0; i < N; i += len) {
				int *fl = f + i, *fr = fl + len / 2, step = flag ? -N / len : N / len;
				long long *w = flag ? W + N : W;
				for (int j = 0; j < len / 2; j++) {
					int tmp = *fr * *w % mod;
					SUB(*fr = *fl, tmp), ADD(*fl, tmp);
					fl++, fr++, w += step;
				}
			}
		}
		if (flag) for (int i = 0; i < N; i++) f[i] = f[i] * invN % mod;
	}
	int polymul(int *f, int n, int *g, int m, int *h) {
		if (!n || !m) return 0;
		int N = 1; while (N < n + m - 1) N <<= 1;
		static int t1[1 << 18], t2[1 << 18];
		; for (int i = 0; i < N; i++) t1[i] = i < n ? f[i] : 0, t2[i] = i < m ? g[i] : 0;
		NTT(t1, N, 0), NTT(t2, N, 0);
		; for (int i = 0; i < N; i++) t1[i] = 1ll * t1[i] * t2[i] % mod;
		NTT(t1, N, 1);
		; for (int i = 0; i < n + m - 1; i++) h[i] = t1[i];
		return n + m - 1;
	}
};

DS <998244353, 3> ds1;
DS <1004535809, 3> ds2;
DS <469762049, 3> ds3;

__int128 StrToInt(string s) {
	__int128 x = 0;
	for (int i = 0; i < s.size(); i++) {
		x = x * 10 + s[i] - '0';
	}
	return x;
}

namespace PolyOp {
	const __int128 C1 = StrToInt("401276874248923522479908641");
	const __int128 C2 = StrToInt("185347017962817624218731910");
	const __int128 C3 = StrToInt("355504753290647734883291996");
	int CRT(int x, int y, int z) {
		return (x * C1 + y * C2 + z * C3) % StrToInt("471064322751194440790966273") % mod;
	}
	void _polymul(int *f, int n, int *g, int m, int *h) {
		static int tmp[1 << 16];
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			ADD(tmp[i + j], 1ll * f[i] * g[j] % mod);
		}
		for (int i = 0; i < n + m - 1; i++) {
			h[i] = tmp[i], tmp[i] = 0;
		}
	}
	void polymul(int *f, int n, int *g, int m, int *h) {
		static int h1[1 << 16], h2[1 << 16], h3[1 << 16];
		int N = n + m - 1;
		ds1.polymul(f, n, g, m, h1);
		ds2.polymul(f, n, g, m, h2);
		ds3.polymul(f, n, g, m, h3);
		for (int i = 0; i < N; i++) {
			h[i] = CRT(h1[i], h2[i], h3[i]);
		}
	}
}

int n, k;
long long fac[30010], inv[30010];

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	fac[0] = 1; for (int i = 1; i <= 30005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[30005] = power(fac[30005], mod - 2); for (int i = 30004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	{
		long long tmp; scanf("%lld%d", &tmp, &k);
		if (tmp > k) {
			printf("0\n");
			return 0;
		}
		n = tmp;
	}
	if (0 && n <= 300 && k <= 300) {
		static int f[310];
		memset(f, 0, sizeof(f));
		f[0] = fac[k];
		for (int i = 1; i <= n; i++) {
			static int g[310]; memset(g, 0, sizeof(g));
			int val = power(2, n - i);
			for (int p = 0; p <= k; p++) {
				long long pw = 1;
				for (int q = p + 1; q <= k; q++) {
					pw = pw * val % mod;
					ADD(g[q], 1ll * f[p] * inv[q - p] % mod * pw % mod);
				}
			}
			memcpy(f, g, sizeof(f));
		}
		int ans = 0; for (int i = 0; i <= k; i++) ADD(ans, 1ll * f[i] * inv[k - i] % mod);
		printf("%d\n", ans);
	} else {
		static int f[30010], g[30010];
		; for (int i = 1; i <= k; i++) f[i] = inv[i];
		; for (int i = 0; i <= k; i++) g[i] = i == 0;
		int sf = 1, sg = 0;
		auto Merge = [&](int *f, int sf, int *g, int sg, int *h, int &sh) -> void {
			static int tmp[1 << 16]; int stmp = sf + sg;
			long long mul = power(2, sg), pw = 1;
			; for (int i = 0; i <= k; i++) tmp[i] = f[i] * pw % mod, pw = pw * mul % mod;
			PolyOp :: polymul(tmp, k + 1, g, k + 1, tmp);
			sh = stmp;
			; for (int i = 0; i <= k; i++) h[i] = tmp[i];
		};
		for (int it = 0; it < 15; it++) {
			if (n >> it & 1) Merge(f, sf, g, sg, g, sg);
			Merge(f, sf, f, sf, f, sf);
		}
		int ans = 0; for (int i = 0; i <= k; i++) ADD(ans, 1ll * g[i] * inv[k - i] % mod);
		ans = ans * fac[k] % mod;
		printf("%d\n", ans);
	}
	return 0;
}