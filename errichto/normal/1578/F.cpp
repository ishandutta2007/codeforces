// Check if a binary string contains 7 equal characters in a row.

#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.length();
	int k = 7;
	for(int i = 0; i <= n - k; i++) {
		int counter = 0;
		for(int j = i; j <= i+k-1; j++) {
			if(s[i] == s[j]) {
				counter++;
			}
		}
		if(counter == k) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}