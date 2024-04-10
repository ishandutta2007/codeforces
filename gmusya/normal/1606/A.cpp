#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		if (str.size() == 1) {
			cout << str << '\n';
			continue;
		}
		if (str.size() == 2) {
			str[1] = str[0];
			cout << str << '\n';
			continue;
		}
		int n = static_cast<int>(str.size());
		vector<pair<int, string>> res;
		for (char left = 'a'; left <= 'b'; ++left) {
			for (char right = 'a'; right <= 'b'; ++right) {
				int diff = (left != str[0]) + (right != str[n - 1]);
				string copy_str = str;
				copy_str[0] = left;
				copy_str[n - 1] = right;
				int cnt = 0;
				for (int i = 0; i + 1 < n; ++i) {
					if (copy_str[i] == 'a' && copy_str[i + 1] == 'b') {
						++cnt;
					}
					if (copy_str[i] == 'b' && copy_str[i + 1] == 'a') {
						--cnt;
					}
				}
				if (cnt == 0) {
					res.emplace_back(diff, copy_str);
				}
			}
		}
		sort(res.begin(), res.end());
		cout << res[0].second << '\n';
	}
	return 0;
}