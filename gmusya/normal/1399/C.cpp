#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> cnt(n + 1);
		for (int i = 0; i < n; i++) {
			int w;
			cin >> w;
			cnt[w]++;
		}
		int ans = 0;
		for (int s = 2; s <= n + n; s++) {
			int tmp = 0;
			for (int i = 1; i <= s - i; i++) {
				if (i == s - i) tmp += cnt[i] / 2;
				else tmp += min(cnt[i], (s - i <= n ? cnt[s - i] : 0));
			}
			ans = max(ans, tmp);
		}
		cout << ans << '\n';
	}
	return 0;
}