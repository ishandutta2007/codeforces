#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main () {
	int n; scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	int x = sum / n, cnt = n - (sum - sum / n * n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = i < cnt ? x : x + 1;
		ans += abs(tmp - a[i]);
	}
	assert(ans % 2 == 0);
	printf("%d\n", ans / 2);
	return 0;
}