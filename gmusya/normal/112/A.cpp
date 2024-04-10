#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] += 'a' - 'A';
		if (s2[i] >= 'A' && s2[i] <= 'Z')
			s2[i] += 'a' - 'A';
	}
	if (s1 == s2)
		cout << "0";
	if (s1 < s2)
		cout << "-1";
	if (s1 > s2)
		cout << "1";
	return 0;
}