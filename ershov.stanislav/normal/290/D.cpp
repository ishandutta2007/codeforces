#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a;
	cin >> a;
	for (int i=0; i<(int)s.length(); i++) {
		s[i]=tolower(s[i]);
		if (s[i]-'a'<a) s[i]=toupper(s[i]);
	}
	cout << s;
	return 0;
}