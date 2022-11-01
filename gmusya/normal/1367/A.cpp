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
		cout << s[0];
		for (int i = 1; i < s.size(); i += 2)
			cout << s[i];
		cout << '\n';
	}
	return 0;
}