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
		int rj = 0, x = 0;
		while(x < n) {
			rj++;
			x += rj;
		}
		if(x == n || x - n > 1) cout << rj << "\n";
		else cout << rj + 1 << "\n";
	}
	return 0;
}