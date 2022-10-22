#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n;
int a[200010];
vector <int> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (!ans.size()) ans.push_back(x);
		a[x]++;
	}
	for (int i = 1; i <= N; i++) {
		if (a[i] && a[i + 1]) {
			ans.clear();
			ans.push_back(i), ans.push_back(i + 1);
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (a[i] < 2) continue;
		int j = i, sum = 0; while (j <= N && a[j] >= 2) sum += a[j], j++;
		sum += a[i - 1] + a[j];
		if (sum > ans.size()) {
			ans.clear();
			for (int k = i - 1; k <= j; k++) {
				int cnt = a[k];
				while (cnt > 1) cnt--, ans.push_back(k);
			}
			for (int k = j; k >= i - 1; k--) {
				if (a[k]) ans.push_back(k);
			}
		}
		i = j - 1;
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}