#include <iostream>
#include <vector>
#include <string>
#include <set>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector <set <int>> g(26);
		for (int i = 0; i < s.size() - 1; i++) {
			g[s[i] - 'a'].insert(s[i + 1] - 'a');
			g[s[i + 1] - 'a'].insert(s[i] - 'a');
		}
		bool tf = true;
		int cnt = 0;
		vector <bool> used(26);
		vector <int> l;
		for (int i = 0; i < 26; i++) 
			if (g[i].size() > 2)
				tf = false;
		if (!tf) {
			cout << "NO" << endl;
			continue;
		}
		vector <char> ans;
		for (int i = 0; i < 26; i++) {
			if (g[i].size() == 0) ans.push_back(i + 'a');
			if (g[i].size() == 1 && !used[i]) {
				int j = i;
				int p = j;
				while (p == j || g[j].size() == 2) {
					used[j] = true;
					ans.push_back(j + 'a');
					for (int u : g[j])
						if (u != p) {
							p = j;
							j = u;
							break;
						}
				}
				used[j] = true;
				ans.push_back(j + 'a');
			}
		}
		if (ans.size() != 26) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (char c : ans)
			cout << c;
		cout << endl;
	}
	return 0;
}