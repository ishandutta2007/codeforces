#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <char> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		while (s.size() && s[0] == s.back())
			s.pop_back();
		int cnt = n - s.size();
		if (s.empty()) {
			cout << (cnt + 2) / 3 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 0; i + 1 < s.size(); i++) {
			cnt++;
			if (s[i] != s[i + 1]) {
				ans += cnt / 3;
				cnt = 0;
			}
		}
		ans += (cnt + 1) / 3;
		cout << ans << '\n';
	}
	return 0;
}