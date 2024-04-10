#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			ans += (1 + (x == 0)) * i * (n - i + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}