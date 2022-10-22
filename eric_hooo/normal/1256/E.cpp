#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
pii a[200010];
int dp[200010];
int ans[200010];
int lst[200010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].fi), a[i].se = i;
	}
	sort(a, a + n);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 3; j <= 5; j++) {
			if (dp[i + j] > dp[i] + a[i + j - 1].fi - a[i].fi) {
				dp[i + j] = dp[i] + a[i + j - 1].fi - a[i].fi;
				lst[i + j] = j;
			}
		}
	}
	int TOT = 0, cur = n;
	while (cur) {
		TOT++; int x = lst[cur];
		for (int i = cur - x; i < cur; i++) {
			ans[a[i].se] = TOT;
		}
		cur -= x;
	}
	printf("%d %d\n", dp[n], TOT);
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}