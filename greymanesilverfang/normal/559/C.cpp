#include <stdio.h>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7, MAX_MN = 200001, MAX_K = 2001;
long long fact[MAX_MN], invf[MAX_MN], inv[MAX_MN], f[MAX_K];

struct tile { int m, n; } B[MAX_K];
bool operator < (tile a, tile b) { return (a.m < b.m || a.m == b.m && a.n < b.n); }

long long C (int a, int b) { return (fact[a + b] * (invf[a] * invf[b] % MOD) % MOD); }

int main() {
	for (int i = 0; i < MAX_MN; ++i) {
		fact[i] = i == 0 ? 1 : fact[i - 1] * i % MOD;
		invf[i] = i == 0 ? 1 : invf[i - 1] * (inv[i] = i == 1 ? 1 : (MOD * MOD - MOD / i * inv[MOD % i]) % MOD) % MOD;
	}
	int m, n, k; scanf("%d%d%d", &m, &n, &k);
	B[k] = (tile) {m, n};
	for (int i = 0; i < k; ++i)
		scanf("%d%d", &B[i].m, &B[i].n);
	sort(B, B + k);
	for (int i = 0; i <= k; ++i) {
		f[i] = C(B[i].m - 1, B[i].n - 1);
		for (int j = 0; j < i; ++j)
			(f[i] += (B[j].n <= B[i].n ? MOD * MOD - f[j] * C(B[i].m - B[j].m, B[i].n - B[j].n) : 0)) %= MOD;
	}
	printf("%I64d", f[k]);
}