#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

const int MAXN = 2007;
int a[MAXN];
int dp[MAXN];
int last[MAXN];

int fact[MAXN];

int mod(int n) {
	return (n % MOD + MOD) % MOD;
}

int fp(int a, int b) {
	if (b == 0) return 1;
	int t = fp(a, b / 2);
	if (b % 2 == 0) return mod(t * t);
	else return mod(mod(t * t) * a);
}

int mdiv(int a, int b) {
	return mod(a * fp(b, MOD - 2));
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mdiv(fact[n], mod(fact[k] * fact[n - k]));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = mod(fact[i - 1] * i);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
		 	int want = a[j] - 1;
		 	last[i] += mod(dp[j] * C(i - j - 1, want));
		 	last[i] %= MOD;
		}
		dp[i + 1] = mod(dp[i] + last[i]);
	}

	cout << mod(dp[n] - 1) << '\n';
    return 0;
}