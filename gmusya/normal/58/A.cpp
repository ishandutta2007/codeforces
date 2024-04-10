#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	string q = "hello";
	int ukq = 0;
	bool tf = false;
	for (int i = 0; i < s.size(); i++) {
		if (ukq == 5) {
			tf = true;
			break;
		}
		if (s[i] == q[ukq])
			ukq++;
	}
	if (ukq == 5)
		tf = true;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}