/* Problem: *
 * Author: ZhaoChongyan
 * Time: 2020-11-24 19:00:34
**/

#include <bits/stdc++.h>
using namespace std;

#define All(a) a.begin(), a.end()

int main() {
	int T = 1, n, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		if (((n & 1) && !(k & 1))) {
			puts("NO");
		} else {
			if ((n & 1) == (k & 1)) {
				if (n < k) {
					puts("NO");
					continue;
				}
				puts("YES");
				for (int i = 1; i < k; ++i) {
					printf("1 ");
				}
				printf("%d\n", n - k + 1);
			} else {
				if (n < (k << 1)) {
					puts("NO");
					continue;
				}
				puts("YES");
				for (int i = 1; i < k; ++i) {
					printf("2 ");
				}
				printf("%d\n", n - (k << 1) + 2);
			}
		}
	}
	return 0;
}