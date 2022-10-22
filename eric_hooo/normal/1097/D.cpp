#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long dp[10010][60];
int k;

int power(long long a, long long b){
	if (!b) return 1;
	long long t = power(a, b / 2);
	return b & 1 ? t * t % mod * a % mod : t * t % mod;
}

int inv(int x){
	return power(x, mod - 2);
}

long long DP(long long p, int e){
	p %= mod;
	memset(dp, 0, sizeof(dp));
	dp[0][e] = 1;
	for (int i = 1; i <= k; i++){
		for (int j = e; j >= 0; j--){
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j] * inv(j + 1) % mod) % mod;
		}
	}
	long long pw = 1;
	long long res = 0;
	for (int i = 0; i <= e; i++){
		res = (res + pw * dp[k][i] % mod) % mod;
		pw = pw * p % mod;
	}
	return res;
}

int main(){
	long long n;
	scanf("%I64d%d", &n, &k);
	long long res = 1;
	for (long long i = 2; i * i <= n; i++){
		if (n % i != 0) continue;
		int cnt = 0;
		while (n % i == 0) n /= i, cnt++;
//		cout << "  " << i << " " << cnt << endl;
		res = res * DP(i, cnt) % mod;
	}
	if (n > 1) res = res * DP(n, 1) % mod;
	printf("%I64d\n", res);
	return 0;
}