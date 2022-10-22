#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		long long n, k; scanf("%lld%lld", &n, &k);
		long long cur = 1, ans = 0;
		while (cur <= k && cur < n) cur = cur + cur, ans++;
		if (cur < n) ans += (n - cur + k - 1) / k;
		printf("%lld\n", ans);
	}
	return 0;
}