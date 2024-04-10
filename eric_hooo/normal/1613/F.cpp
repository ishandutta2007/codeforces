#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int RT = 3;
const int N = 1 << 18;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

long long power(long long a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int num[N];
long long W[N | 10], invN;
int t1[N], t2[N];

void PreCalcNTT(int N) {
	invN = power(N, mod - 2);
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
	if (!flag) return ;
	for (int i = 0; i < N; i++) {
		f[i] = f[i] * invN % mod;
	}
}

void polymul(int *f, int n, int *g, int m, int *h) {
	if (n + m - 1 <= 256) {
		for (int i = 0; i < n + m - 1; i++) {
			t1[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ADD(t1[i + j], 1ll * f[i] * g[j] % mod);
			}
		}
		for (int i = 0; i < n + m - 1; i++) {
			h[i] = t1[i];
		}
		return ;
	}
	int N = 1; while (N < n + m - 1) N <<= 1; PreCalcNTT(N);
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

int n;
int deg[250010];
int P[500010];
long long fac[250010];

int Solve(int l, int r) {
	if (l == r) return 2;
	int mid = l + r >> 1;
	int ls = Solve(l, mid), rs = Solve(mid + 1, r);
	polymul(P + l * 2, ls, P + (mid + 1) * 2, rs, P + l * 2);
	return ls + rs - 1;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 250005; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		deg[x]++, deg[y]++;
	}
	int N = 0;
	for (int i = 1; i <= n; i++) {
		if (i != 1) deg[i]--;
		if (deg[i]) P[N << 1] = 1, P[N << 1 | 1] = deg[i], N++;
	}
	int len = Solve(0, N - 1);
	int ans = 0;
	for (int i = 0; i < len; i++) {
		int val = 1ll * P[i] * fac[n - i] % mod;
		if (i & 1) SUB(ans, val);
		else ADD(ans, val);
	}
	printf("%d\n", ans);
	return 0;
}