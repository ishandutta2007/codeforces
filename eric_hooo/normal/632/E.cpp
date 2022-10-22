#include <bits/stdc++.h>
#define rnd() (rand() << 15 | rand())
using namespace std;

const int N = 1 << 20;
const int mod = 998244353;
const int G = 3;

int f[1 << 20], t1[1 << 20];
int num[1 << 20];

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
				long long tmp = now * f[j + (len >> 1)] % mod;
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

int main () {
	srand((int)time(NULL)), rnd(), rnd(), rnd();
	for (int i = 0; i < N; i++) {
		num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
	}
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		f[x] = rnd() % mod;
	}
	NTT(f, N, t1, 0);
	for (int i = 0; i < N; i++) {
		t1[i] = power(t1[i], k);
	}
	NTT(t1, N, f, 1);
	for (int i = 0; i < N; i++) {
		if (f[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}