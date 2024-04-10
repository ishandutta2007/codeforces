#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int main() {
	string s;
	cin >> s;
	int total = 0, zero = 0;
	for(int i = s.length() - 1; i >= 0; i--) {
		if(s[i] == '0') {
		    zero++;
		    continue;
		}
		total++;
		int digitos = 1 + zero;
		zero = 0;
		if(i < digitos || i == digitos && s[0] < s[i]) {
		    break;
		}
	}
	cout << total << endl;
	return 0;
}