#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (b >= a) {
			printf("%d\n", b);
			continue;
		}
		if (c <= d) {
			printf("-1\n");
			continue;
		}
		printf("%I64d\n", b + (long long)(a - b + c - d - 1) / (c - d) * c);
	}
	return 0;
}