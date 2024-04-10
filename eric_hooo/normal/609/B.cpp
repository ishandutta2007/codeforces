#include <bits/stdc++.h>
using namespace std;

int cnt[20];

int main () {
	int n, m; scanf("%d%d", &n, &m);
	long long ans = 1ll * n * (n - 1) / 2;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		ans -= cnt[x];
		cnt[x]++;
	}
	printf("%I64d\n", ans);
	return 0;
}