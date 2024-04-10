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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool pal = 1;
		REP(i, n / 2) {
			if(s[i] != s[n - i - 1]) {
				pal = 0;
				break;
			}
		}
		if(pal || !k) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}