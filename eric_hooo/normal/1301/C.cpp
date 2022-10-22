#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		int cnt = n - m, val = cnt / (m + 1), a = m + 1 - cnt % (m + 1), b = cnt % (m + 1);
		long long ans = 0;
		ans += 1ll * a * (a - 1) / 2 * (val + 1) * (val + 1);
		ans += 1ll * b * (b - 1) / 2 * (val + 2) * (val + 2);
		ans += 1ll * a * b * (val + 1) * (val + 2);
		printf("%I64d\n", ans); 
	}
	return 0;
}