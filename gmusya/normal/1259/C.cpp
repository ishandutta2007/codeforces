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
		vector <int> answer;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != 'o')
				continue;
			if (i >= 2 && i < s.size() - 2) {
				if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i + 1] == 'n' && s[i + 2] == 'e') {
					answer.push_back(i);
					continue;
				}
				if (s[i - 2] == 't' && s[i - 1] == 'w' && !(s[i + 1] == 'n' && s[i + 2] == 'e')) {
					answer.push_back(i - 1);
					continue;
				}
				if (!(s[i - 2] == 't' && s[i - 1] == 'w') && s[i + 1] == 'n' && s[i + 2] == 'e') {
					answer.push_back(i + 1);
					continue;
				}
				continue;
			}
			if (i >= 2 && i >= s.size() - 2) {
				if (s[i - 2] == 't' && s[i - 1] == 'w') {
					answer.push_back(i - 1);
					continue;
				}
				continue;
			}
			if (i < 2 && i < s.size() - 2) {
				if (s[i + 1] == 'n' && s[i + 2] == 'e') {
					answer.push_back(i + 1);
					continue;
				}
				continue;
			}
		}
		cout << answer.size() << endl;
		for (auto now : answer)
			cout << now + 1 << " ";
		cout << endl;
	}
	return 0;
}