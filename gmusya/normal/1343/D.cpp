#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> cnt(k * 2 + 1);
		for (int i = 0; i < n / 2; i++)
			cnt[a[i] + a[n - i - 1]]++;
		vector <int> cant_touch_this_max(k * 2 + 2), cant_touch_this_min(k * 2 + 2);
		for (int i = 0; i < n / 2; i++) {
			int maxsum = max(a[i], a[n - i - 1]) + k;
			int minsum = min(a[i], a[n - i - 1]) + 1;
			cant_touch_this_min[minsum - 1]++, cant_touch_this_max[maxsum + 1]++;
		}
		for (int i = 1; i <= k * 2 + 1; i++)
			cant_touch_this_max[i] += cant_touch_this_max[i - 1];
		for (int i = k * 2; i >= 0; i--)
			cant_touch_this_min[i] += cant_touch_this_min[i + 1];
		int ans = INF;
		for (int i = 0; i < k * 2 + 1; i++) 
			ans = min(ans, n / 2 + cant_touch_this_min[i] + cant_touch_this_max[i] - cnt[i]);
		cout << ans << '\n';
	}
	return 0;
}