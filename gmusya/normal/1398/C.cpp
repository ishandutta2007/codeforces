#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		vector <int> pre(n + 1);
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + a[i - 1];
		for (int i = 0; i <= n; i++)
			pre[i] = pre[i] - i;
		sort(pre.begin(), pre.end());
		long long ans = 0;
		long long cnt = 0;
		for (int i = 0; i <= n; i++) {
			if (i && pre[i] != pre[i - 1]) {
				ans += cnt * (cnt - 1) / 2;
				cnt = 0;
			}
			cnt++;
		}
		ans += cnt * (cnt - 1) / 2;
		cout << ans << '\n';
	}
	return 0;
}