#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
int t, n, a[200000];
long long sum, ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = 0;
		mp.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
			++mp[a[i]];
		}
		sum *= 2;
		if (sum % n) {
			puts("0");
			continue;
		}
		sum /= n;
		ans = 0;
		for (int i = 0; i < n; ++i) ans += mp[sum - a[i]] - (sum - a[i] == a[i]);
		printf("%lld\n", ans / 2);
	}
	return 0;
}