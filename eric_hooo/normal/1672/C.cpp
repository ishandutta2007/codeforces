#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int p = -1, q = -1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i + 1]) {
				p = p == -1 ? i : p, q = i;
			}
		}
		if (p == -1) printf("0\n");
		else {
			if (p == q) printf("0\n");
			else if (q == p + 1) printf("1\n");
			else printf("%d\n", q - p - 1);
		}
	}
	return 0;
}