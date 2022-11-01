#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 2; i++) {
		if (i + 2 >= s.size())
			break;
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
			s[i] = s[i + 1] = s[i + 2] = ' ';
			s.erase(s.begin() + i, s.begin() + i + 2);
			i--;
		}
	}
	for (int i = 0; i < s.size() && s[i] == ' ';)
		s.erase(s.begin());
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ' ' && s[i + 1] == ' ') {
			s.erase(s.begin() + i + 1);
			i--;
		}
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	return 0;
}