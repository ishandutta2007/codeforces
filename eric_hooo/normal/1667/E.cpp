#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

namespace PolyOp {
	const int G = 3;
	int num[1 << 19], t1[1 << 19], t2[1 << 19], lstN;
	long long W[1 << 19 | 10], invN;
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

int n;
long long fac[200010], inv[200010];
int f[200010], g[200010];

long long C(int n, int k) {return fac[n] * inv[k] % mod * inv[n - k] % mod;}

int main() {
	fac[0] = 1; for (int i = 1; i <= 200005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[0] = 1; for (int i = 1; i <= 200005; i++) inv[i] = power(fac[i], mod - 2);
	scanf("%d", &n);
	int k = n - 1 >> 1;
	static int t1[200010], t2[200010], t3[1 << 19];
	for (int j = k + 1; j < n; j++) {
		t1[j] = fac[n - j - 1];
	}
	for (int j = 0; j <= n; j++) {
		t2[j] = inv[j];
	}
	PolyOp :: polymul(t1, n + 1, t2, n + 1, t3);
	for (int i = 2; i <= n; i++) {
		f[i] = t3[n - i + 1];
		// for (int j = k + 1; j <= n - i + 1; j++) {
		// 	ADD(f[i], 1ll * inv[n - i + 1 - j] % mod * fac[n - j - 1] % mod);
		// }
		f[i] = 1ll * f[i] * (i - 1) % mod * fac[n - i] % mod;
	}
	f[1] = fac[n - 1];
	int sum = 0;
	for (int i = n; i >= 1; i--) {
		SUB(f[i], sum * power(i, mod - 2) % mod);
		ADD(sum, f[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", f[i]);
	}
	printf("\n");
	return 0;
}