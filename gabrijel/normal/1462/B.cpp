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
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(s == "2020") {
			cout << "YES\n";
			continue;
		}
		int pref, suf;
		if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') pref = 4;
		else if(s[0] == '2' && s[1] == '0' && s[2] == '2') pref = 3;
		else if(s[0] == '2' && s[1] == '0') pref = 2;
		else if (s[0] == '2') pref = 1;
		else pref = 0;
		if(s[n - 1] == '0' && s[n - 2] == '2' && s[n - 3] == '0' && s[n - 4] == '2') suf = 4;
		else if(s[n - 1] == '0' && s[n - 2] == '2' && s[n - 3] == '0') suf = 3;
		else if(s[n - 1] == '0' && s[n - 2] == '2') suf = 2;
		else if(s[n - 1] == '0') suf = 1;
		else suf = 0;
		if(pref + suf >= 4) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}