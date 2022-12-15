#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << s;
	for(int i = s.length() - 1; i >= 0; i--) {
		cout << s[i];
	}
	
	return 0;
}