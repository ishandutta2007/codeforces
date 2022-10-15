#include <iostream>

using namespace std;

int main() {
	int o = 0, i = 0;
	string s; cin >> s;
	for (char c: s) {
		if (c == 'o') {
			o++;
		} else {
			i++;
		}
	}
	if (o == 0 || i % o == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}