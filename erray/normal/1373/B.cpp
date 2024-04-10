#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int ct = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != s[i - 1]) {
			  ++ct;
			  s.erase(s.begin() + i - 1);
			  s.erase(s.begin() + i - 1);
			  i = 0;
			}
		}
		cout << (ct & 1 ? "DA" : "NET") << '\n';
	}
}