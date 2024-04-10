#include <iostream>
#include <string>

using namespace std;
string toLowerCase(string toLower);
bool isVowel(char elem);

int main() {
	string s;
	cin >> s;
	s = toLowerCase(s);
	string new_s;
	for (auto elem : s) {
		if (isVowel(elem)) {
			continue;
		}
		new_s += '.';
		new_s += elem;
	}
	cout << new_s;
	return 0;
}

string toLowerCase(string s) {
	string ans = "";
	for (auto elem : s) {
		ans += tolower(elem);
	}
	return ans;
}

bool isVowel(char c) {
	if ((c == 'a') || (c == 'o') || (c == 'y') || (c == 'e') || (c == 'u') || (c == 'i'))
		return true;
	return false;
}