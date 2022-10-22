#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int cur = 1, lst = -1, dead = 0;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			if (x == 0) {
				if (lst == 0) dead = 1;
				lst = x;
			} else {
				if (lst == 0) cur += 1;
				else if (lst == 1) cur += 5;
				else cur += 1;
				lst = x;
			}
		}
		if (dead) printf("-1\n");
		else printf("%d\n", cur);
	}
	return 0;
}