#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		long long ans = 1; int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			if (x == 1) cnt++;
			else if (x == 0) ans = ans * 2;
		}
		printf("%lld\n", ans * cnt);
	}
	return 0;
}