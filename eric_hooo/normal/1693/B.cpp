#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static int fa[200010];
		for (int i = 2; i <= n; i++) {
			scanf("%d", &fa[i]);
		}
		static int L[200010], R[200010];
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &L[i], &R[i]);
		}
		static long long dp[200010]; for (int i = 1; i <= n; i++) dp[i] = 0;
		int ans = 0;
		for (int i = n; i >= 1; i--) {
			if (dp[i] < L[i]) ans++, dp[fa[i]] += R[i];
			else dp[fa[i]] += min((long long)R[i], dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}