#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int dp[maxn];
int t[maxn];
int r[3] = {1, 90, 1440}, c[3] = {20, 50, 120};
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e9;
		for (int j = 0; j < 3; j++) {
			int nc = c[j] + dp[lower_bound(t + 1, t + n + 1, t[i] - r[j] + 1) - t - 1];
			dp[i] = min(dp[i], nc);
		}
		printf("%d\n", dp[i] - dp[i - 1]);
	}
 	return 0;
}