#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

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

int n;
int a[200010];
long long fac[400010], inv[400010];

long long Binom(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 400005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[400005] = power(fac[400005], mod - 2); for (int i = 400004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ADD(ans, Binom(a[i] - 1 + i + 1, i + 1));
	}
	printf("%d\n", ans);
	return 0;
}