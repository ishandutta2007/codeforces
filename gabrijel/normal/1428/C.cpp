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
		vector <char> stek;
		int rj = 0;
		REP(i, (int)s.size()) {
			if(s[i] == 'A') {
				stek.push_back('A');
			}
			else {
				if(stek.size()) {
					rj += 2;
					stek.pop_back();
				}
				else stek.push_back('B');
			}
		}
		cout << (int)s.size() - rj << "\n";
	}
	return 0;
}