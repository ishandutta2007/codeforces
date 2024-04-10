#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int u = 0, d = 0, l = 0, r = 0;
		for (int i = 0; i < s.size(); i++) {
			u += s[i] == 'U';
			d += s[i] == 'D';
			l += s[i] == 'L';
			r += s[i] == 'R';
		}
		if (u > 0 && r > 0 && l > 0 && d > 0) {
			cout << 2 * (min(u, d) + min(l, r)) << endl;
			for (int i = 0; i < min(u, d); i++)
				cout << "U";
			for (int i = 0; i < min(l, r); i++)
				cout << "R";
			for (int i = 0; i < min(u, d); i++)
				cout << "D";
			for (int i = 0; i < min(l, r); i++)
				cout << "L";
			cout << endl;
			continue;
		}
		if (min(u, d) == 0 && min(l, r) == 0) {
			cout << 0 << endl << endl;
			continue;
		}
		if (u == 0 || d == 0)
			cout << "2" << endl << "LR" << endl;
		else
			cout << "2" << endl << "UD" << endl;
	}
	return 0;
}