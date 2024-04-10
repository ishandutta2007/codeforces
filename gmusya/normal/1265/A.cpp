#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define dl double long

using namespace std;

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i > 0 && i < s.size() - 1 && s[i] != '?' && (s[i] == s[i - 1] || s[i] == s[i + 1])) {
			cout << "-1" << endl;
			return;
		}
		if (i == 0) {
			if (s[i] == '?') {
				if (s[i + 1] == 'a')
					s[i] = 'b';
				else
					s[i] = 'a';
			}
			else
				continue;
		}
		if (i > 0) {
			vector <bool> tf(3);
			if (s[i] == '?') {
				tf[s[i - 1] - 'a'] = true;
				if (i + 1 < s.size())
					if (s[i + 1] != '?') 
						tf[s[i + 1] - 'a'] = true;
				for (int j = 0; j < 3; j++)
					if (!tf[j]) 
						s[i] = j + 'a';
				tf.resize(0);
			}
		}
	}
	for (auto now : s)
		cout << now;
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}