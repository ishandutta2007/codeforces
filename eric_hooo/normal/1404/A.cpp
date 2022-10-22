#include <bits/stdc++.h>
using namespace std;

char s[300010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		scanf("%s", s);
		int c0 = 0, c1 = 0;
		for (int i = k; i < n; i++) {
			int p = i % k;
			if (s[i] == '?') continue;
			if (s[p] == '?') {
				s[p] = s[i];
				continue;
			}
			if (s[p] != s[i]) {
				printf("NO\n");
				goto END;
			}
		}
		for (int i = 0; i < k; i++) {
			if (s[i] == '0') c0++;
			else if (s[i] == '1') c1++;
		}
		if (c0 > k / 2 || c1 > k / 2) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		END:;
	}
	return 0;
}