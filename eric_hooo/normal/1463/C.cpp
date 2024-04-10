#include <bits/stdc++.h>
#define int long long
using namespace std;

int t[100010], X[100010];

signed main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> t[i] >> X[i];
		}
		int cur = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (X[i] == cur) {
				ans++;
				continue;
			}
			int be = t[i], delta = X[i] > cur ? 1 : -1, need = abs(cur - X[i]);
			int j = i;
			while (j <= n && t[j] < t[i] + need) {
				int l = cur + delta * (t[j] - t[i]), r = cur + delta * (j == n ? need : min(t[j + 1] - t[i], need));
				if (l > r) swap(l, r);
				if (l <= X[j] && X[j] <= r) ans++;
				j++;
			}
			cur = X[i], i = j - 1;
		}
		cout << ans << endl;
	}
	return 0;
}