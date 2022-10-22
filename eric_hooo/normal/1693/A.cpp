#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static int a[200010];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int p = n; while (p >= 1 && !a[p]) p--;
		if (p == 0) {
			printf("Yes\n");
		} else {
			if (a[p] > 0) {
				printf("No\n");
			} else {
				if (a[1] <= 0) {
					printf("No\n");
				} else {
					a[1]--, a[p]++;
					long long sum = 0;
					int bad = 0;
					for (int i = 1; i <= p; i++) {
						sum += a[i];
						if (sum < 0) {
							bad = 1;
						}
					}
					if (bad || sum != 0) {
						printf("No\n");
					} else {
						printf("Yes\n");
					}
				}
			}
		}
	}
	return 0;
}