#include <bits/stdc++.h>
using namespace std;

int a[10010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int ok = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) ok = 1;
		}
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}