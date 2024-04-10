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

int n, m, k, p;
int coef[1510], csum[1510];
long long fac[100010], inv[100010];
int pre[1510], suc[1510], npr[1510], nsu[1510], spr[1510], ssu[1510];

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 100005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[0] = 1; for (int i = 1; i <= 100005; i++) inv[i] = power(fac[i], mod - 2);
	int A, B;
	cin >> n >> m >> A >> B >> k;
	p = A * power(B, mod - 2) % mod;
	for (int i = 0; i <= 1505; i++) {
		if (i > k) break;
		coef[i] = C(k, i) * power(p, i) % mod * power(1 - p + mod, k - i) % mod;
	}
	for (int i = 0; i <= 1505; i++) {
		csum[i] = coef[i];
		if (i) ADD(csum[i], csum[i - 1]);
	}
	npr[m] = 1, nsu[1] = 1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int i = 1; i <= m; i++) {
			pre[i] = npr[i];
			suc[i] = nsu[i];
			ADD(sum, pre[i]);
		}
		for (int i = 1; i <= m; i++) {
			assert(pre[i] == npr[i]);
			assert(suc[i] == nsu[i]);
		}
		for (int i = 1; i <= m; i++) {
			ADD(pre[i], pre[i - 1]);
		}
		for (int i = m; i >= 1; i--) {
			ADD(suc[i], suc[i + 1]);
		}
		for (int l = 1; l <= m; l++) {
			spr[l] = 1ll * pre[l - 1] * coef[l - 1] % mod;
			ADD(spr[l], spr[l - 1]);
		}
		for (int r = m; r >= 1; r--) {
			ssu[r] = 1ll * suc[r + 1] * coef[m - r] % mod;
			ADD(ssu[r], ssu[r + 1]);
		}
		for (int i = 1; i <= m; i++) {
			npr[i] = 1ll * (sum - suc[i + 1] + mod) * csum[i - 1] % mod;
			SUB(npr[i], spr[i]);
			npr[i] = 1ll * npr[i] * coef[m - i] % mod;
			nsu[i] = 1ll * (sum - pre[i - 1] + mod) * csum[m - i] % mod;
			SUB(nsu[i], ssu[i]);
			nsu[i] = 1ll * nsu[i] * coef[i - 1] % mod;
		}
	}
	int sum = 0;
	for (int l = 1; l <= m; l++) {
		ADD(sum, npr[l]);
	}
	printf("%d\n", sum);
	return 0;
}