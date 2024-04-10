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
		bool idel = 1, ided = 1;
		REP(i, n) {
			if(s[i] == '>') idel = 0;
			if(s[i] == '<') ided = 0;
		}
		if(idel || ided) {
			cout << n << "\n";
			continue;
		}
		int rj = 0;
		if(s[n - 1] == '-' || s[0] == '-') rj++;
		for(int i = 1; i < n; i++) {
			if(s[i - 1] == '-' || s[i] == '-') rj++;
		}
		cout << rj << "\n";
	}
	return 0;
}