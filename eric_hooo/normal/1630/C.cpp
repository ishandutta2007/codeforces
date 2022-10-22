#include <bits/stdc++.h>
using namespace std;

int a[200010];
int nxt[200010];
int n;
int lst[200010];
int dp[200010];
multiset <int> S;
vector <int> era[200010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(lst, -1, sizeof(lst));
	for (int i = n; i >= 1; i--) {
		nxt[i] = lst[a[i]], lst[a[i]] = lst[a[i]] == -1 ? i : lst[a[i]];
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (auto it : era[i]) {
			S.erase(S.find(it));
		}
		if (S.size()) dp[i] = max(*(--S.end()) + i, dp[i]);
		dp[i + 1] = max(dp[i], dp[i + 1]);
		if (nxt[i] != -1) {
			int j = nxt[i];
			S.insert(dp[i] - i - 1);
			era[j + 1].push_back(dp[i] - i - 1);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}