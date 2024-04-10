/*input
WUBWUBIWUBAMWUBWUBX

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	string b = "";

	for (int i = 0; i < s.size(); i++) {
		//cout << i << endl;
		if (i + 2 < s.size() and s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B') {
			i += 2;

			if (b.size() > 0 and b.back() != ' ')
				b.push_back(' ');
		}
		else
			b.push_back(s[i]);
		//cout << i << endl;
	}

	for (int i = b.size() - 1; i >= 0; i--) {
		if (b[i] == ' ')
			b.pop_back();
		else
			break;
	}

	cout << b;

	return 0;
}