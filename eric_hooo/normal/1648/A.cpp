#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100010];
long long cnt[100010];
long long sum[100010];

#define ID(x, y) ((x) * m + (y))

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[ID(i, j)]);
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = a[ID(i, j)];
			ans += cnt[x] * i - sum[x];
			cnt[x]++, sum[x] += i;
		}
	}
	memset(cnt, 0, sizeof(cnt)), memset(sum, 0, sizeof(sum));
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int x = a[ID(i, j)];
			ans += cnt[x] * j - sum[x];
			cnt[x]++, sum[x] += j;
		}
	}
	printf("%lld\n", ans);
	return 0;
}