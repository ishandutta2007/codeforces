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
		vector <char> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int cnt = 0;
		vector <int> ans;
		int i = 0;
		while (i < n && s[i] == 'P')
			i++;
		for (; i < n; i++) {
			if (s[i] == 'A') {
				ans.push_back(cnt);
				cnt = 0;
			}
			else
				cnt++;
		}
		ans.push_back(cnt);
		sort(ans.begin(), ans.end());
		cout << ans[ans.size() - 1] << endl;
	}
	return 0;
}