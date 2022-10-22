#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char,char> m;
	string s, t, str;
	cin >> s >> t >> str;
	for (int i = 0; i < 26; i++) {
		m.insert(pair<char,char>(s[i], t[i]));
		m.insert(pair<char,char>(toupper(s[i]), toupper(t[i])));
	}
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i]))
			cout << m[str[i]];
		else 
			cout << str[i];
	}
	cout << endl;
	return 0;
}