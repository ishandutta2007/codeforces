#include <bits/stdc++.h>
using namespace std;

int lst[1000010];
char s[1000010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s); int n = strlen(s);
		for (int i = 0; i <= n; i++) {
			lst[i] = -1;
		}
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur > 0) lst[cur] = lst[cur] == -1 ? i : lst[cur];
			if (s[i] == '+') cur--;
			else cur++;
		}
		if (cur > 0) lst[cur] = lst[cur] == -1 ? n : lst[cur];
		long long ans = n;
		for (int i = 1; i <= n; i++) {
			if (lst[i] == -1) break;
			ans += lst[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}