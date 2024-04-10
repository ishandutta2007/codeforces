#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	int cnt1 = 0, cnt2 = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			cnt1++;
		else
			cnt2++;
	}
	if (cnt1 > cnt2) {
		for (int i = 0; i < s.size(); i++)
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] += 'A' - 'a';
	}
	else
		for (int i = 0; i < s.size(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 'a' - 'A';
	cout << s;
	return 0;
}