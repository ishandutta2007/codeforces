#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) {
		for(int j = 1; i + 4 * j < n; j++) {
			if(s[i] == '*' && s[i + j] == '*' && s[i + 2 * j] == '*' && s[i + 3 * j] == '*' && s[i + 4 * j] == '*') {
				cout << "yes\n";
				return 0;
			}
		}
	}
	cout << "no\n";
	return 0;
}