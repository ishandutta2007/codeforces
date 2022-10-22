#include <bits/stdc++.h>
using namespace std;
int main () {
	string s; getline(cin, s);
	string ans;
	for (int i = 0; i < s.size(); ) {
		if (s[i] == '.') {
			if (ans.size() && ans[ans.size() - 1] != ' ') ans.push_back(' ');
			ans += "...";
			i += 3;
			while (i < s.size() && s[i] == ' ') i++;
		} else if (s[i] == ',') {
			while (ans[ans.size() - 1] == ' ') ans.pop_back();
			if (ans[ans.size() - 1] == ',') ans.push_back(' ');
			ans += ", ";
			i++;
		} else if (s[i] == ' ') {
			if (ans[ans.size() - 1] != ' ') ans.push_back(' ');
			i++;
		} else {
			ans.push_back(s[i]);
			i++;
		}
	}
	while (ans[ans.size() - 1] == ' ') ans.pop_back();
	cout << ans << endl;
	return 0;
}