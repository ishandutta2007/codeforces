#include <iostream>
#include <string> 

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'r')
			cout << 1 + i << '\n';
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == 'l')
			cout << 1 + i << '\n';
	}
	return 0;
}