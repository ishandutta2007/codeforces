#include <bits/stdc++.h>
using namespace std;

int a[100010];

long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		long long pw = 1;
		for (int i = 1; i <= n; i++) {
			if (pw <= 2000000000) pw = pw * (i + 1) / gcd(pw, i + 1);
			if (a[i] % 2 == 0) {
				if (a[i] % pw == 0) {
					printf("NO\n");
					goto END;
				}
			}
		}
		printf("YES\n");
		END:;
	}
	return 0;
}