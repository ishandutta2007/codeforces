#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m1, m2;
		scanf("%d%d%d", &n, &m1, &m2);
		int ans = -1;
		while (m1--) {
			int x; scanf("%d", &x);
			if (x == n) ans = 1;
		}
		while (m2--) {
			int x; scanf("%d", &x);
			if (x == n) ans = 2;
		}
		if (ans == 1) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}