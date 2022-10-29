#include <stdio.h>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7, MAX_MN = 2e5 + 5, MAX_K = 2e3 + 5;
long long fact[2][MAX_MN], inv[MAX_MN], r[MAX_K], f[MAX_K], ans = 0;
struct tile { int m, n; } B[MAX_K];
bool operator < (tile a, tile b) { return (a.m < b.m || a.m == b.m && a.n < b.n); }
inline long long adj(tile a, tile b, int x) { return (fact[x][a.m - b.m + a.n - b.n] * (fact[1 - x][a.m - b.m] * fact[1 - x][a.n - b.n] % MOD) % MOD); }

int main() {
	for (int i = 0; i < MAX_MN; ++i) {
		fact[0][i] = i == 0 ? 1 : fact[0][i - 1] * i % MOD;
		fact[1][i] = i == 0 ? 1 : fact[1][i - 1] * (inv[i] = i == 1 ? 1 : (MOD * MOD - MOD / i * inv[MOD % i]) % MOD) % MOD;
	}
	int m, n, b, s; scanf("%d%d%d%d", &m, &n, &b, &s);
	B[0] = (tile) {1, 1};
	B[b + 1] = (tile) {m, n};
	for (int i = 1; i <= b; ++i) 
		scanf("%d%d", &B[i].m, &B[i].n);
	sort(B + 1, B + b + 1);
	for (int i = 1; i <= b + 1; ++i) 
		r[i] = adj(B[i], B[0], 0);
	for (; s > 1; s -= s >> 1) {
		for (int i = 1; i <= b + 1; ++i) {
			f[i] = r[i];
			for (int j = 1; j < i; ++j) 
				(f[i] += (B[j].n <= B[i].n ? MOD * MOD - f[j] * adj(B[i], B[j], 0) : 0)) %= MOD;
			(r[i] += MOD - f[i]) %= MOD;
		}
		(ans += s * f[b + 1]) %= MOD;
	}
	printf("%I64d", (ans + r[b + 1]) * adj(B[b + 1], B[0], 1) % MOD);
	return 0;
}