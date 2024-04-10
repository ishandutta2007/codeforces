#include <bits/stdc++.h>
using namespace std;

long long a[5010];

long long dfs(int l, int r, int B) {
	if (l == r) return a[l] == B ? 0 : 1;
	long long minj = 0x3f3f3f3f;
	for (int i = l; i <= r; i++) {
		minj = min(minj, a[i]);
	}
	long long ans = minj - B;
	long long lst = l - 1;
	for (int i = l; i <= r; i++) {
		if (a[i] == minj) {
			if (lst + 1 <= i - 1) ans += dfs(lst + 1, i - 1, minj);
			lst = i;
		}
	}
	if (lst + 1 <= r) ans += dfs(lst + 1, r, minj);
	return min(ans, r - l + 1ll);
}

int main () {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << dfs(0, n - 1, 0) << endl;
	return 0;
}