#include <bits/stdc++.h>
using namespace std;

int a[200010];
vector <int> all[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			all[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			all[a[i]].push_back(i);
		}
		int j = 1, sum = -n, X = -1, Y = -1;
		for (int i = 1; i <= n; i++) {
			while (j <= n && sum < k) sum += all[j].size() * 2, j++;
			if (sum >= k) {
				if (X == -1 || Y - X > j - i - 1) Y = j - 1, X = i;
			}
			sum -= all[i].size() * 2;
		}
		printf("%d %d\n", X, Y);
		int lst = 1, cur = 0, need = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= X && a[i] <= Y) cur++;
			else cur--;
			if (cur == need && need < k) {
				printf("%d %d\n", lst, i), need++, lst = i + 1;
			}
		}
		printf("%d %d\n", lst, n);
	}
	return 0;
}