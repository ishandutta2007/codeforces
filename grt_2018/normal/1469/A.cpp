#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> s;
		if(s[0] == ')' || ((int)s.size() & 1) || s.back() == '(') {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
		
}