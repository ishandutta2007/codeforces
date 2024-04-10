#include <bits/stdc++.h>
using namespace std;

int a[2010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int s1 = 0, s2 = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] & 1) s1 = 1;
			else s2 = 1;
			sum += a[i];
		}
		if (sum & 1) printf("YES\n");
		else if (s1 && s2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}