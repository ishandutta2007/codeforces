#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, G = 3;

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
	int t1[1 << 19], t2[1 << 19];
	int num[1 << 19];
	int LSTN;
	long long W[1 << 19 | 10], invN;
	void PreCalcNTT(int N) {
		if (LSTN == N) return ; invN = power(N, mod - 2);
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
					int tmp = *w * *fr % mod;
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
int mu[200010], vis[200010], prime[200010], tot;
long long fac[200010], inv[200010];
int S[1 << 19], t1[200010], t2[200010];

long long Binom(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void PreCalc(int N) {
	fac[0] = 1; for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
	inv[N] = power(fac[N], mod - 2); for (int i = N - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	mu[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, mu[i] = -1;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, mu[i * prime[j]] = -mu[i];
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			}
		}
	}
}

void GetS(int n) {
	for (int i = 0; i <= n; i++) {
		t1[i] = power(i, n) * inv[i] % mod;
		t2[i] = i & 1 ? mod - inv[i] : inv[i];
	}
	PolyOp :: polymul(t1, n + 1, t2, n + 1, S);
}

int main() {
	PreCalc(200005);
	scanf("%d%d", &n, &k);
	if (k == 1 || n == 1) {
		printf("1\n");
		return 0;
	}
	long long ans = 0;
	for (int d = 1; d <= n; d++) {
		int sum = 0;
		int N = (n + d - 1) / d;
		GetS(N);
		for (int i = 2; i <= min(k, N); i++) {
			ADD(sum, S[i]);
		}
		ans = (ans + sum * mu[d] + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}