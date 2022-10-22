#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

string s;
long long f[100010];
long long fac[100010], inv[100010], pw[100010];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long C(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	fac[0] = inv[0] = 1, pw[0] = 1;
	for (int i = 1; i <= 100005; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = power(fac[i], mod - 2);
		pw[i] = pw[i - 1] * 10 % mod;
	}
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		f[i] = C(n - i - 2, k - 1) * pw[i] % mod;
	}
	for (int i = 1; i < n; i++) {
		f[i] = (f[i - 1] + f[i]) % mod;
	}
	cin >> s;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x = s[i] - '0', len = n - i - 2;
		if (len >= 0) ans = (ans + 1ll * x * f[len]) % mod;
		ans = (ans + 1ll * C(i, k) * x % mod * pw[n - i - 1] % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}