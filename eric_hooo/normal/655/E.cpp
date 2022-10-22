#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char s[1000010];
int last[26];
long long dp[2000010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int m = strlen(s + 1);
	memset(last, -1, sizeof(last));
	dp[0] = 1;
	for (int i = 1; i <= m; i++){
		dp[i] = dp[i - 1] * 2 % mod;
		if (~last[s[i] - 'a']) dp[i] = (dp[i] - dp[last[s[i] - 'a'] - 1] + mod) % mod;
		last[s[i] - 'a'] = i;
	}
	for (int i = 1 + m; i <= n + m; i++){
		int pos = -1;
		for (int j = 0; j < k; j++){
			if (pos == -1 || last[pos] > last[j]) pos = j;
		}
		dp[i] = dp[i - 1] * 2 % mod;
		if (last[pos] != -1) dp[i] = (dp[i] - dp[last[pos] - 1] + mod) % mod;
		last[pos] = i;
	}
	printf("%I64d\n", dp[n + m]);
	return 0;
}