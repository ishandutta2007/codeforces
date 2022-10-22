#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		long long s, n, k; scanf("%lld%lld%lld", &s, &n, &k);
		if (s == k) {
			printf("YES\n");
			continue;
		}
		long long tmp = (s + 1) / k / 2;
		long long maxj = tmp * k + min((s + 1) % (2 * k), k);
		if (maxj >= n + 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}