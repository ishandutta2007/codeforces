#include <bits/stdc++.h>
using namespace std;

char s[300010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; char c; scanf("%d %c", &n, &c);
		scanf("%s", s + 1);
		int qwq = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] != c) qwq = 1;
		}
		if (!qwq) {
			printf("0\n");
			continue;
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			if (s[i] == c) {
				printf("1\n%d\n", i);
				goto END;
			}
		}
		printf("2\n%d %d\n", n, n - 1);
		END:;
	}
	return 0;
}