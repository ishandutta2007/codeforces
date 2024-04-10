#include <bits/stdc++.h>
using namespace std;

char s[200010];
int now[26];
int ans[200010];

int main () {
	int n; scanf("%d", &n);
	scanf("%s", s);
	int tot = 0;
	memset(now, -1, sizeof(now));
	for (int i = 0; i < n; i++) {
		int x = s[i] - 'a';
		for (int j = x; j >= 0; j--) {
			if (now[j] != -1) {
				now[x] = now[j];
				if (j != x) now[j] = -1;
				goto END;
			}
		}
		now[x] = ++tot;
		END:;
		ans[i] = now[x];
	}
	printf("%d\n", tot);
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}