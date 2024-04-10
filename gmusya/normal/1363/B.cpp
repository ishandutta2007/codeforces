#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector <int> cnt0(n), cnt1(n);
		cnt0[0] += (s[0] == '0');
		cnt1[0] += (s[0] == '1');
		for (int i = 1; i < n; i++) {
			cnt0[i] = cnt0[i - 1] + (s[i] == '0');
			cnt1[i] = cnt1[i - 1] + (s[i] == '1');
		}
		int ans = min(cnt0[n - 1], cnt1[n - 1]);
		for (int i = 0; i < n; i++) {
			int cur_ans = 0;
			cur_ans += cnt0[i];
			cur_ans += cnt1[n - 1] - cnt1[i];
			ans = min(ans, cur_ans);
		}
		for (int i = 0; i < n; i++) {
			int cur_ans = 0;
			cur_ans += cnt1[i];
			cur_ans += cnt0[n - 1] - cnt0[i];
			ans = min(ans, cur_ans);
		}
		cout << ans << '\n';
	}
	return 0;
}