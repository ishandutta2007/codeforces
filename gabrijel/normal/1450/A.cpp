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
		int cnt = 0;
		REP(i, n) {
			if(s[i] == 't') cnt++;
			else cout << s[i];
		}
		REP(i, cnt) {
			cout << "t";
		}
		cout << endl;
	}
	return 0;
}