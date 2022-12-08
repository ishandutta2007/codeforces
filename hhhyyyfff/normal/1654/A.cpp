#include <bits/stdc++.h>

using namespace std;

int t, n, a[1000];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		printf("%d\n", a[n - 1] + a[n - 2]);
	}
	return 0;
}