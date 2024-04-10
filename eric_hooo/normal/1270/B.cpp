#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int m1 = 0x3f3f3f3f, p1 = -1, m2 = -0x3f3f3f3f, p2;
		for (int i = 0; i < n; i++) {
			if (i) {
				if (a[i] - i - 1 >= m1) {
					printf("YES\n%d %d\n", p1 + 1, i + 1);
					goto NEXT;
				}
				if (a[i] + i + 1 <= m2) {
					printf("YES\n%d %d\n", p2 + 1, i + 1);
					goto NEXT;
				}
			}
			if (a[i] - i < m1) m1 = a[i] - i, p1 = i;
			if (a[i] + i > m2) m2 = a[i] + i, p2 = i;
		}
		printf("NO\n");
		NEXT:;
	}
	return 0;
}