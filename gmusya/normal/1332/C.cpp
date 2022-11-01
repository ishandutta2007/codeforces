#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		int ans = 0;
		vector <int> cnt(26);
		if (k % 2) 
			for (int i = k / 2; i < n; i += k) {
				cnt[s[i] - 'a']++;
				ans++;
			}
		for (int i = 0; 2 * (i + 1) <= k; i++) {
			vector <int> cnt(26);
			for (int j = i; j < n; j += k) {
				cnt[s[j] - 'a']++;
				cnt[s[n - j - 1] - 'a']++;
				ans += 2;
			}
			sort(cnt.begin(), cnt.end());
			ans -= cnt[25];
		}
		sort(cnt.begin(), cnt.end());
		ans -= cnt[25];
		cout << ans << endl;
	}
	return 0;
}