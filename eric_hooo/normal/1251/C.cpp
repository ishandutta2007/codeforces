#include <bits/stdc++.h>
using namespace std;

char s[300010];
char p1[300010], p2[300010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s); int n = strlen(s);
		int t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] - '0' & 1) p1[t1++] = s[i];
			else p2[t2++] = s[i];
		}
		int tp = 0, c1 = 0, c2 = 0;
		for (int i = 0; i < n; i++) {
			if (c2 == t2 || c1 != t1 && p1[c1] < p2[c2]) s[tp++] = p1[c1++];
			else s[tp++] = p2[c2++];
		}
		s[tp] = '\0';
		printf("%s\n", s);
	}
	return 0;
}