#include <bits/stdc++.h>
using namespace std;

bool check(long long a, int ca, long long b, int cb, int cnt) {
	if (a != b && a % b != 0) return 0;
	if (cb - ca == cnt) return 1;
	if (cb + 1 <= cnt) return 1;
	return 0;
}

int dp[5010];
long long a[5010];
int cnt[5010];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		cnt[i] = 0;
		while (a[i] % 2 == 0) a[i] >>= 1, cnt[i]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j < i; j++) {
			if (check(a[j], cnt[j], a[i], cnt[i], i - j)) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++, ans = max(ans, dp[i]);
	}
	printf("%d\n", n - ans);
	return 0;
}
/*
3
6 4 1

4
20 6 3 4

*/