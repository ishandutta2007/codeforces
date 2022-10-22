#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010];

long long Calc(int l, int r) {
	long long ans = 0, cur = 0;
	while (l != r) {
		l = l < r ? l + 1 : l - 1;
		ans += cur % a[l] == 0 ? cur / a[l] + 1 : cur / a[l] + 1;
		cur = (cur / a[l] + 1) * a[l];
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, Calc(i, n) + Calc(i, 1));
	}
	printf("%lld\n", ans);
	return 0;
}