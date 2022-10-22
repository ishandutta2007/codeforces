#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int j = 0; j < m; j++) {
		int x; scanf("%d", &x);
		printf("%d ", upper_bound(a, a + n, x) - a);
	}
	printf("\n");
	return 0;
}