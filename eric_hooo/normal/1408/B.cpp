#include <bits/stdc++.h>
using namespace std;

int a[110];
int cnt[110];

int main () {
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		memset(cnt, 0, sizeof(cnt));
		int minj = 0x3f3f3f3f, maxj = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			minj = min(minj, a[i]), maxj = max(maxj, a[i]);
			cnt[a[i]]++;
		}
		if (k == 1) {
			if (minj == maxj) cout << 1 << endl;
			else cout << -1 << endl;
			continue;
		}
		int tot = 0;
		for (int i = 0; i <= 100; i++) {
			if (cnt[i]) tot++;
		}
		if (k >= tot) {
			cout << 1 << endl;
			continue;
		}
		tot -= k;
		int ans = (tot + k - 2) / (k - 1) + 1;
		cout << ans << endl;
	}
	return 0;
}