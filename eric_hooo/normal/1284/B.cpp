#include <bits/stdc++.h>
using namespace std;

int sum[1000010];

int main () {
	int n; scanf("%d", &n);
	long long ans = 0;
	int cnt = 0;
	vector <int> a;
	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m);
		int minj = 0x3f3f3f3f, maxj = -1, flag = 0;
		while (m--) {
			int x; scanf("%d", &x);
			if (x > minj) flag = 1;
			minj = min(minj, x), maxj = max(maxj, x);
		}
		if (!flag) sum[maxj]++, a.push_back(minj);
		else cnt++;
	}
	ans += 2ll * cnt * n - 1ll * cnt * cnt;
	for (int i = 1000000; i >= 0; i--) {
		sum[i] += sum[i + 1];
	}
	for (int i = 0; i < a.size(); i++) {
		ans += sum[a[i] + 1];
	}
	printf("%I64d\n", ans);
	return 0;
}