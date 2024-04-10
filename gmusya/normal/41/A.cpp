#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size()) {
		cout << "NO";
		return 0;
	}
	bool tf = true;
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] != s2[s2.size() - 1 - i])
			tf = false;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}