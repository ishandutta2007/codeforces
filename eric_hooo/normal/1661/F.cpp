#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
int a[200010];
int ans;

long long F(int n, int k) {
	int x = n / k, y = n % k;
	return 1ll * x * x * (k - y) + 1ll * (x + 1) * (x + 1) * y;
}

long long Solve(long long lim) {
	ans = 0;
	long long used = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = a[i];
		while (l < r) {
			int mid = l + r >> 1;
			if (F(a[i], mid) - F(a[i], mid + 1) >= lim) l = mid + 1;
			else r = mid;
		}
		ans += l - 1, used += F(a[i], l);
	}
	return used;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--) {
		a[i] -= a[i - 1];
	}
	scanf("%lld", &m);
	long long l = 1, r = 1000000000000000000;
	while (l < r) {
		long long mid = l + r + 1 >> 1;
		if (Solve(mid) <= m) l = mid;
		else r = mid - 1;
	}
	long long used = Solve(l);
	ans -= (m - used) / l;
	printf("%d\n", ans);
	return 0;
}