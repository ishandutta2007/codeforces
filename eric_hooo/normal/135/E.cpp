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

long long fac[1000010], inv[1000010];
int sum[1000010];
int k, w;

long long A(int n, int k) {
	return k < 0 || k > n ? 0 : fac[n] * inv[n - k] % mod;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 1000005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[0] = 1; for (int i = 1; i <= 1000005; i++) inv[i] = power(fac[i], mod - 2);
	scanf("%d%d", &k, &w);
	int ans = 0;
	auto Calc = [&](int x, int y) -> int {
		if (x > y) swap(x, y);
		if (y + 1 <= w) return fac[k] * inv[k - x] % mod * fac[k] % mod * inv[k - y] % mod * power(k, w - y - 1) % mod;
		return 0;
	};
	for (int i = 1; i <= k; i++) {
		sum[i] = i + 2 <= w ? 1ll * fac[k] * inv[k - i] % mod * power(k, w - i - 2) % mod * i % mod : 0;
	}
	for (int i = k; i >= 1; i--) {
		ADD(sum[i], sum[i + 1]);
	}
	for (int i = 1; i <= k; i++) {
		ADD(ans, 1ll * fac[k] * inv[k - i] % mod * i % mod * sum[i] % mod);
		ADD(ans, 1ll * fac[k] * inv[k - i] % mod * i % mod * sum[i + 1] % mod);
	}
	if (w < k + 2) {
		auto GetSum = [&](int l, int r) -> int {return l > r ? 0 : (sum[l] - sum[r + 1] + mod) % mod;};
		for (int i = 1; i <= k; i++) {
			int j = w - 1, coef = i < j ? 2 : i == j ? 1 : 0;
			ADD(ans, 1ll * coef * fac[k] * inv[k - i] % mod * i % mod * (w - 1) % mod * fac[k - 1] % mod * inv[k - w + 1] % mod);
		}
		for (int i = k; i >= 0; i--) {
			sum[i] = A(k - i - 1, w - 1);
			ADD(sum[i], sum[i + 1]);
		}
		for (int i = 1; i <= k; i++) {
			ADD(ans, 1ll * A(k, i) * GetSum(max(0, i - w), i - 1) % mod);
			ADD(ans, 1ll * A(k, i) * GetSum(max(0, i - w + 1), i - 1) % mod);
		}
		for (int i = k; i >= 0; i--) {
			sum[i] = 1ll * A(k - i - 2, w - 2) * (w - 1) % mod;
			ADD(sum[i], sum[i + 1]);
		}
		for (int i = 1; i <= k; i++) {
			ADD(ans, 1ll * A(k, i) * (i - 1) % mod * GetSum(max(0, i - w), i - 1) % mod);
			ADD(ans, 1ll * A(k, i) * (i - 1) % mod * GetSum(max(0, i - w + 1), i - 1) % mod);
		}
		for (int i = k; i >= 0; i--) {
			sum[i] = 1ll * A(k - i - 2, w - 2) * (w - 1) % mod * i % mod;
			ADD(sum[i], sum[i + 1]);
		}
		for (int i = 1; i <= k; i++) {
			SUB(ans, 1ll * A(k, i) * GetSum(max(0, i - w), i - 1) % mod);
			SUB(ans, 1ll * A(k, i) * GetSum(max(0, i - w + 1), i - 1) % mod);
		}
	}
	printf("%d\n", ans);
	return 0;
}