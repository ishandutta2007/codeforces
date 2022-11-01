#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector <int> cnt(26);
		for (int i = 0; i < n; i++)
			cnt[s[i] - 'a']++;
		int m;
		cin >> m;
		vector <int> b(m);
		for (int i = 0; i < m; i++)
			cin >> b[i];
		vector <char> ans(m);
		for (int it = 25; it >= 0; it--) {
			vector <int> zeros;
			for (int i = 0; i < m; i++)
				if (b[i] == 0) zeros.push_back(i);	
			if (zeros.size() > cnt[it]) continue;
			for (auto &now : zeros) {
				ans[now] = 'a' + it;
				b[now] = -1;
			}
			for (int i = 0; i < m; i++)
				for (auto &now : zeros)
					b[i] -= abs(now - i);
		}
		for (auto &now : ans)
			cout << now;
		cout << '\n';
	}
	return 0;
}