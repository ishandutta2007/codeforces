#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int a[5010];
int dp[5010][5010];
int inv[5010], nxt[5010];
int cnt[5010];
int sum[5010];

int power(int a, int b){
	if (!b) return 1;
	long long t = power(a, b >> 1);
	return b & 1 ? t * t % mod * a % mod : t * t % mod;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for (int j = 1; j <= n; j++){
		inv[j] = power(j, mod - 2);
		assert(1ll * j * inv[j] % mod == 1);
	}
	dp[0][0] = 1, dp[0][1] = -1;
	int ans = 0;
	cnt[0] = 1;
	for (int i = 0; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			int val = 1ll * dp[i][j] * cnt[j] % mod;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 1ll * val * inv[n - i]) % mod;
			ans = (ans + 1ll * val * inv[n - i] % mod * (cnt[j] - 1)) % mod;
//			cout << "pos:" << i << " " << j << endl;
//			cout << "  val:" << 1ll * val * inv[n - i] % mod * (cnt[j] - 1) % mod << endl;
//			cout << "  dp:" << val << endl;
		}
	}
//	cout << dp[2][3] * 2 % mod << endl;
	printf("%d\n", ans);
	return 0;
}