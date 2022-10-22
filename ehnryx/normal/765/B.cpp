#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int current = 'a'-1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > current) {
			if (s[i] == current + 1)
				current++;
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}