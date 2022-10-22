#include <bits/stdc++.h>
using namespace std;

int a[100010];
int n;

bool check(int x) {
	if (x == 1) return a[x] & a[x + 1];
	if (x == n) return a[x] & a[x - 1];
	return bool(a[x] & a[x - 1]) & bool(a[x] & a[x + 1]);
}

int main () {
	int q; scanf("%d%d", &n, &q);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = 3;
	}
	while (q--) {
		int x, y; scanf("%d%d", &x, &y), swap(x, y);
		ans -= check(x) + (x > 1 ? check(x - 1) : 0) + (x < n ? check(x + 1) : 0);
		a[x] ^= 1 << y - 1;
		ans += check(x) + (x > 1 ? check(x - 1) : 0) + (x < n ? check(x + 1) : 0);
		if (!ans && (a[n] >> 1 & 1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}