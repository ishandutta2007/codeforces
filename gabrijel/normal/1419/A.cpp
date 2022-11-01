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
		bool par = 0, nep = 0;
		REP(i, n) {
			if(i % 2 == 1 && (s[i] - '0') % 2 == 0) par = 1;
			else if(i % 2 == 0 && (s[i] - '0') % 2 == 1) nep = 1;
		}
		if(n % 2) {
			if(nep) cout << "1\n";
			else cout << "2\n";
		}
		else {
			if(par) cout << "2\n";
			else cout << "1\n";
		}
	}
	return 0;
}