#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s[s.size() - 1] == 'o')
			cout << "FILIPINO";
		if (s[s.size() - 1] == 'u')
			cout << "JAPANESE";
		if (s[s.size() - 1] == 'a')
			cout << "KOREAN";
		cout << endl;
	}
	return 0;
}