#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, G = 3;

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
	int t1[1 << 18], t2[1 << 18], num[1 << 18];
	long long W[1 << 18 | 10], invN;
	void PreCalc(int N) {
		invN = power(N, mod - 2);
		for (int i = 0; i < N; i++) {
			num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
		}
		W[0] = 1, W[1] = power(G, (mod - 1) / N); for (int i = 2; i <= N; i++) W[i] = W[i - 1] * W[1] % mod;
	}
	void NTT(int *f, int N, int flag) {
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
		int N = 1; while (N < n + m - 1) N <<= 1; PreCalc(N);
		for (int i = 0; i < N; i++) {
			t1[i] = i < n ? f[i] : 0;
			t2[i] = i < m ? g[i] : 0;
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

using PolyOp :: polymul;

int P[200010], Q[200010];
long long fac[200010], inv[200010];

int main() {
	fac[0] = 1; for (int i = 1; i <= 200005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[0] = 1; for (int i = 1; i <= 200005; i++) inv[i] = power(fac[i], mod - 2);
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i <= k; i++) {
		P[i] = power(i, k) * inv[i] % mod;
		Q[i] = inv[i] * (i & 1 ? mod - 1 : 1) % mod;
	}
	polymul(P, k + 1, Q, k + 1, P);
	long long dw = 1, ans = 0;
	for (int i = 0; i <= k; i++) {
		if (i > n) break;
		ans = (ans + dw * P[i] % mod * power(n + 1, n - i)) % mod;
		dw = dw * (n - i) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}