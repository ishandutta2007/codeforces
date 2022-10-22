#include <bits/stdc++.h>
using namespace std;

int a[200010];
int sum[200010];
int T[400010];
int n;

void modify(int x, int v) {
	while (x <= 400005) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

long long Solve(int m) {
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + 1 - (a[i] < m ? 2 : 0);
	}
	memset(T, 0, sizeof(T));
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += query(sum[i] + n + 1 - 1);
		modify(sum[i] + n + 1, 1);
	}
	return ans;
}

int main() {
	int m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%lld\n", Solve(m) - Solve(m + 1));
	return 0;
}