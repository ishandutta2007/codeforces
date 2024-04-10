#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 33;

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

int dp[N + 10][12][12][12];
int f[12][12][N + 10];
long long fac[N + 10], inv[N + 10];

int GetVal(int *f, int x) {
	if (x <= N) return f[x];
	static int pre[N + 10], suc[N + 10];
	int L = 22, R = N;
	pre[L] = 1; for (int i = L; i < R; i++) pre[i + 1] = 1ll * pre[i] * (x - i + mod) % mod;
	suc[R] = 1; for (int i = R; i > L; i--) suc[i - 1] = 1ll * suc[i] * (x - i + mod) % mod;
	int ans = 0;
	for (int i = L; i <= R; i++) {
		(R - i & 1 ? SUB : ADD)(ans, 1ll * pre[i] * suc[i] % mod * inv[i - L] % mod * inv[R - i] % mod * f[i] % mod);
	}
	return ans;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= N + 5; i++) fac[i] = fac[i - 1] * i % mod;
	inv[N + 5] = power(fac[N + 5], mod - 2); for (int i = N + 4; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	dp[1][0][0][0] = 1, f[0][0][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int p = 0; p <= 11; p++) {
			for (int q = 0; q <= 11; q++) {
				for (int r = 0; r <= 11; r++) {
					if (dp[i][p][q][r]) {
						int val = dp[i][p][q][r];
						ADD(f[p][q][i], val);
						for (int rr = 0; rr <= i; rr++) {
							int pp = p + rr, qq = q + (rr > r);
							if (pp > 11 || qq > 11) break;
							ADD(dp[i + 1][pp][qq][rr], val);
						}
					}
				}
			}
		}
	}
	int T; scanf("%d", &T);
	while (T--) {
		int n, k, x; scanf("%d%d%d", &n, &k, &x);
		printf("%d\n", GetVal(f[k][x], n));
	}
	return 0;
}