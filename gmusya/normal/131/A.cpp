#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	bool tf = true;
	cin >> s;
	for (int i = 1; i < s.size(); i++)
		if (s[i] < 'A' || s[i] > 'Z')
			tf = false;
	if (tf) {
		for (int i = 1; i < s.size(); i++)
			s[i] = s[i] - 'A' + 'a';
		if (s[0] >= 'A' && s[0] <= 'Z')
			s[0] = s[0] - 'A' + 'a';
		else
			s[0] = s[0] - 'a' + 'A';
	}
	cout << s;
	return 0;
}