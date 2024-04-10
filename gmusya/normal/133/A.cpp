#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool tf = false;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
			tf = true;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}