#include<iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2000;
const int MAXK = 50;

ll choose[MAXN][MAXN];
ll fact[MAXN];

ll dp[MAXK][MAXN];
ll f[MAXK][MAXN][MAXK];

void precomp() {
	for(int i = 0; i < MAXN; i++) {
		choose[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
			if(choose[i][j] >= MOD) choose[i][j] -= MOD;
		}
	}
	fact[0] = 1;
	for(int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	dp[0][0] = 1;
	for(int k = 1; k < MAXK; k++) {
		for(int v = k; v < MAXN; v++) {
			dp[k][v] = dp[k - 1][v - k] + dp[k][v - k];
			if(dp[k][v] >= MOD) dp[k][v] -= MOD;
		}
	}

	for(int k = 1; k < MAXK; k++) {
		f[k][0][0] = 0;
		for(int v = 1; v < MAXN; v++) {
			f[k][v][0] = f[k][v - 1][0] + dp[k][v];
			if(f[k][v][0] >= MOD) f[k][v][0] -= MOD;
		}
		for(int a = 1; a <= k; a++) {
			for(int v = 1; v < MAXN; v++) {
				f[k][v][a] = f[k][v - 1][a] + f[k][v - 1][a - 1];
				if(f[k][v][a] >= MOD) f[k][v][a] -= MOD;
			}
		}
	}
}

ll slow(int n, int k) {
	if(k * (k + 1) / 2 > n) return 0;
	n += k;
	ll res = 0;
	for(int v = 0; v <= n; v++) {
		res += dp[k][v] * choose[n - v][k] % MOD;
		res %= MOD;
	}
	return res * fact[k] % MOD;
}

ll go(int n, int k) {
	if(k * (k + 1) / 2 > n) return 0;
	return f[k][n + k][k] * fact[k] % MOD;
}

int main() {
	precomp();
	/*
	 *for(int n = 1; n <= 2000; n++) {
	 *    for(int k = 1; k <= n; k++) {
	 *        int a = go(n, k);
	 *        int b = slow(n, k);
	 *        if(a != b) cerr << n << ' ' << k << ' ' << a << ' ' << b << '\n';
	 *    }
	 *    cerr << n << '\n';
	 *}
	 */
	int T; cin >> T;
	for(int i = 0; i < T; i++) {
		int n, k; cin >> n >> k;
		cout << go(n, k) << '\n';
	}
}