#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool tf = true;
	int cnt = 0;
	vector <vector <int>> ans;
	for (int i = 0; i < n; i++) {
		tf = false;
		ans.push_back({});
		for (int j = 0; j < n - 1; j++) {
			if (s[j] == 'R' && s[j + 1] == 'L') {
				tf = true;
				ans[i].push_back(j + 1);
				cnt++;
				swap(s[j], s[j + 1]);
				j++;
				continue;
			}
		}
		if (!tf) {
			ans.pop_back();
			break;
		}
	}
	if (k < ans.size() || k > cnt) {
		cout << -1;
		return 0;
	}
	int sum = cnt;
	for (int i = 0; i < ans.size(); i++) {
		sum -= ans[i].size();
		if (sum >= k - 1) {
			k--;
			cout << ans[i].size() << " ";
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << endl;
			continue;
		}
		sum += ans[i].size();
		sum--;
		k--;
		cout << 1 << " " << ans[i].back() << endl;
		ans[i].pop_back();
		if (!ans[i].empty()) i--;
	}
	return 0;
}