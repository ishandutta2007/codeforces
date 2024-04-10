#include <bits/stdc++.h>
using namespace std;

int can[26];

int main () {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		memset(can, 0, sizeof(can));
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i && s[i] != s[i - 1]) {
				if (cnt & 1) can[s[i - 1] - 'a'] = 1;
				cnt = 1;
			} else cnt++;
		}
		if (cnt & 1) can[s[(int)s.size() - 1] - 'a'] = 1;
		for (int i = 0; i < 26; i++) {
			if (can[i]) cout << char('a' + i);
		}
		cout << endl;
	}
	return 0;
}