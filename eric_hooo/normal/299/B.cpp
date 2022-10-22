#include <bits/stdc++.h>
using namespace std;

char a[300010];
int dp[300010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	scanf("%s", a + 1);
	dp[1] = 1;
	int cnt = 1;
	for (int i = 2; i <= n; i++){
		if (i - k - 1 >= 1) cnt -= dp[i - k - 1];
		dp[i] = cnt > 0 && a[i] == '.';
		cnt += dp[i];
	}
	printf(dp[n] ? "YES\n" : "NO\n");
	return 0;
}