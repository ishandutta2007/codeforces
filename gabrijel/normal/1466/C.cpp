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
		int n = (int)s.size(), rj = 0;
		REP(i, n) {
			if(i == 0) continue;
			if(s[i] == s[i - 1]) {
				rj++;
				s[i] = '#';
			}
			else if(i == 1) continue;
			else if(s[i] == s[i - 2]) {
				rj++;
				s[i] = '#';
			}
		}
		cout << rj << "\n";
	}
	return 0;
}