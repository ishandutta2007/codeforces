#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int neg = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]), neg += a[i] < 0, a[i] = abs(a[i]);
		}
		int ok = 1;
		for (int i = 0; i < n; i++) {
			if (i < neg) a[i] = -a[i];
			if (i && a[i - 1] > a[i]) ok = 0;
		}
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}