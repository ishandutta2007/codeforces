#include <bits/stdc++.h>
using namespace std;

char s[100010], t[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s%s", s, t);
		int n = strlen(s), m = strlen(t);
		reverse(s, s + n), reverse(t, t + m);
		int pos = 0, ans = 0;
		while (t[pos] == '0') pos++;
		while (s[pos] == '0') ans++, pos++;
		printf("%d\n", ans);
	}
	return 0;
}