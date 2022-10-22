#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
	if (s == "") return 0;
	if (s[0] == '0' && s.size() > 1) return 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') continue;
		return 0;
	}
	return 1;
}

int main () {
	string s; cin >> s;
	s += ",";
	int now = 0;
	string a = "\"", b = "\"";
	while (now < s.size()) {
		string t;
		while (now < s.size() && s[now] != ',' && s[now] != ';') t.push_back(s[now]), now++;
		now++;
		if (check(t)) {
			a += t + ",";
		} else {
			b += t + ",";
		}
	}
	a.pop_back(), b.pop_back();
	a += "\"", b += "\"";
	if (a == "\"") a = "-";
	if (b == "\"") b = "-";
	cout << a << endl << b << endl;
	return 0;
}