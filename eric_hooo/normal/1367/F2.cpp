#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];
vector <int> all;
int dp[200010], f[200010];
int lst[200010], cnt[200010];
vector <int> pos[200010];

void Main() {
	scanf("%d", &n);
	all.clear();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
	}
	int N = all.size();
	for (int i = 1; i <= N; i++) {
		pos[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		pos[a[i]].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		lst[i] = -1, cnt[i] = 0;
	}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		int x = a[i];
		dp[i] = 1, f[i] = 1;
		if (lst[x] != -1) dp[i] = max(dp[i], dp[lst[x]] + 1);
		else if (x < N && pos[x + 1][0] > i) dp[i] = max(dp[i], dp[pos[x + 1][0]] + 1);
		if (lst[x] == -1) {
			if (x < N) dp[i] = max(dp[i], cnt[x + 1] + 1);
		}
		ans = max(ans, dp[i]);
		if (x < N && pos[x + 1][0] > i) f[i] = max(f[i], dp[pos[x + 1][0]] + 1);
		if (lst[x] != -1) f[i] = max(f[i], f[lst[x]] + 1);
		if (x < N) f[i] = max(f[i], cnt[x + 1] + 1);
		ans = max(ans, f[i]);
		lst[x] = i, cnt[x]++;
	}
	printf("%d\n", n - ans);
}

int main() {
	int Case; scanf("%d", &Case);
	while (Case--) Main();
	return 0;
}