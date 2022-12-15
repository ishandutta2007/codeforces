#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5 + 5;


bool check(string &s) {	
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a' && (b || c)) return false;
		if(s[i] == 'a') a++;
		if(s[i] == 'b') b++;
		if(s[i] == 'b' && c) return false;
		if(s[i] == 'c') c++;
	}
	if(!a || !b || !c) return false;
	return c == a || c == b;
}
int main() {
	string s;
	cin >> s;
	if(check(s)) {
		cout << "YES\n";
	} else cout << "NO\n";
	return 0;
}