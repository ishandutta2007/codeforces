#include <bits/stdc++.h>
using namespace std;

char s[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		int has = 0, cnt = 0, ok = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') cnt++;
			else cnt--, has = 1;
			if (cnt < 0) ok = 0;
		}
		if (s[n - 1] != 'B') ok = 0;
		if (!has) ok = 0;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}