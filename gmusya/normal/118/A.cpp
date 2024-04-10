#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 'a' - 'A';
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i') {
			s.erase(s.begin() + i);
			i--;
			continue;
		}
		if (i == 0 || s[i - 1] != '.')
			s.insert(s.begin() + i, '.');
	}
	cout << s;
	return 0;
}