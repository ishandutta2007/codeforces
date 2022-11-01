#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s, c;
		cin >> s >> c;
		int l = 0;
		while (l < s.size()) {
			int sm = l;
			for (int i = l; i < s.size(); i++)
				if (s[i] <= s[sm])
					sm = i;
			int uk;
			for (uk = l; uk < s.size() && s[sm] == s[uk]; uk++);
			if (uk < sm) {
				swap(s[uk], s[sm]);
				break;
			}
			l = sm + 1;
		}
		if (s < c)
			cout << s << endl;
		else
			cout << "---" << endl;
	}
	return 0;
}