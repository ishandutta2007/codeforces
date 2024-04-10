#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, RT = 3, N = 1 << 19;

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
	int t1[N], t2[N], num[N], LSTN;
	long long W[N | 10], invN;
	void PreCalc(int N) {
		if (LSTN == N) return ;
		LSTN = N, invN = power(N, mod - 2);
		for (int i = 0; i < N; i++) {
			num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
		}
		W[0] = 1, W[1] = power(RT, (mod - 1) / N);
		for (int i = 2; i <= N; i++) {
			W[i] = W[i - 1] * W[1] % mod;
		}
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
	void polycpy(int *f, int n, int *g, int m) {
		for (int i = 0; i < n; i++) {
			f[i] = i < m ? g[i] : 0;
		}
	}
	void polydot(int *f, int *g, int n, int *h) {
		for (int i = 0; i < n; i++) {
			h[i] = 1ll * f[i] * g[i] % mod;
		}
	}
	void polymul(int *f, int n, int *g, int m, int *h) {
		int N = 1; while (N < n + m - 1) N <<= 1; PreCalc(N);
		polycpy(t1, N, f, n), NTT(t1, N, 0);
		polycpy(t2, N, g, m), NTT(t2, N, 0);
		polydot(t1, t2, N, t1), NTT(t1, N, 1);
		polycpy(h, n + m - 1, t1, N);
	}
}

using PolyOp :: polymul;

map <string, int> all;
int n;
char buf[10];
long long fac[200010], inv[200010];
long long a[1000010], ans[1000010];

long long C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 200005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[0] = 1; for (int i = 1; i <= 200005; i++) inv[i] = power(fac[i], mod - 2);
	scanf("%d", &n);
	int hasW = 0, hasB = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		if (buf[1] == 'W') buf[1] = 'B';
		else if (buf[1] == 'B') buf[1] = 'W';
		if (buf[0] == 'W' || buf[1] == 'W') hasW = 1;
		if (buf[0] == 'B' || buf[1] == 'B') hasB = 1;
		all[buf]++;
	}
	int A = all["WB"], B = all["BW"], t = all["??"], a = all["W?"] + all["?B"], b = all["?W"] + all["B?"];
	long long ans = 0;
	for (int delta = -1000000; delta <= 1000000; delta++) {
		if (delta < -a) continue;
		if (delta > b) continue;
		long long coef = C(a + b, b - delta);
		int need = B - A + delta; need = abs(need);
		ans = (ans + coef * C(t + t, need + t)) % mod;
	}
	if (A == 0 && B == 0) {
		long long pw = 1;
		for (int i = 0; i < t; i++) {
			pw = pw * 2 % mod;
		}
		ans = (ans - pw + mod) % mod;
	}
	if (!hasW) ans = (ans + 1) % mod;
	if (!hasB) ans = (ans + 1) % mod;
	printf("%lld\n", ans);
	return 0;
}