#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

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

namespace PolyOp {
	const int G = 3;
	int num[1 << 12], t1[1 << 12], t2[1 << 12], lstN;
	long long W[1 << 12 | 10], invN;
	void PreCalcNTT(int N) {
		if (lstN == N) return ; lstN = N, invN = power(N, mod - 2);
		for (int i = 0; i < N; i++) {
			num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
		}
		W[0] = 1, W[1] = power(G, (mod - 1) / N); for (int i = 2; i <= N; i++) W[i] = W[i - 1] * W[1] % mod;
	}
	void NTT(int *f, int N, int flag) {
		PreCalcNTT(N);
		for (int i = 0; i < N; i++) {
			if (i < num[i]) swap(f[i], f[num[i]]);
		}
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
		if (flag) {
			for (int i = 0; i < N; i++) {
				f[i] = f[i] * invN % mod;
			}
		}
	}
	void polymul(int *f, int n, int *g, int m, int *h) {
		int N = 1; while (N < n + m - 1) N <<= 1;
		for (int i = 0; i < N; i++) {
			t1[i] = i < n ? f[i] : 0, t2[i] = i < m ? g[i] : 0;
		}
		NTT(t1, N, 0), NTT(t2, N, 0);
		for (int i = 0; i < N; i++) {
			t1[i] = 1ll * t1[i] * t2[i] % mod;
		}
		NTT(t1, N, 1);
		for (int i = 0; i < n + m - 1; i++) {
			h[i] = t1[i];
		}
	}
}

int n, k;
int a[2010];
int f[110][2010];
long long fac[2010], inv[2010];

long long C(int n, int k) {return fac[n] * inv[k] % mod * inv[n - k] % mod;}

int main() {
	fac[0] = 1; for (int i = 1; i <= 2005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[2005] = power(fac[2005], mod - 2); for (int i = 2004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	f[0][0] = 1;
	int N = 0, l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		// cerr << "   i:" << i << endl;
		static int g[110][2010];
		// for (int j = l; j <= r; j++) {
		// 	int pj = j - l;
		// 	for (int t = N + 1; t >= 0; t--) {
		// 		f[pj][t] = (1ll * f[pj][t] * j + (t ? 1ll * f[pj][t - 1] * t : 0)) % mod;
		// 	}
		// }
		// N++;
		int L = max(0, a[i] - k), R = min(n, a[i] + k);
		L = max(L, l), r = min(r, R);
		if (L > R) {
			printf("0\n");
			return 0;
		}
		static int tmp[2010][2010];
		for (int j = l; j <= r; j++) {
			int pj = j - l, qj = j - L;
			if (qj >= 0 && qj <= R - L) {
				for (int t = 0; t <= N; t++) {
					ADD(g[qj][t], 1ll * f[pj][t] * j % mod);
					ADD(g[qj][t], 1ll * f[pj][t] * t % mod);
					ADD(g[qj][t + 1], f[pj][t]);
				}
			}
			if (j < R) {
				for (int t = 0; t <= N; t++) {
					ADD(tmp[j + 1][t], f[pj][t]);
				}
			}
		}
		for (int j = l + 1; j <= R; j++) {
			int qj = j - L;
			if (qj >= 0 && qj <= R - L) {
				for (int t = 0; t <= N; t++) {
					ADD(g[qj][t], tmp[j][t]);
				}
			}
			if (j < R) {
				for (int t = 1; t <= N; t++) {
					ADD(tmp[j + 1][t - 1], 1ll * tmp[j][t] * t % mod);
				}
				// for (int t = 0; t <= N; t++) {
				// 	tmp[j][t] = tmp[j][t] * fac[t] % mod;
				// }
				// static int qwq[1 << 12]; for (int t = 0; t < N; t++) qwq[t] = inv[N - t];
				// // PolyOp :: polymul(tmp[j], N + 1, qwq, N, qwq);
				// for (int t = 0; t < N; t++) {
				// 	ADD(tmp[j + 1][t], qwq[N + t] * inv[t] % mod);
				// }
				// for (int t = 0; t <= N; t++) {
				// 	for (int tt = 0; tt < t; tt++) {
				// 		ADD(tmp[j + 1][tt], tmp[j][t] * C(t, tt) % mod);
				// 	}
				// }
			}
			for (int t = 0; t <= N; t++) {
				tmp[j][t] = 0;
			}
		}
		l = L, r = R, N++;
		for (int j = l; j <= r; j++) {
			int pj = j - l;
			for (int t = 0; t <= N; t++) {
				f[pj][t] = g[pj][t], g[pj][t] = 0;
			}
		}
	}
	int ans = 0;
	for (int j = l; j <= r; j++) {
		int pj = j - l;
		// ADD(ans, f[pj][0]);
		for (int t = 0; t <= N; t++) {
			// ADD(ans, f[pj][t] * power(n - j, t) % mod);
			ADD(ans, f[pj][t] * C(n - j, t) % mod * fac[t] % mod);
		}
	}
	printf("%d\n", ans);
	return 0;
}