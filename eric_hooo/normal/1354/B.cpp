#include <bits/stdc++.h>
using namespace std;

char s[200010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		int last[3] = {n, n, n};
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			last[s[i] - '1'] = i;
			int tmp = max(last[0], max(last[1], last[2]));
			if (tmp == n) continue;
			ans = ans == 0 ? tmp - i + 1 : min(ans, tmp - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}