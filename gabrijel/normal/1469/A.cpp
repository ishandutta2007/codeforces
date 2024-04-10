#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		string s;
		cin >> s;
		if(s.size() % 2) {
			cout << "NO\n";
			continue;
		}
		if(s[0] == ')' || s.back() == '(') {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}