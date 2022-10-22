#include <bits/stdc++.h>
#define rep(x, l, r) for (int (x) = (l); (x) < (r); (x)++)
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

long long inv[50010];

namespace PolyOp {
	const int G = 3;
	int num[1 << 17], t1[1 << 17], t2[1 << 17], t3[1 << 17];
	long long W[1 << 17 | 1];
	int LSTN; long long invN;
	void PreCalcNTT(int N) {
		if (LSTN == N) return ; LSTN = N, invN = power(N, mod - 2);
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
		rep(i, 0, N) t1[i] = i < n ? f[i] : 0, t2[i] = i < m ? g[i] : 0;
		NTT(t1, N, 0), NTT(t2, N, 0);
		rep(i, 0, N) t1[i] = 1ll * t1[i] * t2[i] % mod;
		NTT(t1, N, 1);
		rep(i, 0, n + m - 1) h[i] = t1[i];
	}
	void polyinv(int *f, int n, int *g) {
		if (n == 1) {g[0] = power(f[0], mod - 2); return ;}
		int mid = n + 1 >> 1; polyinv(f, mid, g);
		int N = 1; while (N < mid + mid + n - 2) N <<= 1;
		for (int i = 0; i < N; i++) {
			t1[i] = i < mid ? g[i] : 0, t2[i] = i < n ? f[i] : 0;
		}
		NTT(t1, N, 0), NTT(t2, N, 0);
		for (int i = 0; i < N; i++) {
			t1[i] = 1ll * t1[i] * t1[i] % mod * t2[i] % mod;
		}
		NTT(t1, N, 1);
		for (int i = 0; i < n; i++) {
			g[i] = ((i < mid ? g[i] : 0) * 2ll - t1[i] + mod) % mod;
		}
	}
	void polyln(int *f, int n, int *g) {
		polyinv(f, n, t3);
		rep(i, 0, n - 1) g[i] = 1ll * f[i + 1] * (i + 1) % mod;
		polymul(t3, n, g, n - 1, t3);
		rep(i, 0, n) g[i] = i ? t3[i - 1] * power(i, mod - 2) % mod : 0;
	}
}

using PolyOp :: polymul;
using PolyOp :: polyinv;
using PolyOp :: polyln;

int n, m, M;
int coef[1 << 17];
int A[1 << 17], B[1 << 17], C[1 << 17], D[1 << 17], E[1 << 17], ans[1 << 17], res[1 << 17];
long long fac[50010], ifc[50010];
long long suc[100010], isu[100010];

long long GetProd(int l, int r) {
	return suc[l - M + 50000] * isu[r + 1 - M + 50000] % mod;
}

long long binom(int n, int k) {
	if (n < 0) return 0;
	if (k < 0 || k > n) return 0;
	return GetProd(n - k + 1, n) * ifc[k] % mod;
}

void PreCalc() {
	M = m >> 1;
	for (int i = 0; i <= 100005; i++) {
		suc[i] = (M - 50000 + i + mod) % mod;
	}
	for (int i = 100004; i >= 0; i--) {
		suc[i] = suc[i] * suc[i + 1] % mod;
	}
	for (int i = 0; i <= 100005; i++) {
		isu[i] = power(suc[i], mod - 2);
	}
	for (int i = 0; i <= 50005; i++) {
		inv[i] = power(i, mod - 2);
	}
	fac[0] = 1; for (int i = 1; i <= 50005; i++) fac[i] = fac[i - 1] * i % mod;
	ifc[0] = 1; for (int i = 1; i <= 50005; i++) ifc[i] = power(fac[i], mod - 2);
}

int main() {
	cin >> n >> m;
	PreCalc();
	for (int i = 1; i <= n; i++) {
		coef[i] = binom((m + (i & 1) >> 1) - 1 + i - (i - 1) / 2, i);
	}
	for (int i = 1; i <= n; i++) {
		A[i] = 1ll * (i % 2 == 0 ? coef[i] : 0) * (i & 2 ? 1 : mod - 1) % mod;
		B[i] = 1ll * (i % 2 == 1 ? coef[i] : 0) * (i & 2 ? mod - 1 : 1) % mod;
	}
	A[0] = (mod + 1 - A[0]) % mod;
	for (int i = 1; i <= n; i++) {
		A[i] = (mod - A[i]) % mod;
	}
	polyinv(A, n + 1, C), polymul(C, n + 1, B, n + 1, D);
	D[0] = (mod + 1 - D[0]) % mod;
	rep(i, 1, n + 1) D[i] = (mod - D[i]) % mod;
	polyinv(D, n + 1, E);
	polyln(C, n + 1, ans), polyln(E, n + 1, res);
	rep(i, 0, n + 1) ADD(ans[i], res[i]);
	printf("%lld\n", 1ll * ans[n] * n % mod);
	return 0;
}