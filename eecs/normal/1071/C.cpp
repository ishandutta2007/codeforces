#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, a[maxn];
vector<pair<int, int>> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1, j; i <= n - 2; i++) if (a[i]) {
		for (j = 2; i + j + j <= n; j++) {
			if (a[i + j]) break;
		}
		if (i + j + j > n) j = 1;
		a[i] ^= 1, a[i + j] ^= 1, a[i + j + j] ^= 1;
		ans.emplace_back(i, j);
	}
	for (int i = n - 1; i <= n; i++) if (a[i]) {
		if (i <= 6) puts("NO"), exit(0);
		a[i] = 0;
		ans.emplace_back(i - 6, 1);
		ans.emplace_back(i - 6, 3);
		ans.emplace_back(i - 5, 1);
	}
	printf("YES\n%d\n", ans.size());
	for (auto p : ans) {
		int x = p.first, d = p.second;
		printf("%d %d %d\n", x, x + d, x + d + d);
	}
	return 0;
}