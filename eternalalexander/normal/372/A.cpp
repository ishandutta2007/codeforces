#include <bits/stdc++.h>

#define maxn 500005

int n,a[maxn];

int check(int x) {
	for (int i = 1; i <= x; ++ i) if (a[n - x + i] < a[i] * 2) return 0;
	return 1;
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int l = 0, r = n / 2, ans = 0;
	while (l <= r) {
		int mid = (l+r) >> 1;
		if (check(mid)) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} printf("%d",n - ans);
	return 0;
}