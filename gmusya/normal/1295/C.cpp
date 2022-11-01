#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s1, s2, z;
		cin >> s1 >> s2;
		vector <vector <int>> c(26);
		for (int i = 0; i < s1.size(); i++)
			c[s1[i] - 'a'].push_back(i);
		int ans = 1;
		int cur_pos = 0;
		bool tf = true;
		for (int i = 0; i < s2.size(); i++) {
			if (c[s2[i] - 'a'].size() == 0) {
				tf = false;
				break;
			}
			if (cur_pos > c[s2[i] - 'a'][c[s2[i] - 'a'].size() - 1]) {
				ans++;
				cur_pos = 0;
			}
			int l = 0;
			int r = c[s2[i] - 'a'].size() - 1;
			while (l != r) {
				int m = (l + r) / 2;
				if (c[s2[i] - 'a'][m] < cur_pos)
					l = m + 1;
				else
					r = m;
			}
			cur_pos = c[s2[i] - 'a'][l] + 1;
		}
		if (!tf)
			cout << "-1" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}