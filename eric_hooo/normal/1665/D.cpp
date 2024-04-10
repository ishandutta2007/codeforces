#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int x = 0;
		for (int it = 0; it < 30; it++) {
			int b = (1 << it) - x, a = b + (1 << it + 1);
			printf("? %d %d\n", a, b);
			fflush(stdout);
			int tmp; scanf("%d", &tmp);
			if (tmp == (1 << it + 1)) x |= 1 << it;
		}
		printf("! %d\n", x);
	}
	return 0;
}