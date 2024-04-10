#include <bits/stdc++.h>
using namespace std;

int Query(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	int tmp; scanf("%d", &tmp);
	return tmp == 0 ? 0x3f3f3f3f : tmp;
}

int main() {
	int n; scanf("%d", &n);
	int l = n, r = 2000 * n;
	while (l < r) {
		int mid = l + r >> 1;
		if (Query(mid) == 1) r = mid;
		else l = mid + 1;
	}
	int S = r - n + 1, ans = r;
	for (int i = n; i >= 1; i--) {
		int lb = (S + i - 1) / i, rb = (ans + i - 1) / i;
		if (lb >= rb) continue;
		int cur = rb;
		while (cur > lb && Query(cur - 1) == i) cur--;
		ans = min(ans, cur * i);
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}