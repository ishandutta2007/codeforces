#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') c1++;
			else c2++;
		}
		if (min(c1, c2) & 1) cout << "DA" << endl;
		else cout << "NET" << endl;
	}
	return 0;
}