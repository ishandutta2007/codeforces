#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <string> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		bool sol = false;
		string ans;
		for (int i = 0; i < m; i++)
			for (char c = 'a'; c <= 'z'; c++) {
				string str = s[0];
				str[i] = c;
				int gs = 0;
				for (int j = 0; j < n; j++) {
					int cnt = 0;
					for (int z = 0; z < m; z++)
						cnt += (str[z] != s[j][z]);
					gs += (cnt < 2);
				}
				if (gs == n) {
					sol = true;
					ans = str;
				}
			}
		if (sol) {
			cout << ans << '\n';
			continue;
		}
		cout << -1 << '\n';
	}
	return 0;
}