#include <bits/stdc++.h>
using namespace std;

int a[5010];
int cnt[5010];
int ans[5010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		memset(cnt, 0, sizeof(cnt));
		int now = 1;
		for (int j = i; j < n; j++) {
			cnt[a[j]]++;
			if (cnt[a[j]] > cnt[now] || cnt[a[j]] == cnt[now] && a[j] < now) now = a[j];
			ans[now]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}