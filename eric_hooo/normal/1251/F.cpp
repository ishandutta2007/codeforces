#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int G = 3;
const int N = 1 << 19;

long long fac[300010], inv[300010], pw[300010];
int a[300010], b[300010], cnt[300010], f[1 << 19], g[1 << 19];
int t1[1 << 19], t2[1 << 19], num[1 << 19];
int ans[1 << 20];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

void NTT(int *a, int N, int *f, int flag) {
	for (int i = 0; i < N; i++) {
		f[i] = a[num[i]];
	}
	for (int len = 2; len <= N; len <<= 1) {
		long long E = power(G, (mod - 1) / len);
		if (flag) E = power(E, mod - 2);
		for (int i = 0; i < N; i += len) {
			long long now = 1;
			for (int j = i; j < i + (len >> 1); j++) {
				long long tmp = f[j + (len >> 1)] * now % mod;
				f[j + (len >> 1)] = f[j] - tmp;
				if (f[j + (len >> 1)] < 0) f[j + (len >> 1)] += mod;
				f[j] = f[j] + tmp;
				if (f[j] >= mod) f[j] -= mod;
				now = now * E % mod;
			}
		}
	}
	if (flag) {
		long long inv = power(N, mod - 2);
		for (int i = 0; i < N; i++) {
			f[i] = f[i] * inv % mod;
		}
	}
}

long long C(int n, int k) {
	if (k > n || k < 0) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	fac[0] = inv[0] = 1, pw[0] = 1;
	for (int i = 1; i <= 300005; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = power(fac[i], mod - 2);
		pw[i] = pw[i - 1] * 2 % mod;
	}
	for (int i = 0; i < N; i++) {
		num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
	}
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for (int it = 0; it < k; it++) {
		int len; scanf("%d", &len);
		int c1 = 0, c2 = 0;
		for (int i = 1; i < len; i++) {
			if (cnt[i] == 1) c1++;
			else if (cnt[i] > 1) c2++;
		}
		memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
		for (int i = 0; i <= c1; i++) {
			f[i] = 1ll * C(c1, i) * pw[i] % mod;
		}
		for (int i = 0; i <= c2 + c2; i++) {
			g[i] = C(c2 + c2, i);
		}
		NTT(f, N, t1, 0), NTT(g, N, t2, 0);
		for (int i = 0; i < N; i++) {
			t1[i] = 1ll * t1[i] * t2[i] % mod;
		}
		NTT(t1, N, t2, 1);
		for (int i = 0; i <= c1 + c2 + c2; i++) {
			if (i + len + 1 <= 600000) ans[i + len + 1] = (ans[i + len + 1] + t2[i]) % mod;
		}
	}
	int q; scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x);
		printf("%d\n", ans[x / 2]);
	}
	return 0;
}