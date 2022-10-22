#include <bits/stdc++.h>
using namespace std;

const long long INF = 100000000000000ll;

struct Node{
	int t, c;
}a[2010];

long long dp[4010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &a[i].t, &a[i].c);
	}
	for (int i = 0; i <= 4005; i++){
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 4005; j >= a[i].t - 1; j--){
			dp[j] = min(dp[j], dp[j - a[i].t - 1] + a[i].c);
		}
	}
	long long ans = INF;
	for (int i = n; i <= 4000; i++){
		ans = min(ans, dp[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}